import tkinter as tk


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
            {"label": "10,000", "value": 10_000},
            {"label": "50,000", "value": 50_000},
            {"label": "100,000", "value": 100_000},
            {"label": "200,000", "value": 200_000},
            {"label": "500,000", "value": 500_000},
            {"label": "1,000,000", "value": 1_000_000},
            {"label": "2,000,000", "value": 2_000_000},
            {"label": "5,000,000", "value": 5_000_000},
        ]

        self.__max_episodes.set(options[3]["label"])

        dropdown = tk.OptionMenu(
            frame,
            self.__max_episodes,
            *[option["label"] for option in options],
        )
        dropdown.pack(side=tk.LEFT, padx=5)

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
            text="(if activated, the agent won't train at automatically)",
            font=("Arial", 12),
        )
        subtitle.pack(side=tk.LEFT, padx=5)
