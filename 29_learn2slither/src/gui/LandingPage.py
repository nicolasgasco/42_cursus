import tkinter as tk

from constants import BG, BLACK, PRIMARY


class LandingPage(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent, padx=30, pady=15, bg=BG)

        self.__play_button = None
        self.__train_button = None

        self.__init_header()
        self.__init_actions()

    @property
    def play_button(self):
        return self.__play_button

    @property
    def train_button(self):
        return self.__train_button

    def __init_header(self):
        frame = tk.Frame(
            self,
            bg=self["bg"],
        )
        frame.pack(pady=10)

        title = tk.Label(
            frame,
            text="🐍 Welcome to learn2slither! 🐍",
            font=("Arial", 28, "bold"),
            bg=self["bg"],
        )
        title.pack(pady=10)

        subtitle = tk.Label(
            frame,
            text="Choose one of the following options:",
            font=("Arial", 16),
            bg=self["bg"],
        )
        subtitle.pack(pady=10)

    def __init_actions(self):
        frame = tk.Frame(
            self,
            bg=self["bg"],
        )
        frame.pack(pady=10)

        play_button = tk.Button(
            frame,
            text="Play",
            font=("Arial", 20, "bold"),
            width=10,
            height=2,
            bg=PRIMARY,
            highlightbackground=PRIMARY,
            fg=BLACK,
        )
        play_button.pack(pady=10)
        self.__play_button = play_button

        train_button = tk.Button(
            frame,
            text="Train",
            font=("Arial", 20, "bold"),
            width=10,
            height=2,
            bg=PRIMARY,
            highlightbackground=PRIMARY,
            fg=BLACK,
        )
        train_button.pack(pady=10)
        self.__train_button = train_button
