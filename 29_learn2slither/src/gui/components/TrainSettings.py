import json as json
import tkinter as tk
from os import path

from constants import DEFAULT_MAX_EPISODES, SETTINGS_DIR_PATH
from constants.settings import TRAIN_SETTINGS_FILE_NAME


class TrainSettings(tk.LabelFrame):
    def __init__(self, parent: tk.Tk):
        super().__init__(
            parent,
            text="Train settings",
            padx=10,
            pady=10,
            width=300,
        )

        self.__interactive_mode = tk.BooleanVar(value=True)
        self.__max_episodes = tk.StringVar(value=DEFAULT_MAX_EPISODES)

        self.__render_max_episodes_widget()
        self.__render_interactive_mode_toggle()

    def __render_max_episodes_widget(self) -> None:
        frame = tk.Frame(self)
        frame.pack(fill=tk.X, padx=10, pady=10)

        label = tk.Label(frame, text="Max episodes")
        label.pack(side=tk.LEFT, padx=5)

        options = [
            {"label": "1", "value": 1},
            {"label": "10", "value": 10},
            {"label": "100", "value": 100},
            {"label": "1,000", "value": DEFAULT_MAX_EPISODES},
            {"label": "2,000", "value": 2_000},
            {"label": "5,000", "value": 5_000},
            {"label": "10,000", "value": 10_000},
            {"label": "20,000", "value": 20_000},
            {"label": "50,000", "value": 50_000},
            {"label": "100,000", "value": 100_000},
        ]

        self.__store_setting_in_file("max_episodes", DEFAULT_MAX_EPISODES)

        dropdown = tk.OptionMenu(
            frame,
            self.__max_episodes,
            *[option["value"] for option in options],
            command=lambda value: self.__store_setting_in_file(
                "max_episodes", int(value)
            ),
        )
        dropdown.pack(side=tk.LEFT, padx=5)

    def __store_setting_in_file(self, key: str, value: int | bool) -> None:
        file_name = path.join(
            "..",
            SETTINGS_DIR_PATH,
            TRAIN_SETTINGS_FILE_NAME,
        )
        with open(file_name, "r") as file:
            settings = file.read()
            settings = json.loads(settings)

        settings[key] = value

        with open(file_name, "w") as file:
            json.dump(settings, file, indent=4)

    def __render_interactive_mode_toggle(self):
        frame = tk.Frame(self)
        frame.pack(fill=tk.X, padx=10, pady=10)

        label = tk.Label(frame, text="Interactive mode")
        label.pack(side=tk.LEFT, padx=5)

        self.__store_setting_in_file(
            "interactive_mode", bool(self.__interactive_mode.get())
        )
        checkbox = tk.Checkbutton(
            frame,
            variable=self.__interactive_mode,
            command=lambda: self.__store_setting_in_file(
                "interactive_mode", bool(self.__interactive_mode.get())
            ),
            onvalue=True,
            offvalue=False,
        )
        checkbox.pack(side=tk.LEFT, padx=5)

        subtitle = tk.Label(
            frame,
            text=(
                "(if activated, you will be able to control the agent "
                "during training)"
            ),
            font=("Arial", 12),
        )
        subtitle.pack(side=tk.LEFT, padx=5)
