from constants import SnakeDirection, BoardBlock


class Game:
    def __init__(self, raw_map: list):
        self.__raw_map = raw_map

    def move_snake(self, direction: str) -> bool:
        has_moved = self.__move_head(direction)

        if has_moved:
            self.__move_tail()
            return True

        return False

    def __move_head(self, direction: str) -> None:
        head_y, head_x = self.__find_head()
        if head_x is None or head_y is None:
            raise ValueError("Snake head not found in the map.")

        has_moved = False

        if direction == SnakeDirection.UP.value:
            new_pos = self.__raw_map[head_y - 1][head_x]
            if new_pos != BoardBlock.BODY.value:
                self.__raw_map[head_y - 1][head_x] = BoardBlock.HEAD.value
                has_moved = True
        elif direction == SnakeDirection.DOWN.value:
            new_pos = self.__raw_map[head_y + 1][head_x]
            if new_pos != BoardBlock.BODY.value:
                self.__raw_map[head_y + 1][head_x] = BoardBlock.HEAD.value
                has_moved = True
        elif direction == SnakeDirection.LEFT.value:
            new_pos = self.__raw_map[head_y][head_x - 1]
            if new_pos != BoardBlock.BODY.value:
                self.__raw_map[head_y][head_x - 1] = BoardBlock.HEAD.value
                has_moved = True
        elif direction == SnakeDirection.RIGHT.value:
            new_pos = self.__raw_map[head_y][head_x + 1]
            if new_pos != BoardBlock.BODY.value:
                self.__raw_map[head_y][head_x + 1] = BoardBlock.HEAD.value
                has_moved = True
        else:
            raise ValueError(f"Invalid direction: {direction}")

        if has_moved:
            self.__raw_map[head_y][head_x] = BoardBlock.BODY.value

        return has_moved

    def __find_head(self) -> tuple:
        for y, row in enumerate(self.__raw_map):
            for x, block in enumerate(row):
                if block == BoardBlock.HEAD.value:
                    return (y, x)
        return (None, None)

    def __move_tail(self) -> None:
        tail_y, tail_x = self.__find_tail()

        if tail_x is None or tail_y is None:
            raise ValueError("Snake tail not found in the map.")

        self.__raw_map[tail_y][tail_x] = BoardBlock.EMPTY.value

    def __find_tail(self) -> tuple:
        head_pos = self.__find_head()
        tail_pos = head_pos

        found_tail = False
        prev_direction = None
        while not found_tail:
            if (
                self.__raw_map[tail_pos[0] - 1][tail_pos[1]]
                == BoardBlock.BODY.value
                and prev_direction != SnakeDirection.DOWN.value
            ):
                tail_pos = (tail_pos[0] - 1, tail_pos[1])
                prev_direction = SnakeDirection.UP.value
            elif (
                self.__raw_map[tail_pos[0] + 1][tail_pos[1]]
                == BoardBlock.BODY.value
            ) and prev_direction != SnakeDirection.UP.value:
                tail_pos = (tail_pos[0] + 1, tail_pos[1])
                prev_direction = SnakeDirection.DOWN.value
            elif (
                self.__raw_map[tail_pos[0]][tail_pos[1] - 1]
                == BoardBlock.BODY.value
            ) and prev_direction != SnakeDirection.RIGHT.value:
                tail_pos = (tail_pos[0], tail_pos[1] - 1)
                prev_direction = SnakeDirection.LEFT.value
            elif (
                self.__raw_map[tail_pos[0]][tail_pos[1] + 1]
                == BoardBlock.BODY.value
            ) and prev_direction != SnakeDirection.LEFT.value:
                tail_pos = (tail_pos[0], tail_pos[1] + 1)
                prev_direction = SnakeDirection.RIGHT.value
            else:
                found_tail = True
                break

        return tail_pos if found_tail else (None, None)
