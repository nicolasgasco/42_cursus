import tkinter as tk
from constants import (
    BLACK,
    LIGHT_GREY,
    PRIMARY,
)


class DataFrame(tk.Frame):
    def __init__(self, parent: tk.Tk, args: dict):
        super().__init__(parent, bg=parent["bg"], padx=0, pady=0)
        self.pack(
            side=tk.TOP,
            anchor=tk.W,
            fill=tk.X,
            padx=0,
            pady=0,
        )

        self.__label = args["label"]
        self.__value_label: tk.Label | None = None

        self.render(str(args["value"]))

    def render(self, value: str) -> None:
        LINE_LENGTH = 40
        padding = LINE_LENGTH - len(self.__label) - len(value)

        label = tk.Label(
            self,
            text=self.__label + " " * padding,
            bg=LIGHT_GREY,
            fg=BLACK,
            font=("Arial", 18),
            anchor="w",
        )
        label.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=5)

        self.__value_label = tk.Label(
            self,
            text=value,
            bg=LIGHT_GREY,
            fg=PRIMARY,
            font=("Arial", 18),
            anchor="e",
        )
        self.__value_label.pack(side=tk.RIGHT, fill=tk.X, expand=True, padx=5)

    def update(self, value: str) -> None:
        self.__value_label.config(text=value)
