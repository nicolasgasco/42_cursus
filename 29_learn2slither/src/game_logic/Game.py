import os as os
import pickle as pkl
from collections import deque

import numpy as np

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
        self.__has_won = False
        self.__has_moved = False

        self.__length = settings["snake_length"]
        self.__moves = 0
        self.__win_length = settings["victory_length"]

        self.__blocks_to_update = []

    @property
    def has_moved(self) -> bool:
        return self.__has_moved

    @property
    def game_over(self) -> bool:
        return self.__game_over

    @property
    def has_won(self) -> bool:
        return self.__has_won

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

    @property
    def blocks_to_update(self) -> list:
        return self.__blocks_to_update

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
        self.__blocks_to_update = []

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
        self.__set_map_block(
            new_head_y, new_head_x, BoardBlockSymbol.HEAD.value
        )
        self.__head_pos = (new_head_y, new_head_x)

        block_to_place = (
            BoardBlockSymbol.BODY.value
            if self.__length > 1
            else BoardBlockSymbol.EMPTY.value
        )
        self.__set_map_block(head_y, head_x, block_to_place)
        self.__body_pos.appendleft((head_y, head_x))

        if new_block == BoardBlockSymbol.GREEN_APPLE.value:
            self.__ate_green_apple = True
            self.__apples_green += 1
            self.__place_apple(BoardBlockSymbol.GREEN_APPLE.value)

            self.__length += 1
            if self.__length >= self.__win_length:
                self.__has_won = True
                return
        elif new_block == BoardBlockSymbol.RED_APPLE.value:
            self.__ate_red_apple = True
            self.__apples_red += 1
            self.__place_apple(BoardBlockSymbol.RED_APPLE.value)

            self.__length -= 1
            if self.__length <= 0:
                self.__game_over = True

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
        if self.__length <= 0:
            return

        blocks_to_remove = 2 if self.__ate_red_apple else 1

        for _ in range(blocks_to_remove):
            tail_y, tail_x = self.__body_pos[-1]

            if not self.__ate_green_apple:
                self.__set_map_block(
                    tail_y, tail_x, BoardBlockSymbol.EMPTY.value
                )
                self.__body_pos.pop()

    def __place_apple(self, apple: str) -> None:
        apples_to_place = 1
        patience = 100

        while apples_to_place > 0:
            if patience <= 0:
                raise Exception("Unable to place apple on the map.")

            rand_x = np.random.randint(1, len(self.__raw_map[0]) - 1)
            rand_y = np.random.randint(1, len(self.__raw_map) - 1)

            if self.__raw_map[rand_y][rand_x] != BoardBlockSymbol.EMPTY.value:
                patience -= 1
                continue

            self.__set_map_block(rand_y, rand_x, apple)
            self.__raw_map[rand_y][rand_x] = apple
            apples_to_place -= 1

    def __set_map_block(self, y: int, x: int, block: str) -> None:
        self.__raw_map[y][x] = block
        self.__blocks_to_update.append(
            {
                "block": block,
                "pos": (y, x),
            }
        )
