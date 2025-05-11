import tkinter as tk

from constants import BLACK, DEFAULT_PADDING, LIGHT_GREY, BoardBlockSymbol
from settings_parser import SettingsParser

from .DataFrame import DataFrame


class ContextData(tk.LabelFrame):
    def __init__(self, parent: tk.Tk, args: dict):
        super().__init__(
            parent,
            bg=LIGHT_GREY,
            text="Context data",
            fg=BLACK,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )

        self.grid(row=2, column=1, sticky="nsew")

        self.__map = self.__blank_map()

        self.__context = DataFrame(
            self,
            {"value": self.__map},
        )

    def __blank_map(self) -> str:
        settings = SettingsParser().settings
        map_width = settings["width"]
        map_height = settings["height"]

        map = ["❔" * map_width for _ in range(map_height)]

        return "\n".join(map)

    def update_data(self, args: dict) -> None:
        contexts = [context for context in args["context"].values()]

        map = [list(row) for row in self.__blank_map().split("\n")]

        for context in contexts:
            for block_info in context:
                y, x = block_info["pos"]
                map[y][x] = block_info["block"]

        head_y, head_x = args["head_pos"]
        map[head_y][head_x] = BoardBlockSymbol.HEAD.value

        self.__map = "\n".join("".join(row) for row in map)

        self.__context.update(self.__map)
