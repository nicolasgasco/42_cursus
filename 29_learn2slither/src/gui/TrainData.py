import tkinter as tk

from constants import (
    BLACK,
    DEFAULT_PADDING,
    LIGHT_GREY,
)

from .DataFrame import DataFrame


class TrainData(tk.LabelFrame):
    def __init__(self, parent: tk.Tk, args: dict):
        super().__init__(
            parent,
            bg=LIGHT_GREY,
            text="Training data",
            fg=BLACK,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )

        self.grid(row=0, column=1, sticky="nsew")

        self.__games_played = DataFrame(
            self, {"label": "Games played", "value": str(args["games_played"])}
        )
        self.__games_won = DataFrame(
            self, {"label": "Wins", "value": str(args["games_won"])}
        )
        self.__games_lost = DataFrame(
            self, {"label": "Losses", "value": str(args["games_lost"])}
        )
        self.__elapsed_time = DataFrame(
            self, {"label": "Elapsed time", "value": args["elapsed_time"]}
        )

    def update_data(self, args: dict) -> None:
        self.__games_played.update(str(args["games_played"]))
        self.__games_won.update(str(args["games_won"]))
        self.__games_lost.update(str(args["games_lost"]))
        self.__elapsed_time.update(args["elapsed_time"])
