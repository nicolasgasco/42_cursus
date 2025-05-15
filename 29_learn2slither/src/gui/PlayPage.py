import tkinter as tk

from constants import SnakeDirection

DEFAULT_SPEED_MS = 1_000


class PlayPage(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent, padx=30, pady=15)

        self.__is_paused = False

        self.__board = None
        self.__controls = None
        self.__game_data = None

        self.__tick_id = None

    @property
    def board(self):
        return self.__board

    @board.setter
    def board(self, board):
        self.__board = board

    @property
    def game_data(self):
        return self.__game_data

    @game_data.setter
    def game_data(self, data):
        self.__game_data = data

    def toggle_pause(self) -> None:
        self.__is_paused = not self.__is_paused

    def tick(self, on_tick: callable) -> None:
        if not self.__is_paused:
            on_tick()

        if self.__controls:
            speed = int(DEFAULT_SPEED_MS / float(self.controls.speed.get()))
        else:
            speed = int(DEFAULT_SPEED_MS / 2)

        self.__tick_id = self.after(speed, lambda: self.tick(on_tick))

    def stop_tick(self) -> None:
        if self.__tick_id:
            self.after_cancel(self.__tick_id)
            self.__tick_id = None

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

    def bind_pause_key(self) -> None:
        self.bind_all("<space>", lambda _: self.toggle_pause())
