import tkinter as tk

from constants import SnakeDirection

DEFAULT_SPEED_MS = 1_000


class Root(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Learn2Slither")

        self.__board = None
        self.__controls = None

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

    def tick(self, on_tick: callable) -> None:
        on_tick()
        self.__board.fill()

        speed = int(DEFAULT_SPEED_MS / float(self.controls.speed.get()))
        self.after(speed, lambda: self.tick(on_tick))

    def bind_movement_keys(self, on_key_press: callable) -> None:
        self.bind_all(
            "<w>", lambda event: on_key_press(event, SnakeDirection.UP.value)
        )
        self.bind_all(
            "<Up>", lambda event: on_key_press(event, SnakeDirection.UP.value)
        )
        self.bind_all(
            "<a>", lambda event: on_key_press(event, SnakeDirection.LEFT.value)
        )
        self.bind_all(
            "<Left>",
            lambda event: on_key_press(event, SnakeDirection.LEFT.value),
        )
        self.bind_all(
            "<s>", lambda event: on_key_press(event, SnakeDirection.DOWN.value)
        )
        self.bind_all(
            "<Down>",
            lambda event: on_key_press(event, SnakeDirection.DOWN.value),
        )
        self.bind_all(
            "<d>",
            lambda event: on_key_press(event, SnakeDirection.RIGHT.value),
        )
        self.bind_all(
            "<Right>",
            lambda event: on_key_press(event, SnakeDirection.RIGHT.value),
        )
