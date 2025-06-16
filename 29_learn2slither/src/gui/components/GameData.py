import tkinter as tk

from constants import (
    BLACK,
    DEFAULT_PADDING,
    LIGHT_GREY,
)

from .DataFrame import DataFrame


class GameData(tk.LabelFrame):
    def __init__(
        self,
        parent: tk.Tk,
        length: int,
        red_apples: int,
        green_apples: int,
        moves: int,
    ):
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

        self.__moves = DataFrame(self, label="Moves", value=str(moves))
        self.__length = DataFrame(self, label="Length", value=str(length))
        self.__red_apples = DataFrame(
            self, label="Red apples", value=str(red_apples)
        )
        self.__green_apples = DataFrame(
            self, label="Green apples", value=str(green_apples)
        )

    def update_data(
        self,
        moves: int,
        length: int,
        red_apples: int,
        green_apples: int,
    ) -> None:
        self.__moves.update(str(moves))
        self.__length.update(str(length))
        self.__red_apples.update(str(red_apples))
        self.__green_apples.update(str(green_apples))
