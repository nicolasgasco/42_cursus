import tkinter as tk

from constants import INTERACTIVE_ACTION, SnakeDirection

DEFAULT_SPEED_MS = 1_000


class Root(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Learn2Slither")

        self.__board = None
        self.__controls = None
        self.__game_data = None
        self.__train_data = None
        self.__context_data = None

        self.__is_paused = False

        self.bind("<Escape>", lambda _: self.quit())
        self.bind("<p>", lambda _: self.pause())

    @property
    def board(self):
        return self.__board

    @board.setter
    def board(self, board):
        self.__board = board

    @property
    def controls(self):
        return self.__controls

    @controls.setter
    def controls(self, controls):
        self.__controls = controls

    @property
    def game_data(self):
        return self.__game_data

    @game_data.setter
    def game_data(self, data):
        self.__game_data = data

    @property
    def train_data(self):
        return self.__train_data

    @train_data.setter
    def train_data(self, data):
        self.__train_data = data

    @property
    def context_data(self):
        return self.__context_data

    @context_data.setter
    def context_data(self, data):
        self.__context_data = data

    def pause(self):
        self.__is_paused = not self.__is_paused

    def tick(self, on_tick: callable) -> None:
        if not self.__is_paused:
            on_tick()

        speed = int(DEFAULT_SPEED_MS / float(self.controls.speed.get()))
        self.after(speed, lambda: self.tick(on_tick))

    def bind_movement_keys(self, on_key_press: callable) -> None:
        events = [
            {
                "keys": ["<w>", "<Up>"],
                "direction": SnakeDirection.UP.value,
            },
            {
                "keys": ["<a>", "<Left>"],
                "direction": SnakeDirection.LEFT.value,
            },
            {
                "keys": ["<s>", "<Down>"],
                "direction": SnakeDirection.DOWN.value,
            },
            {
                "keys": ["<d>", "<Right>"],
                "direction": SnakeDirection.RIGHT.value,
            },
        ]

        for event in events:
            for key in event["keys"]:
                self.bind_all(
                    key,
                    lambda event, direction=event["direction"]: on_key_press(
                        event, direction
                    ),
                )

    def bind_training_keys(self, on_key_press: callable) -> None:
        self.bind_all(
            "<Left>",
            lambda event, direction=INTERACTIVE_ACTION.BACKWARD: on_key_press(
                event, direction
            ),
        )
        self.bind_all(
            "<Right>",
            lambda event, direction=INTERACTIVE_ACTION.FORWARD: on_key_press(
                event, direction
            ),
        )
