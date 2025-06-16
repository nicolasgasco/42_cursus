import tkinter as tk

from constants import (
    BLACK,
    DEFAULT_PADDING,
    LIGHT_GREY,
)

from .DataFrame import DataFrame


class TrainData(tk.LabelFrame):
    def __init__(
        self,
        parent: tk.Tk,
        games_played: int,
        games_won: int,
        games_lost: int,
        elapsed_time: float,
    ):
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

        self.__episodes = DataFrame(
            self, label="Episodes", value=str(games_played)
        )
        self.__games_won = DataFrame(self, label="Wins", value=str(games_won))
        self.__games_lost = DataFrame(
            self, label="Losses", value=str(games_lost)
        )

        win_loss_ratio = (
            games_won * 100 / games_played if games_played > 0 else 0
        )
        self.__win_loss_ratio = DataFrame(
            self,
            label="Win/Loss ratio",
            value=f"{win_loss_ratio:.2f}%",
        )
        self.__elapsed_time = DataFrame(
            self, label="Elapsed seconds", value=elapsed_time
        )

    def update_data(self, args: dict) -> None:
        self.__episodes.update(str(args["games_played"]))
        self.__games_won.update(str(args["games_won"]))
        self.__games_lost.update(str(args["games_lost"]))

        win_loss_ratio = args["games_won"] * 100 / args["games_played"]
        self.__win_loss_ratio.update(f"{win_loss_ratio:.2f}%")

        self.__elapsed_time.update(args["elapsed_time"])
