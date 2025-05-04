from Block import Block
from constants import MAPS_DIR_PATH
from settings_parser import SettingsParser
from os import path


class Board:
    def __init__(self):
        self.__rows = self.__parse_board_from_file()

    def __parse_board_from_file(self) -> list:
        settings = SettingsParser().settings
        map_file_name = settings["file_name"]
        assert map_file_name, "Map file name not found in settings."

        map_file_path = path.join("..", "..", MAPS_DIR_PATH, map_file_name)
        print(f"Map file path: {map_file_path}")
        with open(map_file_path, "r") as file:
            map_rows = file.readlines()
            map_rows = [row.strip() for row in map_rows]

        return map_rows

    def render(self):
        for y, row in enumerate(self.__rows):
            for x, block in enumerate(row):
                gui_block = Block({"block": block})
                gui_block.grid(row=x, column=y)
