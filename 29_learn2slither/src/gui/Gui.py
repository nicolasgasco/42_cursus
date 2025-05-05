import tkinter as tk
from constants import SnakeDirection

SPEED = 1_000  # TODO change with configurable settings


class TkGui(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Learn2Slither")

        self.__board = None

    @property
    def board(self):
        return self.__board

    @board.setter
    def board(self, board):
        self.__board = board

    def tick(self, on_tick: callable) -> None:
        on_tick()
        self.__board.fill()
        self.after(SPEED, lambda: self.tick(on_tick))

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
