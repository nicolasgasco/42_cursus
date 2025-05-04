import tkinter as tk
from Board import Board
from constants import SnakeDirection
from Game import Game

SPEED = 1_000  # TODO change with configurable settings


def main():
    root = tk.Tk()
    root.title("Learn2Slither")

    board = Board()
    board.render()

    raw_map = board.raw_map
    game_hanlder = Game(raw_map)

    prev_direction = SnakeDirection.LEFT.value

    def on_key_press(_, direction):
        nonlocal prev_direction
        # TODO add logic to check if the snake actually moved
        prev_direction = direction

    root.bind_all(
        "<w>", lambda event: on_key_press(event, SnakeDirection.UP.value)
    )
    root.bind_all(
        "<Up>", lambda event: on_key_press(event, SnakeDirection.UP.value)
    )
    root.bind_all(
        "<a>", lambda event: on_key_press(event, SnakeDirection.LEFT.value)
    )
    root.bind_all(
        "<Left>", lambda event: on_key_press(event, SnakeDirection.LEFT.value)
    )
    root.bind_all(
        "<s>", lambda event: on_key_press(event, SnakeDirection.DOWN.value)
    )
    root.bind_all(
        "<Down>", lambda event: on_key_press(event, SnakeDirection.DOWN.value)
    )
    root.bind_all(
        "<d>", lambda event: on_key_press(event, SnakeDirection.RIGHT.value)
    )
    root.bind_all(
        "<Right>",
        lambda event: on_key_press(event, SnakeDirection.RIGHT.value),
    )

    def tick():
        print("Tick")
        game_hanlder.move_snake(prev_direction)
        board.render()
        root.after(SPEED, tick)

    tick()

    root.mainloop()


if __name__ == "__main__":
    main()
