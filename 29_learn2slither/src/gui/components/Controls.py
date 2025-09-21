import sys as sys
import tkinter as tk

from constants import (
    BG,
    BLACK,
    DEFAULT_PADDING,
    DEFAULT_SPEED,
    MAX_SPEED,
    PRIMARY,
    WHITE,
)
from settings_parser import SettingsParser


class Controls(tk.LabelFrame):
    def __init__(self, parent: tk.Tk):
        super().__init__(
            parent,
            bg=BG,
            text="Controls",
            fg=WHITE,
            font=("Arial", 20, "bold"),
            padx=DEFAULT_PADDING,
            pady=DEFAULT_PADDING,
            width=200,
            height=200,
        )

        self.__parent = parent

        self.grid(row=0, column=0, sticky="nsew")

        is_interactive_mode = SettingsParser("train").settings.get(
            "interactive_mode", False
        )

        self.__create_buttons(is_interactive_mode)
        if not is_interactive_mode:
            self.__create_speed_radio()

    def __create_speed_radio(self) -> None:
        frame = tk.LabelFrame(
            self,
            text="Speed",
            bg=self["bg"],
            fg=self["fg"],
            font=("Arial", 12),
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
            ("Normal", "1"),
            ("Fast", DEFAULT_SPEED),
            ("Faster", "20"),
            ("Turbo", MAX_SPEED),
        ]

        for label, value in speeds:
            radio = tk.Radiobutton(
                frame,
                text=label,
                variable=self.speed,
                value=value,
                bg=self["bg"],
                fg=self["fg"],
                font=("Arial", 12),
                selectcolor=PRIMARY,
            )
            radio.pack(side=tk.LEFT, padx=DEFAULT_PADDING)

    def __create_buttons(self, is_interactive_mode: bool) -> None:
        frame = tk.Frame(
            self,
            bg=self["bg"],
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

        if not is_interactive_mode:
            PAUSE_LABEL = "⏸︎ Pause"
            RESUME_LABEL = "▶︎ Resume"
            pause_button = tk.Button(
                frame,
                text=PAUSE_LABEL,
                bg=PRIMARY,
                highlightbackground=PRIMARY,
                fg=BLACK,
                command=lambda: [
                    self.__parent.frames["train"].toggle_pause(),
                    pause_button.config(
                        text=(
                            RESUME_LABEL
                            if self.__parent.frames["train"].is_paused
                            else PAUSE_LABEL
                        )
                    ),
                ],
                font=("Arial", 20),
                borderwidth=0,
                padx=10,
                pady=5,
            )
            pause_button.pack(side=tk.LEFT, padx=DEFAULT_PADDING)

        stop_button = tk.Button(
            frame,
            text="⏏ Exit",
            bg=self["bg"],
            command=lambda: sys.exit(0),
            font=("Arial", 20),
            borderwidth=0,
            padx=10,
            pady=5,
        )
        stop_button.pack(side=tk.LEFT, padx=DEFAULT_PADDING)
