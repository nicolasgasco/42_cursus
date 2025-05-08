import os as os
import pickle as pkl
from collections import deque

from constants import DEFAULT_SNAKE_DIRECTION, BoardBlockSymbol, SnakeDirection
from settings_parser import SettingsParser

from .utils import is_opposite_direction


class Game:
    def __init__(self, raw_map: list):
        self.__raw_map = raw_map

        self.__direction = DEFAULT_SNAKE_DIRECTION

        self.__head_pos: tuple = (None, None)
        self.__body_pos: deque | None = None
        self.__load_snake_pos()

        self.__forbidden_blocks = [
            BoardBlockSymbol.WALL.value,
            BoardBlockSymbol.BODY.value,
        ]

        settings = SettingsParser().settings

        self.__apples_red = 0
        self.__apples_green = 0
        self.__ate_green_apple = False
        self.__ate_red_apple = False
        self.__game_over = False
        self.__has_moved = False
        self.__length = settings["snake_length"]
        self.__moves = 0

    @property
    def has_moved(self) -> bool:
        return self.__has_moved

    @property
    def game_over(self) -> bool:
        return self.__game_over

    @property
    def moves(self) -> int:
        return self.__moves

    @property
    def length(self) -> int:
        return self.__length

    @property
    def apples_green(self) -> int:
        return self.__apples_green

    @property
    def apples_red(self) -> int:
        return self.__apples_red

    def __load_snake_pos(self) -> tuple:
        path = os.path.join("data", "snake_pos.pkl")
        with open(path, "rb") as f:
            snake_pos = pkl.load(f)

        self.__head_pos = snake_pos["head_pos"]
        self.__body_pos = deque(snake_pos["body_pos"])

    def move_snake(self, direction: str) -> None:
        self.__ate_green_apple = False
        self.__ate_red_apple = False
        self.__game_over = False
        self.__has_moved = False

        if is_opposite_direction(direction, self.__direction):
            return

        self.__move_head(direction)

        if self.__has_moved:
            self.__move_tail()
            self.__moves += 1

        self.__direction = direction

    def __move_head(self, direction: str) -> None:
        head_y, head_x = self.__head_pos

        new_head_y, new_head_x = self.__get_new_head_pos(
            head_y, head_x, direction
        )

        new_block = self.__raw_map[new_head_y][new_head_x]

        if new_block in self.__forbidden_blocks:
            self.__game_over = True
            return

        self.__has_moved = True
        self.__raw_map[new_head_y][new_head_x] = BoardBlockSymbol.HEAD.value
        self.__head_pos = (new_head_y, new_head_x)

        self.__raw_map[head_y][head_x] = BoardBlockSymbol.BODY.value
        self.__body_pos.appendleft((head_y, head_x))

        if new_block == BoardBlockSymbol.GREEN_APPLE.value:
            self.__length += 1
            self.__ate_green_apple = True
            self.__apples_green += 1
        elif new_block == BoardBlockSymbol.RED_APPLE.value:
            self.__length -= 1
            self.__ate_red_apple = True
            self.__apples_red += 1

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

    def __move_tail(self) -> None:
        blocks_to_remove = 2 if self.__ate_red_apple else 1

        for _ in range(blocks_to_remove):
            tail_y, tail_x = self.__body_pos[-1]

            if not self.__ate_green_apple:
                self.__raw_map[tail_y][tail_x] = BoardBlockSymbol.EMPTY.value
                self.__body_pos.pop()
