from constants import DEFAULT_SNAKE_DIRECTION
from game_logic import Game
from gui import Board, Controls, GameData, Root, TrainData


def init_interface(root: Root):
    root.board = Board(root)
    game_handler = Game(root.board.raw_map)
    root.game_data = GameData(
        root,
        {
            "moves": game_handler.moves,
            "length": game_handler.length,
            "red_apples": game_handler.apples_red,
            "green_apples": game_handler.apples_green,
        },
    )

    return game_handler


def main():
    games_lost = 0  # TODO move to training object
    games_won = 0  # TODO move to training object

    root = Root()
    root.controls = Controls(root)
    root.train_data = TrainData(
        root,
        {
            "games_played": games_lost + games_won,
            "games_won": games_won,
            "games_lost": games_lost,
        },
    )

    intended_direction = DEFAULT_SNAKE_DIRECTION
    prev_direction = DEFAULT_SNAKE_DIRECTION

    game_handler = init_interface(root)

    def on_key_press(_, direction):
        nonlocal intended_direction
        intended_direction = direction

    root.bind_movement_keys(on_key_press)

    def on_tick():
        nonlocal prev_direction
        nonlocal intended_direction
        nonlocal game_handler
        nonlocal games_lost
        nonlocal games_won

        game_handler.move_snake(intended_direction)

        if game_handler.has_moved:
            prev_direction = intended_direction
        else:
            game_handler.move_snake(prev_direction)

        root.game_data.update_data(
            {
                "moves": game_handler.moves,
                "length": game_handler.length,
                "red_apples": game_handler.apples_red,
                "green_apples": game_handler.apples_green,
            }
        )

        if game_handler.game_over or game_handler.has_won:
            if game_handler.has_won:
                print("Game won!")
                games_won += 1
            else:
                print("Game Over :(")
                games_lost += 1

            root.train_data.update_data(
                {
                    "games_played": games_lost + games_won,
                    "games_won": games_won,
                    "games_lost": games_lost,
                }
            )

            intended_direction = DEFAULT_SNAKE_DIRECTION
            prev_direction = DEFAULT_SNAKE_DIRECTION

            game_handler = init_interface(root)

            return

        root.board.fill(game_handler.blocks_to_update)

    root.tick(on_tick)
    root.mainloop()


if __name__ == "__main__":
    main()
