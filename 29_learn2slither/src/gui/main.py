import tkinter as tk
from Board import Board
from Game import Game


def main():
    root = tk.Tk()
    root.title("Learn2Slither")

    board = Board()
    board.render()

    raw_map = board.raw_map
    game_hanlder = Game(raw_map)

    def on_key_press(event, direction=None):
        game_hanlder.move_snake(direction)
        board.render()

    root.bind_all("<w>", lambda event: on_key_press(event, "UP"))
    root.bind_all("<Up>", lambda event: on_key_press(event, "UP"))

    root.bind_all("<a>", lambda event: on_key_press(event, "LEFT"))
    root.bind_all("<Left>", lambda event: on_key_press(event, "LEFT"))

    root.bind_all("<s>", lambda event: on_key_press(event, "DOWN"))
    root.bind_all("<Down>", lambda event: on_key_press(event, "DOWN"))

    root.bind_all("<d>", lambda event: on_key_press(event, "RIGHT"))
    root.bind_all("<Right>", lambda event: on_key_press(event, "RIGHT"))

    root.mainloop()


if __name__ == "__main__":
    main()
