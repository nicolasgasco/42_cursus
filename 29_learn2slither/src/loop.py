import sys as sys
import time as t

from agent import Agent, TrainStats
from constants import DEFAULT_SNAKE_DIRECTION, INTERACTIVE_ACTION
from game_logic import Game
from gui import Board, ContextData, Controls, GameData, Root, TrainData
from map import MapGenerator
from settings_parser import SettingsParser


def init_interface(root: Root, agent: Agent):
    map_generator = MapGenerator()
    map_generator.generate_map()

    root.board = Board(root, {"map": map_generator.map})

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

    root.context_data = ContextData(
        root,
        {
            "context": agent.context,
            "head_pos": game_handler.head_pos,
        },
    )

    return game_handler


def destroy_interface(root: Root):
    if root.board:
        root.board.destroy()
    if root.game_data:
        root.game_data.destroy()
    if root.context_data:
        root.context_data.destroy()


def main():
    start = t.time()

    args = sys.argv[1:] if len(sys.argv) > 1 else []
    is_game_mode = args[0] == "--play" if args else False
    is_interactive_mode = args[0] == "--interactive" if args else False

    train_settings = SettingsParser("train").settings
    max_episodes = train_settings["max_episodes"]

    agent = Agent()
    agent.training_stats = TrainStats()

    root = Root()
    root.controls = Controls(root)

    root.train_data = TrainData(
        root,
        {
            "games_played": agent.training_stats.games_lost
            + agent.training_stats.games_won,
            "games_won": agent.training_stats.games_won,
            "games_lost": agent.training_stats.games_lost,
            "elapsed_time": (t.time() - start).__round__(1),
        },
    )

    intended_direction = DEFAULT_SNAKE_DIRECTION
    prev_direction = DEFAULT_SNAKE_DIRECTION

    game_handler = init_interface(root, agent)

    if is_game_mode:

        def on_key_press(_, direction):
            nonlocal intended_direction
            intended_direction = direction

        root.bind_movement_keys(on_key_press)

    elif is_interactive_mode:

        def on_key_press(_, direction):
            if direction == INTERACTIVE_ACTION.FORWARD:
                on_tick()
            elif direction == INTERACTIVE_ACTION.BACKWARD:
                game_handler.move_snake(prev_direction)

        root.bind_training_keys(on_key_press)

    def on_tick():
        nonlocal prev_direction
        nonlocal intended_direction
        nonlocal game_handler

        current_episode = (
            agent.training_stats.games_lost + agent.training_stats.games_won
        )
        if current_episode >= max_episodes:
            print("Training completed.")
            root.quit()
            return

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

        agent.update_context(
            {
                "map": root.board.raw_map,
                "head_pos": game_handler.head_pos,
            }
        )
        root.context_data.update_data(
            {
                "context": agent.context,
                "head_pos": game_handler.head_pos,
            }
        )

        if game_handler.game_over or game_handler.has_won:
            if game_handler.has_won:
                print("Game won!")
                agent.training_stats.games_won += 1
            else:
                print("Game Over :(")
                agent.training_stats.games_lost += 1

            if is_game_mode:
                root.quit()
                return

            root.train_data.update_data(
                {
                    "games_played": agent.training_stats.games_lost
                    + agent.training_stats.games_won,
                    "games_won": agent.training_stats.games_won,
                    "games_lost": agent.training_stats.games_lost,
                    "elapsed_time": (t.time() - start).__round__(1),
                }
            )

            intended_direction = DEFAULT_SNAKE_DIRECTION
            prev_direction = DEFAULT_SNAKE_DIRECTION

            destroy_interface(root)
            game_handler = init_interface(root, agent)

            return

        root.board.fill(game_handler.blocks_to_update)

    if not is_interactive_mode:
        root.tick(on_tick)
    root.mainloop()


if __name__ == "__main__":
    main()
