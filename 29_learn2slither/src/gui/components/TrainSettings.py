import json as json
import tkinter as tk
from os import path

from constants import DEFAULT_MAX_EPISODES, SETTINGS_DIR_PATH


class TrainSettings(tk.LabelFrame):
    def __init__(self, parent: tk.Tk):
        super().__init__(
            parent,
            text="Train settings",
            padx=10,
            pady=10,
            width=300,
        )

        self.__max_episodes = None
        self.__interactive_mode = tk.BooleanVar(value=False)

        self.__render_max_episodes_widget()
        self.__render_interactive_mode_toggle()

    def __render_max_episodes_widget(self) -> None:
        frame = tk.Frame(self)
        frame.pack(fill=tk.X, padx=10, pady=10)

        label = tk.Label(frame, text="Max episodes")
        label.pack(side=tk.LEFT, padx=5)

        self.__max_episodes = tk.StringVar()

        options = [
            {"label": "5,000", "value": 5_000},
            {"label": "10,000", "value": 10_000},
            {"label": "50,000", "value": 50_000},
            {"label": "100,000", "value": 100_000},
            {"label": "200,000", "value": 200_000},
            {"label": "500,000", "value": 500_000},
            {"label": "1,000,000", "value": 1_000_000},
            {"label": "2,000,000", "value": 2_000_000},
            {"label": "5,000,000", "value": 5_000_000},
        ]

        self.__max_episodes.set(DEFAULT_MAX_EPISODES)
        self.__store_max_episodes(DEFAULT_MAX_EPISODES)

        dropdown = tk.OptionMenu(
            frame,
            self.__max_episodes,
            *[option["value"] for option in options],
            command=self.__store_max_episodes,
        )
        dropdown.pack(side=tk.LEFT, padx=5)

    def __store_max_episodes(self, value: int) -> None:
        file_name = path.join(
            "..",
            SETTINGS_DIR_PATH,
            "train.json",
        )
        with open(file_name, "r") as file:
            settings = file.read()
            settings = json.loads(settings)

        settings["max_episodes"] = value

        with open(file_name, "w") as file:
            json.dump(settings, file, indent=4)

    def __render_interactive_mode_toggle(self):
        frame = tk.Frame(self)
        frame.pack(fill=tk.X, padx=10, pady=10)

        label = tk.Label(frame, text="Interactive mode")
        label.pack(side=tk.LEFT, padx=5)

        checkbox = tk.Checkbutton(
            frame,
            variable=self.__interactive_mode,
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
