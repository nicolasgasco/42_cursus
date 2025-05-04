import tkinter as tk
from settings_parser import SettingsParser
from Board import Board

def main():
    root = tk.Tk()
    root.title("Learn2Slither")
    
    board = Board()
    board.render()

    root.mainloop()

if __name__ == "__main__":
    main()
