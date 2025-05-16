import tkinter as tk

DEFAULT_SPEED_MS = 1_000


class TrainPage(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent, padx=30, pady=15)

        self.__is_paused = False

        self.__board = None
        self.__controls = None
        self.__game_data = None
        self.__train_data = None
        self.__context_data = None

        self.__tick_id = None

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

    def toggle_pause(self) -> None:
        self.__is_paused = not self.__is_paused

    def tick(self, on_tick: callable) -> None:
        if not self.__is_paused:
            on_tick()

        speed = int(DEFAULT_SPEED_MS / float(self.controls.speed.get()))

        self.__tick_id = self.after(speed, lambda: self.tick(on_tick))

    def stop_tick(self) -> None:
        if self.__tick_id:
            self.after_cancel(self.__tick_id)
            self.__tick_id = None
