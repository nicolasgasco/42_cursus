import tkinter as tk
from os import path

from constants import (
    BLACK,
    DEFAULT_PADDING,
    MAPS_DIR_PATH,
    BoardBlockSymbol,
)
from settings_parser import SettingsParser

from .BoardBlock import BoardBlock


class Board(tk.Frame):
    def __init__(
        self, parent: tk.Tk, *, map: list, should_fill: bool = True
    ) -> None:
        super().__init__(
            parent,
            bg=BLACK,
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
            borderwidth=5,
            relief=tk.RAISED,
        )
        self.grid(row=1, column=0, rowspan=2, sticky="nsew")

        self.__map = map if map.all() else self.__parse_board_from_file()
        if should_fill:
            self.first_fill()

        settings = SettingsParser("map").settings
        self.__victory_length = settings["victory_length"]
        self.__file_name = settings["file_name"]

    @property
    def raw_map(self):
        return self.__map

    def __parse_board_from_file(self) -> list:
        assert self.__file_name, "Map file name not found in settings."

        map_file_path = path.join("..", MAPS_DIR_PATH, self.__file_name)
        with open(map_file_path, "r") as file:
            map_rows = file.readlines()
            map_rows = [list(map_row.strip()) for map_row in map_rows]

        return map_rows

    def first_fill(self) -> None:
        for y, row in enumerate(self.__map):
            for x, block in enumerate(row):
                gui_block = BoardBlock(self, block=block)
                gui_block.grid(row=y, column=x)

    def __populate_victory_blocks(self) -> None:
        for y, row in enumerate(self.__map):
            for x, block in enumerate(row):
                if block == BoardBlockSymbol.GREEN_APPLE.value:

                    gui_block = BoardBlock(
                        self,
                        block=BoardBlockSymbol.VICTORY.value,
                    )
                    gui_block.grid(row=y, column=x)

    def fill(self, blocks_to_update: list, snake_length: int = None) -> None:
        for block_info in blocks_to_update:
            y, x = block_info["pos"]
            block = block_info["block"]

            gui_block = BoardBlock(self, block=block)
            gui_block.grid(row=y, column=x)

        has_almost_won = (
            snake_length == self.__victory_length - 1
            if snake_length
            else False
        )
        if has_almost_won:
            self.__populate_victory_blocks()
