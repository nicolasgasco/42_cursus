import json
import time as time
from random import random

import schedule as schedule

from constants import (
    EXPLORATION_RATE_DECAY,
    EXPLORATION_RATE_MAX,
    EXPLORATION_RATE_MIN,
    REWARDS,
    BoardBlockSymbol,
    SnakeDirection,
)
from settings_parser import SettingsParser


class Training:
    def __init__(self):
        self.__existing_model = SettingsParser("train").settings[
            "existing_model"
        ]

        training_data = (
            self.__import_training_data(self.__existing_model)
            if self.__existing_model
            else {}
        )

        self.__prev_episodes = training_data.get("episodes", None)
        self.__q_table = training_data.get("q_table", {})
        self.__learning_rate = training_data.get("learning_rate", 0.05)
        self.__discount_factor = training_data.get("discount_factor", 0.98)
        self.__exploration_rate = training_data.get(
            "exploration_rate", EXPLORATION_RATE_MAX
        )

        self.__directions = [
            SnakeDirection.UP.value,
            SnakeDirection.RIGHT.value,
            SnakeDirection.DOWN.value,
            SnakeDirection.LEFT.value,
        ]

        schedule.every(15).seconds.do(self.save_training_data_to_file)

    @property
    def learning_rate(self) -> float:
        return self.__learning_rate

    @property
    def discount_factor(self) -> float:
        return self.__discount_factor

    @property
    def exploration_rate(self) -> float:
        return self.__exploration_rate

    @property
    def q_table_entries(self) -> int:
        return len(self.__q_table)

    def __import_training_data(self, model_id: str | None) -> None:
        training_data = {}
        # TODO change name to timestamp
        try:
            filename = f"{model_id}.json"
            path = "../models/" + filename
            with open(path, "r", encoding="utf-8") as file:
                body = json.load(file)

            training_data["episodes"] = body.get("episodes", None)
            training_data["learning_rate"] = body.get("learning_rate", None)
            training_data["discount_factor"] = body.get(
                "discount_factor", None
            )
            training_data["exploration_rate"] = body.get(
                "exploration_rate", None
            )
            training_data["q_table"] = {}
            for entry in body["entries"]:
                state = tuple(tuple(state) for state in entry["state"])
                actions = entry["actions"]

                training_data["q_table"][state] = {
                    SnakeDirection.UP.value: actions[0],
                    SnakeDirection.RIGHT.value: actions[1],
                    SnakeDirection.DOWN.value: actions[2],
                    SnakeDirection.LEFT.value: actions[3],
                }

            print(f"Training data imported from {filename}")
            return training_data
        except FileNotFoundError:
            return training_data

    def simplify_context(self, context: dict) -> dict:
        context_props = context.keys()

        direction_props = []
        for prop in context_props:
            blocks = []
            for i, block in enumerate(context[prop]):
                if str(block["block"]) == BoardBlockSymbol.EMPTY.value:
                    continue

                is_fatal_block = (
                    str(block["block"]) == BoardBlockSymbol.WALL.value
                    or str(block["block"]) == BoardBlockSymbol.BODY.value
                )
                is_preceded_by_empty = (
                    str(context[prop][i - 1]["block"])
                    == BoardBlockSymbol.EMPTY.value
                )
                if i > 0 and is_fatal_block and is_preceded_by_empty:
                    blocks.append(BoardBlockSymbol.EMPTY.value)

                blocks.append(str(block["block"]))

            direction_props.append(tuple(dict.fromkeys(blocks)))

        return tuple(direction_props)

    def __is_exploration_action(self) -> bool:
        is_exploration_action = random() < self.__exploration_rate

        self.__exploration_rate = max(
            EXPLORATION_RATE_MIN,
            self.__exploration_rate - EXPLORATION_RATE_DECAY,
        )

        return is_exploration_action

    def __pick_highest_q_value_action(
        self, simplified_context: dict
    ) -> SnakeDirection:
        q_values = self.__q_table[simplified_context]
        max_q_value = max(q_values.values())

        best_actions = [
            direction
            for direction, q_value in q_values.items()
            if q_value == max_q_value
        ]
        best_action = best_actions[int(random() * len(best_actions))]

        return best_action

    def pick_next_move(
        self, context: dict, benchmark_mode: bool
    ) -> SnakeDirection:
        self.__next_move = None

        simplified_context = self.simplify_context(context)

        is_known_context = simplified_context in self.__q_table
        if not is_known_context and not benchmark_mode:
            self.__q_table[simplified_context] = {
                direction: 0 for direction in self.__directions
            }

        random_index = int(random() * len(self.__directions))

        is_exploration_action = self.__is_exploration_action()
        if is_exploration_action:
            return self.__directions[random_index]

        if is_known_context:
            return self.__pick_highest_q_value_action(simplified_context)

        self.__next_move = self.__directions[random_index]
        return self.__next_move

    # TODO improve this
    def save_training_data_to_file(self, episodes=None) -> None:
        print("Saving Q-table to file...")

        entries = []
        for state, actions in self.__q_table.items():
            entries.append(
                {
                    "state": state,
                    "actions": [q_value for q_value in actions.values()],
                }
            )

        prev_episodes = self.__prev_episodes or 0
        episodes = episodes or 0
        body = {
            "episodes": prev_episodes + episodes,
            "learning_rate": self.__learning_rate,
            "discount_factor": self.__discount_factor,
            "exploration_rate": self.__exploration_rate,
            "entries": entries,
        }

        if self.__existing_model:
            filename = f"{self.__existing_model}.json"
        else:
            timestamp = int(time.time())
            filename = f"{timestamp}.json"
            self.__existing_model = timestamp

        path = "../models/" + filename
        with open(path, "w", encoding="utf-8") as file:
            json.dump(body, file, indent=2, ensure_ascii=False)

    def __calc_reward(
        self, new_block: str, prev_context: dict, move: str
    ) -> int:
        DIRECTION_INDEX = {
            SnakeDirection.UP.value: 0,
            SnakeDirection.RIGHT.value: 1,
            SnakeDirection.DOWN.value: 2,
            SnakeDirection.LEFT.value: 3,
        }

        if new_block == BoardBlockSymbol.EMPTY.value:
            index = DIRECTION_INDEX[move]
            direction_context = prev_context[index]

            if BoardBlockSymbol.RED_APPLE.value in direction_context:
                return -100
            if BoardBlockSymbol.GREEN_APPLE.value in direction_context:
                return 250
            if BoardBlockSymbol.WALL.value in direction_context:
                return -10
            if BoardBlockSymbol.BODY.value in direction_context:
                return -10

        return REWARDS.get(new_block, 0)

    def train(
        self,
        new_block: str,
        prev_context: dict,
        context: dict,
        move: str,
    ) -> None:
        prev_context = self.simplify_context(prev_context)

        context = self.simplify_context(context)
        if context not in self.__q_table:
            self.__q_table[context] = {
                direction: 0 for direction in self.__directions
            }

        reward = self.__calc_reward(new_block, prev_context, move)
        prev_q_value = self.__q_table[prev_context][move]
        best_action = self.__pick_highest_q_value_action(context)
        q_value_best_action = self.__q_table[context][best_action]

        temp_diff_error = (
            reward
            + self.__discount_factor * q_value_best_action
            - prev_q_value
        )
        new_q_value = prev_q_value + self.__learning_rate * temp_diff_error

        self.__q_table[prev_context][move] = new_q_value

        schedule.run_pending()
