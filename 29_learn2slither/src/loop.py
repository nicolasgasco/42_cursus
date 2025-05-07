from gui import Board, Root, Controls
from constants import DEFAULT_SNAKE_DIRECTION
from game_logic import Game


def main():
    root = Root()

    root.controls = Controls(root)

    root.board = Board(root)

    game_handler = Game(root.board.raw_map)

    intended_direction = DEFAULT_SNAKE_DIRECTION
    prev_direction = DEFAULT_SNAKE_DIRECTION

    def on_key_press(_, direction):
        nonlocal intended_direction
        intended_direction = direction

    root.bind_movement_keys(on_key_press)

    def on_tick():
        if game_handler.game_over:
            print("Game Over")
            root.after(2000, root.quit)
            return

        game_handler.move_snake(intended_direction)

        if game_handler.has_moved:
            nonlocal prev_direction
            prev_direction = intended_direction
        else:
            game_handler.move_snake(prev_direction)

    root.tick(on_tick)
    root.mainloop()


if __name__ == "__main__":
    main()
