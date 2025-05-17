import tkinter as tk


class Root(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Learn2Slither")

        self.__frames = {
            "landing": None,
            "game": None,
            "settings": None,
            "train": None,
        }

        self.__is_paused = False

        self.bind("<Escape>", lambda _: self.quit())
        self.bind("<p>", lambda _: self.pause())

    @property
    def frames(self):
        return self.__frames

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
