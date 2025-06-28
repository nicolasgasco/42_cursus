import tkinter as tk

from constants import BG, DEFAULT_PADDING, WHITE

from .DataFrame import DataFrame


class AgentData(tk.LabelFrame):
    def __init__(
        self,
        parent: tk.Tk,
        learning_rate: float,
        discount_factor: float,
        exploration_rate: float,
        q_table_entries: int,
    ):
        super().__init__(
            parent,
            bg=BG,
            text="Agent data",
            fg=WHITE,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )

        self.grid(row=0, column=2, sticky="nsew")

        self.__learning_rate = DataFrame(
            self, label="Learning rate", value=f"{learning_rate:.3f}"
        )

        self.__discount_factor = DataFrame(
            self, label="Discount factor", value=f"{discount_factor:.3f}"
        )

        self.__exploration_rate = DataFrame(
            self, label="Exploration rate", value=f"{exploration_rate:.3f}"
        )

        self.__q_table_entries = DataFrame(
            self, label="Q-table entries", value=str(q_table_entries)
        )

    def update_data(
        self,
        learning_rate: float,
        discount_factor: float,
        exploration_rate: float,
        q_table_entries: int,
    ) -> None:
        self.__learning_rate.update(f"{learning_rate:.3f}")
        self.__discount_factor.update(f"{discount_factor:.3f}")
        self.__exploration_rate.update(f"{exploration_rate:.3f}")
        self.__q_table_entries.update(str(q_table_entries))
