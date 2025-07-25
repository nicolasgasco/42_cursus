import tkinter as tk


class DataFrame(tk.Frame):
    def __init__(self, parent: tk.Tk, value: str | int, label: str = None):
        super().__init__(parent, bg=parent["bg"], padx=0, pady=0)
        self.pack(
            side=tk.TOP,
            anchor=tk.W,
            fill=tk.X,
            padx=0,
            pady=0,
        )

        self.__label = label
        self.__value_label: tk.Label | None = None

        self.render(str(value))

    def render(self, value: str) -> None:
        if self.__label:
            LINE_LENGTH = 40
            padding = LINE_LENGTH - len(self.__label) - len(value)

            label = tk.Label(
                self,
                text=self.__label + " " * padding,
                bg=self["bg"],
                font=("Arial", 18),
                anchor="w",
            )
            label.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=5)

        self.__value_label = tk.Label(
            self,
            text=value,
            bg=self["bg"],
            font=("Arial", 18),
            anchor="e",
        )
        self.__value_label.pack(
            side=(tk.RIGHT if self.__label else tk.LEFT),
            fill=tk.Y,
            expand=True if self.__label else False,
            padx=5,
        )

    def update(self, value: str) -> None:
        self.__value_label.config(text=value)
