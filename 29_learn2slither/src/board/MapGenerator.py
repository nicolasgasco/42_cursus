from dotenv import load_dotenv
import json as json
import numpy as np
import os as os
import time as time

from constants.board import BoardBlock
from settings_parser import SettingsParser


class MapGenerator:
    def __init__(self) -> None:
        load_dotenv()

        settings = SettingsParser().settings

        self.__green_apples = settings["green_apples"]
        self.__height = settings["height"]
        self.__red_apples = settings["red_apples"]
        self.__snake_length = settings["snake_length"]
        self.__width = settings["width"]

        # TODO add validation of settings

        map_size = (self.__height, self.__width)
        self.__map = np.full(map_size, BoardBlock.EMPTY.value)

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
        # TODO move this to separate file
        def fill_walls(map: list) -> list:
            """
            Fills the borders of the given map with walls.
            Args:
                map (list): A 2D list representing the map
                to be filled with walls.
            Returns:
                list: The modified map with walls on its borders.
            """

            filled_map = map

            # Top wall
            filled_map[0, :] = BoardBlock.WALL.value
            # Bottom wall
            filled_map[-1, :] = BoardBlock.WALL.value
            # Left wall
            filled_map[:, 0] = BoardBlock.WALL.value
            # Right wall
            filled_map[:, -1] = BoardBlock.WALL.value

            return filled_map

        def fill_apple(map: list, apple: str, counter: int = 1) -> list:
            """
            Fills the map with a specified number of apples
            at random empty positions.
            Args:
                map (list): The game board represented as a 2D list.
                apple (str): The character or symbol representing an apple.
                counter (int, optional): The number of apples to place
                on the map. Defaults to 1.
            Returns:
                list: The updated game board with apples placed.
            """

            filled_map = map

            for _ in range(counter):
                patience = 100
                placed_apple = False

                while not placed_apple:
                    if patience <= 0:
                        raise Exception("Unable to place apple on the map.")

                    rand_x = np.random.randint(1, self.__width - 1)
                    rand_y = np.random.randint(1, self.__height - 1)

                    if filled_map[rand_y, rand_x] != BoardBlock.EMPTY.value:
                        patience -= 1
                        continue

                    filled_map[rand_y, rand_x] = apple
                    placed_apple = True

            return filled_map

        def fill_snake(map: list, head: str, body: str, length: str) -> list:
            """
            Fills the map with a snake of specified length, head,
            and body characters.
            Args:
                map (list): The game board represented as a 2D list.
                head (str): The character representing the snake's head.
                body (str): The character representing the snake's body.
                length (int): The length of the snake.
            Returns:
                list: The updated game board with the snake placed on it.
            """

            filled_map = map

            patience = 100
            placed_head = False

            while not placed_head:
                if patience <= 0:
                    raise Exception("Unable to place snake on the map.")

                head_x = np.random.randint(1, self.__width - 1 - self.__snake_length)
                head_y = np.random.randint(1, self.__height - 1)

                is_head_empty = filled_map[head_y, head_x] == BoardBlock.EMPTY.value

                is_head_left_empty = (
                    filled_map[head_y, head_x - 1] == BoardBlock.EMPTY.value
                )

                is_head_right_empty = (
                    filled_map[head_y, head_x + 1] == BoardBlock.EMPTY.value
                )

                is_head_right_right_empty = (
                    filled_map[head_y, head_x + 2] == BoardBlock.EMPTY.value
                )
                if (
                    not is_head_empty
                    or not is_head_left_empty
                    or not is_head_right_empty
                    or not is_head_right_right_empty
                ):
                    patience -= 1
                    continue

                filled_map[head_y, head_x] = head
                placed_head = True

            for i in range(1, length):
                new_x = head_x + i
                new_y = head_y

                filled_map[new_y, new_x] = body

            return filled_map

        filled_map = fill_walls(self.__map)
        filled_map = fill_apple(
            filled_map, BoardBlock.RED_APPLE.value, self.__red_apples
        )
        filled_map = fill_apple(
            filled_map, BoardBlock.GREEN_APPLE.value, self.__green_apples
        )
        filled_map = fill_snake(
            filled_map,
            BoardBlock.HEAD.value,
            BoardBlock.BODY.value,
            self.__snake_length,
        )
        self.__map = filled_map

    def save_map_to_file(self) -> str:
        """
        Saves the current map to a file with a timestamped filename.
        Returns:
            str: The full path of the saved map file.
        """

        timestamp = time.strftime("%Y-%m-%d")
        file_name = timestamp
        file_name += f"_W{self.__width}_H{self.__height}"
        file_name += "_map"

        maps_dir_path = os.environ.get("MAPS_DIR_PATH")
        file_name = os.path.join("..", "..", maps_dir_path, file_name)

        try:
            with open(file_name, "w") as file:
                for row in self.__map:
                    file.write("".join(row) + "\n")
        except Exception as e:
            raise e

        return file_name
