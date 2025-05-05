from Board import Board
from constants import SnakeDirection
from game_logic import Game
from Gui import TkGui


def main():
    gui = TkGui()

    gui.board = Board()
    gui.board.fill()

    raw_map = gui.board.raw_map
    game_handler = Game(raw_map)

    intended_direction = SnakeDirection.LEFT.value
    prev_direction = SnakeDirection.LEFT.value

    def on_key_press(_, direction):
        nonlocal intended_direction
        intended_direction = direction

    gui.bind_movement_keys(on_key_press)

    def on_tick():
        nonlocal prev_direction
        game_handler.move_snake(intended_direction)

        if game_handler.game_over:
            print("Game Over")
            gui.after(2000, gui.quit)
            return
        elif game_handler.has_moved:
            prev_direction = intended_direction
        else:
            game_handler.move_snake(prev_direction)

    gui.tick(on_tick)

    gui.mainloop()


if __name__ == "__main__":
    main()
