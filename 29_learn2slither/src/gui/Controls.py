import tkinter as tk

from constants import (
    BLACK,
    DEFAULT_PADDING,
    DEFAULT_SPEED,
    LIGHT_GREY,
    PRIMARY,
)


class Controls(tk.LabelFrame):
    def __init__(self, parent: tk.Tk):
        super().__init__(
            parent,
            bg=LIGHT_GREY,
            text="Controls",
            fg=BLACK,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
            width=200,
            height=200,
        )

        self.grid(row=0, column=0, sticky="nsew")

        self.__create_speed_radio()

    def __create_speed_radio(self) -> None:
        frame = tk.LabelFrame(
            self,
            text="Speed",
            bg=self["bg"],
            fg=self["fg"],
            font=("Arial", 12),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )
        frame.pack(
            side=tk.TOP,
            anchor=tk.W,
            fill=tk.X,
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
        )

        self.speed = tk.StringVar()
        self.speed.set(DEFAULT_SPEED)

        speeds = [
            DEFAULT_SPEED,
            "50",
            "100",
            "200",
            "500",
            "750",
            "1000",
        ]

        for speed in speeds:
            radio = tk.Radiobutton(
                frame,
                text=f"{speed}x",
                variable=self.speed,
                value=speed,
                bg=self["bg"],
                fg=self["fg"],
                font=("Arial", 12),
                selectcolor=PRIMARY,
            )
            radio.pack(side=tk.LEFT, padx=DEFAULT_PADDING)
