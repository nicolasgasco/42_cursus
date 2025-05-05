from constants import SnakeDirection, BoardBlock


class Game:
    def __init__(self, raw_map: list):
        self.__forbidden_blocks = [
            BoardBlock.WALL.value,
            BoardBlock.BODY.value,
        ]
        self.__game_over = False
        self.__has_moved = False
        self.__head_pos: tuple | None = None
        self.__raw_map = raw_map

    @property
    def has_moved(self) -> bool:
        return self.__has_moved

    @property
    def game_over(self) -> bool:
        return self.__game_over

    def move_snake(self, direction: str) -> None:
        self.__move_head(direction)

        if self.__has_moved:
            self.__move_tail()

    def __move_head(self, direction: str) -> None:
        head_y, head_x = (
            self.__head_pos if self.__head_pos else self.__find_head_pos()
        )
        assert (
            head_x is not None and head_y is not None
        ), "Head position not found."

        new_head_y, new_head_x = self.__get_new_head_pos(
            head_y, head_x, direction
        )

        is_forbidden_block = (
            self.__raw_map[new_head_y][new_head_x] in self.__forbidden_blocks
        )

        if is_forbidden_block:
            self.__game_over = True
            self.__has_moved = False
        elif not is_forbidden_block:
            self.__raw_map[new_head_y][new_head_x] = BoardBlock.HEAD.value
            self.__has_moved = True
            self.__game_over = False

        if self.__has_moved:
            self.__raw_map[head_y][head_x] = BoardBlock.BODY.value

    def __move_tail(self) -> None:
        tail_y, tail_x = self.__find_tail()

        if tail_x is None or tail_y is None:
            raise ValueError("Snake tail not found in the map.")

        self.__raw_map[tail_y][tail_x] = BoardBlock.EMPTY.value

    def __find_head_pos(self) -> tuple:
        for y, row in enumerate(self.__raw_map):
            for x, block in enumerate(row):
                if block == BoardBlock.HEAD.value:
                    return (y, x)
        return (None, None)

    def __get_new_head_pos(
        self, head_y: int, head_x: int, direction: str
    ) -> tuple:
        if direction == SnakeDirection.UP.value:
            return (head_y - 1, head_x)
        elif direction == SnakeDirection.DOWN.value:
            return (head_y + 1, head_x)
        elif direction == SnakeDirection.LEFT.value:
            return (head_y, head_x - 1)
        elif direction == SnakeDirection.RIGHT.value:
            return (head_y, head_x + 1)
        else:
            raise ValueError(f"Invalid direction: {direction}")

    def __find_tail(self) -> tuple:
        head_pos = (
            self.__head_pos if self.__head_pos else self.__find_head_pos()
        )
        assert head_pos is not None, "Head position not found."

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
