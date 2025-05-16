import tkinter as tk


class SettingsPage(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent, padx=30, pady=15)

        self.__init_header()

    def __init_header(self):
        frame = tk.Frame(self)
        frame.pack(pady=10)

        title = tk.Label(frame, text="Settings", font=("Arial", 28, "bold"))
        title.pack(pady=10)
