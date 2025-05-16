import tkinter as tk

from constants import (
    BLACK,
    DEFAULT_PADDING,
    LIGHT_GREY,
)

from .DataFrame import DataFrame


class GameData(tk.LabelFrame):
    def __init__(self, parent: tk.Tk, args: dict):
        super().__init__(
            parent,
            bg=LIGHT_GREY,
            text="Game data",
            fg=BLACK,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )

        self.grid(row=1, column=1, sticky="nsew")

        self.__moves = DataFrame(
            self, {"label": "Moves", "value": str(args["moves"])}
        )
        self.__length = DataFrame(
            self, {"label": "Length", "value": str(args["length"])}
        )
        self.__red_apples = DataFrame(
            self, {"label": "Red apples", "value": str(args["red_apples"])}
        )
        self.__green_apples = DataFrame(
            self, {"label": "Green apples", "value": str(args["green_apples"])}
        )

    def update_data(self, args: dict) -> None:
        self.__moves.update(str(args["moves"]))
        self.__length.update(str(args["length"]))
        self.__red_apples.update(str(args["red_apples"]))
        self.__green_apples.update(str(args["green_apples"]))
