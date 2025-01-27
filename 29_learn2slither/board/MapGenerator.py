import json as json
import numpy as np
import os as os
import time as time

BOARD_LEGEND = {
    "EMPTY": "⬛",
    "GREEN_APPLE": "🍏",
    "RED_APPLE": "🍎",
    "WALL": "⬜",
}


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

        self.__map = fill_walls(self.__map)
        self.__map = fill_apple(self.__map, BOARD_LEGEND["RED_APPLE"], 1)
        self.__map = fill_apple(self.__map, BOARD_LEGEND["GREEN_APPLE"], 2)

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

        timestamp = time.strftime("%Y-%m-%d_%H-%M-%S")
        file_name = timestamp
        file_name += f"_W{self.__width}_H{self.__height}"
        file_name += "_map"

        maps_dir_path = os.environ.get("MAPS_DIR_PATH")
        file_name = os.path.join(maps_dir_path, file_name)

        with open(file_name, "w") as file:
            for row in self.__map:
                file.write("".join(row) + "\n")

        return file_name
