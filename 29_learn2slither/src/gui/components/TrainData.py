import tkinter as tk

from constants import BG, DEFAULT_PADDING, WHITE

from .DataFrame import DataFrame


class TrainData(tk.LabelFrame):
    def __init__(
        self,
        parent: tk.Tk,
        games_played: int,
        max_games: int,
        games_won: int,
        games_lost: int,
        elapsed_time: float,
    ):
        super().__init__(
            parent,
            bg=BG,
            text="Training data",
            fg=WHITE,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )

        self.grid(row=0, column=1, sticky="nsew")

        self.__max_games = max_games
        self.__episodes = DataFrame(
            self, label="Episodes", value=f"{games_played}/{self.__max_games}"
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
            self, label="Elapsed seconds", value=f"{int(elapsed_time)} s"
        )

    def update_data(
        self,
        games_played: int,
        games_won: int,
        games_lost: int,
        elapsed_time: float,
    ) -> None:
        self.__episodes.update(f"{games_played}/{self.__max_games}")
        self.__games_won.update(str(games_won))
        self.__games_lost.update(str(games_lost))

        win_loss_ratio = games_won * 100 / games_played
        self.__win_loss_ratio.update(f"{win_loss_ratio:.2f}%")

        self.__elapsed_time.update(f"{int(elapsed_time)} s")
