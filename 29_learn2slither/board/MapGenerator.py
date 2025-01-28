import json as json
import numpy as np
import os as os
import time as time

BOARD_LEGEND = {
    "EMPTY": "⬛",
    "GREEN_APPLE": "🍏",
    "RED_APPLE": "🍎",
    "HEAD": "🐸",
    "BODY": "🟩",
    "WALL": "⬜",
}

NUM_RED_APPLES = 1
NUM_GREEN_APPLES = 2
SNAKE_LENGTH = 3


class MapGenerator:
    def __init__(self) -> None:
        settings = self.__parse_settings()

        self.__width = settings["width"]
        self.__height = settings["height"]

        map_size = (self.__height, self.__width)
        self.__map = np.full(map_size, BOARD_LEGEND["EMPTY"])

    def __parse_settings(self) -> dict:
        """
        Parses the map settings from a JSON file.
        This method retrieves the directory path for settings
        from the environment variable
        "SETTINGS_DIR_PATH", constructs the full path to the "map.json" file,
        and reads the settings from this file.
        Returns:
            dict: A dictionary containing the map settings.
        """

        settings_dir_path = os.environ.get("SETTINGS_DIR_PATH")
        map_settings_path = os.path.join(settings_dir_path, "map.json")
        with open(map_settings_path, "r") as file:
            settings = json.load(file)

        return settings

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
        def fill_walls(map: list) -> list:
            """
            Fills the borders of the given map with walls.
            This function takes a 2D list representing a map and fills
            the top, bottom, left, and right borders with wall elements
            as defined in BOARD_LEGEND.
            Args:
                map (list): A 2D list representing the map
                to be filled with walls.
            Returns:
                list: The modified map with walls on its borders.
            """

            filled_map = map

            # Top wall
            filled_map[0, :] = BOARD_LEGEND["WALL"]
            # Bottom wall
            filled_map[-1, :] = BOARD_LEGEND["WALL"]
            # Left wall
            filled_map[:, 0] = BOARD_LEGEND["WALL"]
            # Right wall
            filled_map[:, -1] = BOARD_LEGEND["WALL"]

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
                placed_apple = False

                while not placed_apple:
                    rand_x = np.random.randint(1, self.__width - 1)
                    rand_y = np.random.randint(1, self.__height - 1)

                    if filled_map[rand_y, rand_x] != BOARD_LEGEND["EMPTY"]:
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

            placed_head = False

            while not placed_head:
                head_x = np.random.randint(1, self.__width - 1 - SNAKE_LENGTH)
                head_y = np.random.randint(1, self.__height - 1)

                is_head_empty = (
                    filled_map[head_y, head_x] == BOARD_LEGEND["EMPTY"]
                )

                is_head_left_empty = (
                    filled_map[head_y, head_x - 1] == BOARD_LEGEND["EMPTY"]
                )
                is_head_right_empty = (
                    filled_map[head_y, head_x + 1] == BOARD_LEGEND["EMPTY"]
                )
                is_head_right_right_empty = (
                    filled_map[head_y, head_x + 2] == BOARD_LEGEND["EMPTY"]
                )
                if (
                    not is_head_empty
                    or not is_head_left_empty
                    or not is_head_right_empty
                    or not is_head_right_right_empty
                ):
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
            filled_map, BOARD_LEGEND["RED_APPLE"], NUM_RED_APPLES
        )
        filled_map = fill_apple(
            filled_map, BOARD_LEGEND["GREEN_APPLE"], NUM_GREEN_APPLES
        )
        filled_map = fill_snake(
            filled_map,
            BOARD_LEGEND["HEAD"],
            BOARD_LEGEND["BODY"],
            SNAKE_LENGTH,
        )
        self.__map = filled_map

    def save_map_to_file(self) -> str:
        """
        Saves the current map to a file with a timestamped filename.
        The filename is generated using the current timestamp,
        map width, and height.
        The directory to save the file is retrieved
        from the environment variable "MAPS_DIR_PATH".
        Returns:
            str: The full path of the saved map file.
        """

        timestamp = time.strftime("%Y-%m-%d")
        file_name = timestamp
        file_name += f"_W{self.__width}_H{self.__height}"
        file_name += "_map"

        maps_dir_path = os.environ.get("MAPS_DIR_PATH")
        file_name = os.path.join(maps_dir_path, file_name)

        with open(file_name, "w") as file:
            for row in self.__map:
                file.write("".join(row) + "\n")

        return file_name
