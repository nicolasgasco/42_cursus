import time as t

from agent import Agent, TrainStats
from constants import DEFAULT_SNAKE_DIRECTION, INTERACTIVE_ACTION
from game_logic import Game
from gui import (
    Board,
    ContextData,
    Controls,
    GameData,
    Root,
    TrainData,
    TrainPage,
)
from map import MapGenerator
from settings_parser import SettingsParser


def init_interface(root: Root, agent: Agent):
    map_generator = MapGenerator()
    map_generator.generate_map()

    root.frames["train"].board = Board(root, map=map_generator.map)

    game_handler = Game(root.frames["train"].board.raw_map)

    root.frames["train"].game_data = GameData(
        root,
        {
            "moves": game_handler.moves,
            "length": game_handler.length,
            "red_apples": game_handler.apples_red,
            "green_apples": game_handler.apples_green,
        },
    )

    agent.update_context(
        {
            "map": root.frames["train"].board.raw_map,
            "head_pos": game_handler.head_pos,
        }
    )

    root.frames["train"].context_data = ContextData(root)
    root.frames["train"].context_data.update_data(
        {
            "context": agent.context,
            "head_pos": game_handler.head_pos,
        },
    )

    return game_handler


def destroy_interface(root: Root):
    if root.frames["train"].board:
        root.frames["train"].board.destroy()
    if root.frames["train"].game_data:
        root.frames["train"].game_data.destroy()
    if root.frames["train"].context_data:
        root.frames["train"].context_data.destroy()


def render_train_mode(root: Root):
    root.frames["train"] = TrainPage(root)
    root.frames["train"].grid(row=0, column=0, sticky="nsew")

    start = t.time()

    train_settings = SettingsParser("train").settings
    interactive_mode = train_settings["interactive_mode"]
    max_episodes = train_settings["max_episodes"]

    agent = Agent()
    agent.training_stats = TrainStats()

    root.frames["train"].controls = Controls(root)

    root.frames["train"].train_data = TrainData(
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

    if interactive_mode:

        def on_key_press(_, direction):
            if direction == INTERACTIVE_ACTION.FORWARD:
                on_tick()
            elif direction == INTERACTIVE_ACTION.BACKWARD:
                game_handler.move_snake(prev_direction)

        root.frames["train"].bind_training_keys(on_key_press)

    root.frames["train"].bind_pause_key()

    def on_tick():
        nonlocal prev_direction
        nonlocal intended_direction
        nonlocal game_handler

        current_episode = (
            agent.training_stats.games_lost + agent.training_stats.games_won
        )

        if current_episode >= max_episodes:
            agent.save_q_table_to_file()
            print("Training completed.")
            root.quit()
            return

        intended_direction = agent.pick_next_move()
        replaced_block = game_handler.move_snake(intended_direction)

        if game_handler.has_moved:
            prev_direction = intended_direction
        elif not game_handler.game_over:
            game_handler.move_snake(prev_direction)

        prev_context = agent.context.copy()
        agent.update_context(
            {
                "map": root.frames["train"].board.raw_map,
                "head_pos": game_handler.head_pos,
            }
        )

        agent.train(replaced_block, prev_context, intended_direction)

        root.frames["train"].game_data.update_data(
            {
                "moves": game_handler.moves,
                "length": game_handler.length,
                "red_apples": game_handler.apples_red,
                "green_apples": game_handler.apples_green,
            }
        )

        root.frames["train"].context_data.update_data(
            {
                "context": agent.context,
                "head_pos": game_handler.head_pos,
            }
        )

        if game_handler.game_over or game_handler.has_won:
            if game_handler.has_won:
                print("✅ Game won")
                agent.training_stats.games_won += 1
            else:
                print("❌ Game Over")
                agent.training_stats.games_lost += 1

            root.frames["train"].train_data.update_data(
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

        root.frames["train"].board.fill(
            game_handler.blocks_to_update, game_handler.length
        )

    if not interactive_mode:
        root.frames["train"].tick(on_tick)
