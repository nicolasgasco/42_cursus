import os as os
import pickle as pkl
import time as time
from collections import deque

import numpy as np

from constants import (
    DATA_DIR_PATH,
    DATA_SNAKE_FILE_NAME,
    MAPS_DIR_PATH,
    BoardBlockSymbol,
)
from settings_parser import SettingsParser


class MapGenerator:
    def __init__(self) -> None:
        settings = SettingsParser("map").settings

        self.__green_apples = settings["green_apples"]
        self.__height = settings["height"]
        self.__randomized = settings["randomized"]
        self.__red_apples = settings["red_apples"]
        self.__snake_length = settings["snake_length"]
        self.__width = settings["width"]

        # TODO add validation of settings

        map_size = (self.__height, self.__width)
        self.__map = np.full(map_size, BoardBlockSymbol.EMPTY.value)

        self.__body_pos = deque()
        self.__head_pos = (None, None)

        if not self.__randomized:
            np.random.seed(0)

    def __str__(self) -> str:
        output = "MapGenerator("
        output += f"width={self.__width}, "
        output += f"height={self.__height}"
        output += ")"
        return output

    @property
    def map(self) -> np.ndarray:
        return self.__map

    def generate_map(self) -> None:
        filled_map = self.__fill_walls(self.__map)

        filled_map = self.__fill_snake(filled_map)

        filled_map = self.__fill_apple(
            filled_map, BoardBlockSymbol.RED_APPLE.value, self.__red_apples
        )

        filled_map = self.__fill_apple(
            filled_map, BoardBlockSymbol.GREEN_APPLE.value, self.__green_apples
        )

        self.__map = filled_map

        self.__dump_snake_data()

    def __fill_walls(self, map: list) -> list:
        filled_map = map

        filled_map[0, :] = BoardBlockSymbol.WALL.value  # Top wall
        filled_map[-1, :] = BoardBlockSymbol.WALL.value  # Bottom wall
        filled_map[:, 0] = BoardBlockSymbol.WALL.value  # Left wall
        filled_map[:, -1] = BoardBlockSymbol.WALL.value  # Right wall

        return filled_map

    def __fill_apple(self, map: list, apple: str, num_apples: int) -> list:
        filled_map = map

        apple_to_place = num_apples
        patience = 100
        while apple_to_place > 0:
            if patience <= 0:
                raise Exception("Unable to place apple on the map.")

            rand_x = np.random.randint(1, self.__width - 1)
            rand_y = np.random.randint(1, self.__height - 1)

            if filled_map[rand_y, rand_x] != BoardBlockSymbol.EMPTY.value:
                patience -= 1
                continue

            filled_map[rand_y, rand_x] = apple
            apple_to_place -= 1

        return filled_map

    def __fill_snake(self, map: list) -> list:

        filled_map = map

        placed_whole = False
        patience_whole = 100
        while not placed_whole:
            if patience_whole <= 0:
                raise Exception("Unable to place whole snake on the map.")

            min_dist_to_wall = 3
            head_x = np.random.randint(
                min_dist_to_wall, self.__width - 1 - min_dist_to_wall
            )
            head_y = np.random.randint(
                min_dist_to_wall, self.__height - 1 - min_dist_to_wall
            )

            if filled_map[head_y, head_x] != BoardBlockSymbol.EMPTY.value:
                continue

            self.__head_pos = (head_y, head_x)

            prev_x, prev_y = head_x, head_y
            new_x, new_y = head_x, head_y
            for _ in range(1, self.__snake_length):
                # Right
                if (
                    prev_x + 1 <= self.__width
                    and filled_map[prev_y, prev_x + 1]
                    == BoardBlockSymbol.EMPTY.value
                ):
                    new_x = prev_x + 1
                # Down
                elif (
                    prev_y + 1 <= self.__height
                    and filled_map[prev_y + 1, prev_x]
                    == BoardBlockSymbol.EMPTY.value
                ):
                    new_y = prev_y + 1
                # Left
                elif (
                    prev_x - 1 >= 1
                    and filled_map[prev_y, prev_x - 1]
                    == BoardBlockSymbol.EMPTY.value
                ):
                    new_x = prev_x - 1
                # Up
                elif (
                    prev_y - 1 >= 1
                    and filled_map[prev_y - 1, prev_x]
                    == BoardBlockSymbol.EMPTY.value
                ):
                    new_y = prev_y - 1
                else:
                    patience_whole -= 1
                    continue

                filled_map[new_y, new_x] = BoardBlockSymbol.BODY.value
                self.__body_pos.append((new_y, new_x))

                prev_x = new_x
                prev_y = new_y

            filled_map[head_y, head_x] = BoardBlockSymbol.HEAD.value
            break

        return filled_map

    def save_map_to_file(self) -> str:
        timestamp = time.strftime("%Y-%m-%d")
        file_name = timestamp
        file_name += f"_W{self.__width}_H{self.__height}"
        file_name += "_map"

        file_name = os.path.join("..", MAPS_DIR_PATH, file_name)

        try:
            with open(file_name, "w") as file:
                for row in self.__map:
                    file.write("".join(row) + "\n")
        except Exception as e:
            raise e

        return file_name

    def __dump_snake_data(self) -> str:
        path = os.path.join(DATA_DIR_PATH, DATA_SNAKE_FILE_NAME)

        if not os.path.exists(os.path.dirname(path)):
            os.makedirs(os.path.dirname(path))

        with open(path, "wb") as file:
            pkl.dump(
                {
                    "head_pos": self.__head_pos,
                    "body_pos": self.__body_pos,
                },
                file,
            )
