import tkinter as tk

from gui.components.TrainSettings import TrainSettings


class SettingsPage(tk.Frame):
    def __init__(self, parent, args: dict):
        super().__init__(parent, padx=30, pady=15)

        self.__render_header()
        self.__render_train_settings()
        self.__render_buttons(
            {
                "handle_go_back": args["handle_go_back"],
            }
        )

        self.__train_settings = None

    @property
    def train_settings(self):
        return self.__train_settings

    @train_settings.setter
    def train_settings(self, settings):
        self.__train_settings = settings

    def __render_header(self):
        frame = tk.Frame(self)
        frame.pack(pady=10)

        title = tk.Label(frame, text="Settings", font=("Arial", 28, "bold"))
        title.pack(pady=10)

    def __render_train_settings(self):
        train_settings = TrainSettings(self)
        train_settings.pack(fill="both", expand=True)

    def __render_buttons(self, args: dict):
        frame = tk.Frame(self)
        frame.pack(pady=10)

        back_button = tk.Button(
            frame,
            bg="lightgrey",
            fg="black",
            borderwidth=1,
            relief="solid",
            text="Back",
            font=("Arial", 20, "bold"),
            command=args["handle_go_back"],
        )
        back_button.pack(pady=10)

        train_button = tk.Button(
            frame,
            text="Start training",
            font=("Arial", 20, "bold"),
            command=lambda: print("Train button clicked"),
        )
        train_button.pack(pady=10)
