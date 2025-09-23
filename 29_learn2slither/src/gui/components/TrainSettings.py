import json as json
import tkinter as tk
from os import listdir, path

from constants import (
    DEFAULT_EXISTING_MODEL,
    DEFAULT_MAX_EPISODES,
    SETTINGS_DIR_PATH,
    TRAIN_SETTINGS_FILE_NAME,
)


class TrainSettings(tk.LabelFrame):
    def __init__(self, parent: tk.Tk):
        super().__init__(
            parent,
            text="Train settings",
            padx=10,
            pady=10,
            width=300,
        )

        self.__max_episodes = tk.StringVar(value=DEFAULT_MAX_EPISODES)
        self.__existing_model = tk.StringVar(value=DEFAULT_EXISTING_MODEL)
        self.__interactive_mode = tk.BooleanVar(value=False)
        self.__benchmark_mode = tk.BooleanVar(value=False)

        self.__render_max_episodes_dropdown()
        self.__render_import_model_dropdown()
        self.__render_interactive_mode_toggle()
        self.__render_benchmark_mode_toggle()

    def __render_max_episodes_dropdown(self) -> None:
        frame = tk.Frame(self)
        frame.pack(fill=tk.X, padx=10, pady=10)

        label = tk.Label(frame, text="Max episodes")
        label.pack(side=tk.LEFT, padx=5)

        options = [
            1,
            10,
            100,
            DEFAULT_MAX_EPISODES,
            2_000,
            5_000,
            10_000,
            20_000,
            50_000,
            100_000,
            1_000_000,
        ]

        self.__store_setting_in_file("max_episodes", DEFAULT_MAX_EPISODES)

        dropdown = tk.OptionMenu(
            frame,
            self.__max_episodes,
            *[option for option in options],
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
            text=("activate to control agent during training"),
            font=("Arial", 12),
        )
        subtitle.pack(side=tk.LEFT, padx=5)

    def __get_list_of_models(self) -> list[str]:
        # TODO change to constant
        models_path = "../models"

        if not path.exists(models_path):
            return []

        return [
            file_name.split(".")[0]
            for file_name in listdir(models_path)
            if file_name.endswith(".json")
        ]

    def __render_import_model_dropdown(self) -> None:
        frame = tk.Frame(self)
        frame.pack(fill=tk.X, padx=10, pady=10)

        label = tk.Label(frame, text="Import existing model")
        label.pack(side=tk.LEFT, padx=5)

        models = self.__get_list_of_models()
        options = [DEFAULT_EXISTING_MODEL] + sorted(models, reverse=True)

        self.__store_setting_in_file("existing_model", None)
        dropdown = tk.OptionMenu(
            frame,
            self.__existing_model,
            *[option for option in options],
            command=lambda value: self.__store_setting_in_file(
                "existing_model",
                value if value != DEFAULT_EXISTING_MODEL else None,
            ),
        )
        dropdown.pack(side=tk.LEFT, padx=5)

    def __render_benchmark_mode_toggle(self) -> None:
        frame = tk.Frame(self)
        frame.pack(fill=tk.X, padx=10, pady=10)

        label = tk.Label(frame, text="Benchmark mode")
        label.pack(side=tk.LEFT, padx=5)

        self.__store_setting_in_file("benchmark_mode", False)
        checkbox = tk.Checkbutton(
            frame,
            variable=self.__benchmark_mode,
            command=lambda: self.__store_setting_in_file(
                "benchmark_mode", bool(self.__benchmark_mode.get())
            ),
            onvalue=True,
            offvalue=False,
        )
        checkbox.pack(side=tk.LEFT, padx=5)

        subtitle = tk.Label(
            frame,
            text=("agent does not train, activate to monitor performance"),
            font=("Arial", 12),
        )
        subtitle.pack(side=tk.LEFT, padx=5)
