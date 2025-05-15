import tkinter as tk

from constants import INTERACTIVE_ACTION


class Root(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Learn2Slither")

        self.__frames = {
            "landing": None,
            "game": None,
            "train": None,
        }

        self.__controls = None
        self.__train_data = None
        self.__context_data = None

        self.__is_paused = False

        self.bind("<Escape>", lambda _: self.quit())
        self.bind("<p>", lambda _: self.pause())

    @property
    def frames(self):
        return self.__frames

    @property
    def controls(self):
        return self.__controls

    @controls.setter
    def controls(self, controls):
        self.__controls = controls

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

    def destroy_frame(self, frame_name: str = None):
        if frame_name is None:
            return

        if self.__frames[frame_name]:
            for widget in self.__frames[frame_name].winfo_children():
                widget.destroy()
            self.__frames[frame_name].destroy()
            self.__frames[frame_name] = None

    def pause(self):
        self.__is_paused = not self.__is_paused

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
