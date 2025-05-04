import tkinter as tk
from Board import Board


def main():
    root = tk.Tk()
    root.title("Learn2Slither")

    board = Board()
    board.render()

    # BInd WASP keys to the snake
    root.bind_all("<w>", lambda event: print("Move Up"))
    root.bind_all("<Up>", lambda event: print("Move Up"))

    root.bind_all("<a>", lambda event: print("Move Left"))
    root.bind_all("<Left>", lambda event: print("Move Left"))

    root.bind_all("<s>", lambda event: print("Move Down"))
    root.bind_all("<Down>", lambda event: print("Move Down"))

    root.bind_all("<d>", lambda event: print("Move Right"))
    root.bind_all("<Right>", lambda event: print("Move Right"))

    root.mainloop()


if __name__ == "__main__":
    main()
