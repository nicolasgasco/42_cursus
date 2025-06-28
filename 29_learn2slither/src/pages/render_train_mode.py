import time as t

from agent import Agent, TrainStats
from constants import (
    DEFAULT_SNAKE_DIRECTION,
    DEFAULT_SPEED,
    INTERACTIVE_ACTION,
    MAX_SPEED,
)
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


def init_interface(root: Root, agent: Agent, is_max_speed: bool = False):
    map_generator = MapGenerator()
    map_generator.generate_map()

    root.frames["train"].board = Board(
        root, map=map_generator.map, should_fill=(not is_max_speed)
    )

    game_handler = Game(root.frames["train"].board.raw_map)

    root.frames["train"].game_data = GameData(
        root,
        moves=game_handler.moves,
        length=game_handler.length,
        red_apples=game_handler.apples_red,
        green_apples=game_handler.apples_green,
    )

    agent.update_context(
        map=root.frames["train"].board.raw_map,
        head_pos=game_handler.head_pos,
    )

    root.frames["train"].context_data = ContextData(root)

    if not is_max_speed:
        root.frames["train"].context_data.update_data(
            context=agent.context,
            head_pos=game_handler.head_pos,
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
    interactive_mode = bool(train_settings["interactive_mode"])
    benchmark_mode = bool(train_settings["benchmark_mode"])
    max_episodes = train_settings["max_episodes"]

    agent = Agent()
    agent.training_stats = TrainStats()

    root.frames["train"].controls = Controls(root)

    root.frames["train"].train_data = TrainData(
        root,
        games_played=agent.training_stats.games_lost
        + agent.training_stats.games_won,
        max_games=max_episodes,
        games_won=agent.training_stats.games_won,
        games_lost=agent.training_stats.games_lost,
        elapsed_time=(t.time() - start),
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

        speed = (
            root.frames["train"].controls.speed.get()
            if not interactive_mode
            else DEFAULT_SPEED
        )
        is_max_speed = int(speed) == int(MAX_SPEED)

        if game_handler.game_over or game_handler.has_won:
            if game_handler.has_won:
                print("✅ Game won")
                agent.training_stats.games_won += 1
            else:
                print("❌ Game Over")
                agent.training_stats.games_lost += 1

            root.frames["train"].train_data.update_data(
                games_played=agent.training_stats.games_lost
                + agent.training_stats.games_won,
                games_won=agent.training_stats.games_won,
                games_lost=agent.training_stats.games_lost,
                elapsed_time=(t.time() - start),
            )

            intended_direction = DEFAULT_SNAKE_DIRECTION
            prev_direction = DEFAULT_SNAKE_DIRECTION

            destroy_interface(root)
            game_handler = init_interface(root, agent, is_max_speed)

            return

        current_episode = (
            agent.training_stats.games_lost + agent.training_stats.games_won
        )

        if current_episode >= max_episodes:
            if not benchmark_mode:
                agent.save_training_data_to_file(current_episode)
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
            map=root.frames["train"].board.raw_map,
            head_pos=game_handler.head_pos,
        )

        if not benchmark_mode:
            agent.train(
                replaced_block,
                prev_context,
                intended_direction,
            )

        if not is_max_speed:
            root.frames["train"].game_data.update_data(
                moves=game_handler.moves,
                length=game_handler.length,
                red_apples=game_handler.apples_red,
                green_apples=game_handler.apples_green,
            )

            root.frames["train"].context_data.update_data(
                context=agent.context,
                head_pos=game_handler.head_pos,
            )

            root.frames["train"].board.fill(
                game_handler.blocks_to_update, game_handler.length
            )

    if not interactive_mode:
        root.frames["train"].tick(on_tick)
