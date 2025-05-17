from tkinter import messagebox

from constants import DEFAULT_SNAKE_DIRECTION
from game_logic import Game
from gui import (
    Board,
    GameData,
    PlayPage,
    Root,
)
from map import MapGenerator


def render_game_mode(
    root: Root,
    *,
    render_landing: callable,
    render_train_mode: callable,
    render_train_settings: callable,
):
    root.frames["game"] = PlayPage(root)
    root.frames["game"].pack(fill="both", expand=True)

    map_generator = MapGenerator()
    map_generator.generate_map()

    root.frames["game"].board = Board(
        root.frames["game"], {"map": map_generator.map}
    )
    game_handler = Game(root.frames["game"].board.raw_map)

    root.frames["game"].game_data = GameData(
        root.frames["game"],
        {
            "moves": game_handler.moves,
            "length": game_handler.length,
            "red_apples": game_handler.apples_red,
            "green_apples": game_handler.apples_green,
        },
    )

    intended_direction = DEFAULT_SNAKE_DIRECTION
    prev_direction = DEFAULT_SNAKE_DIRECTION

    def on_key_press(_, direction):
        nonlocal intended_direction
        intended_direction = direction

    root.frames["game"].bind_movement_keys(on_key_press)
    root.frames["game"].bind_pause_key()

    def on_tick():
        nonlocal prev_direction

        game_handler.move_snake(intended_direction)

        if game_handler.has_moved:
            prev_direction = intended_direction
        else:
            game_handler.move_snake(prev_direction)

        root.frames["game"].board.fill(game_handler.blocks_to_update)
        root.frames["game"].game_data.update_data(
            {
                "moves": game_handler.moves,
                "length": game_handler.length,
                "red_apples": game_handler.apples_red,
                "green_apples": game_handler.apples_green,
            }
        )

        if game_handler.game_over or game_handler.has_won:
            messagebox.showinfo(
                title="Game Over",
                message="You won!" if game_handler.has_won else "You lost!",
                icon=messagebox.INFO,
                parent=root,
            )
            root.frames["game"].stop_tick()
            root.frames["game"].toggle_pause()
            root.destroy_frame("game")
            render_landing(
                root,
                render_game_mode=render_game_mode,
                render_train_mode=render_train_mode,
                render_train_settings=render_train_settings,
            )
            return

    root.frames["game"].tick(on_tick)
