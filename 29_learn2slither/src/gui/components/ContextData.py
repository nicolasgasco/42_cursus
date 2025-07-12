import tkinter as tk

from constants import (
    BG,
    BLANK_CHARACTER,
    DEFAULT_PADDING,
    WHITE,
    BoardBlockSymbol,
)
from settings_parser import SettingsParser

from .DataFrame import DataFrame


class ContextData(tk.LabelFrame):
    def __init__(self, parent: tk.Tk):
        super().__init__(
            parent,
            bg=BG,
            text="Context data",
            fg=WHITE,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )

        self.grid(row=1, column=1, sticky="nsew")

        self.__blank_map = self.__generate_blank_map()
        self.__map = self.__blank_map

        self.__context = DataFrame(
            self,
            value=self.__map,
        )

        self.__next_move = DataFrame(
            self,
            label="Next move",
            value="-",
        )

    def __generate_blank_map(self) -> str:
        settings = SettingsParser("map").settings
        map_width = settings["width"]
        map_height = settings["height"]

        map = [BLANK_CHARACTER * map_width for _ in range(map_height)]

        return "\n".join(map)

    def update_data(
        self,
        context: dict,
        head_pos: tuple[int, int],
        next_move_str: str = "",
    ) -> None:
        self.__next_move.update(next_move_str)

        contexts = [context for context in context.values()]

        map = [list(row) for row in self.__blank_map.split("\n")]

        for context in contexts:
            for block_info in context:
                y, x = block_info["pos"]
                map[y][x] = block_info["block"]

        head_y, head_x = head_pos
        map[head_y][head_x] = BoardBlockSymbol.HEAD.value

        self.__map = "\n".join("".join(row) for row in map)

        self.__context.update(self.__map)
