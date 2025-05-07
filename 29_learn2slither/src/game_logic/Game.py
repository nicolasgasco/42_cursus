from constants import BoardBlockSymbol, DEFAULT_SNAKE_DIRECTION, SnakeDirection


class Game:
    def __init__(self, raw_map: list):
        self.__raw_map = raw_map

        self.__direction = DEFAULT_SNAKE_DIRECTION
        self.__head_pos: tuple | None = None

        self.__forbidden_blocks = [
            BoardBlockSymbol.WALL.value,
            BoardBlockSymbol.BODY.value,
        ]

        self.__ate_green_apple = False
        self.__ate_red_apple = False
        self.__game_over = False
        self.__has_moved = False

    @property
    def has_moved(self) -> bool:
        return self.__has_moved

    @property
    def game_over(self) -> bool:
        return self.__game_over

    def move_snake(self, direction: str) -> None:
        self.__ate_green_apple = False
        self.__ate_red_apple = False
        self.__game_over = False
        self.__has_moved = False

        self.__move_head(direction)

        if self.__has_moved:
            self.__move_tail()

        self.__direction = direction

    def __is_opposite_direction(
        self, direction: str, prev_direction: str
    ) -> bool:
        return (
            (
                direction == SnakeDirection.UP.value
                and prev_direction == SnakeDirection.DOWN.value
            )
            or (
                direction == SnakeDirection.DOWN.value
                and prev_direction == SnakeDirection.UP.value
            )
            or (
                direction == SnakeDirection.LEFT.value
                and prev_direction == SnakeDirection.RIGHT.value
            )
            or (
                direction == SnakeDirection.RIGHT.value
                and prev_direction == SnakeDirection.LEFT.value
            )
        )

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

        new_block = self.__raw_map[new_head_y][new_head_x]

        if new_block in self.__forbidden_blocks:
            if not self.__is_opposite_direction(direction, self.__direction):
                self.__game_over = True
            return

        self.__has_moved = True
        if new_block == BoardBlockSymbol.GREEN_APPLE.value:
            self.__ate_green_apple = True
        elif new_block == BoardBlockSymbol.RED_APPLE.value:
            self.__ate_red_apple = True

        self.__raw_map[new_head_y][new_head_x] = BoardBlockSymbol.HEAD.value
        self.__raw_map[head_y][head_x] = BoardBlockSymbol.BODY.value

    def __move_tail(self) -> None:
        n_repeat = 2 if self.__ate_red_apple else 1

        for _ in range(n_repeat):
            tail_y, tail_x = self.__find_tail()

            if tail_x is None or tail_y is None:
                raise ValueError("Snake tail not found in the map.")

            if not self.__ate_green_apple:
                self.__raw_map[tail_y][tail_x] = BoardBlockSymbol.EMPTY.value

    def __find_head_pos(self) -> tuple:
        for y, row in enumerate(self.__raw_map):
            for x, block in enumerate(row):
                if block == BoardBlockSymbol.HEAD.value:
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
                == BoardBlockSymbol.BODY.value
                and prev_direction != SnakeDirection.DOWN.value
            ):
                tail_pos = (tail_pos[0] - 1, tail_pos[1])
                prev_direction = SnakeDirection.UP.value
            elif (
                self.__raw_map[tail_pos[0] + 1][tail_pos[1]]
                == BoardBlockSymbol.BODY.value
            ) and prev_direction != SnakeDirection.UP.value:
                tail_pos = (tail_pos[0] + 1, tail_pos[1])
                prev_direction = SnakeDirection.DOWN.value
            elif (
                self.__raw_map[tail_pos[0]][tail_pos[1] - 1]
                == BoardBlockSymbol.BODY.value
            ) and prev_direction != SnakeDirection.RIGHT.value:
                tail_pos = (tail_pos[0], tail_pos[1] - 1)
                prev_direction = SnakeDirection.LEFT.value
            elif (
                self.__raw_map[tail_pos[0]][tail_pos[1] + 1]
                == BoardBlockSymbol.BODY.value
            ) and prev_direction != SnakeDirection.LEFT.value:
                tail_pos = (tail_pos[0], tail_pos[1] + 1)
                prev_direction = SnakeDirection.RIGHT.value
            else:
                found_tail = True
                break

        return tail_pos if found_tail else (None, None)
