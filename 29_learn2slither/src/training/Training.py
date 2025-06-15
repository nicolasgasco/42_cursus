import json
from random import random

import schedule as schedule

from constants import (
    EXPLORATION_RATE_DECAY,
    EXPLORATION_RATE_MAX,
    EXPLORATION_RATE_MIN,
    BoardBlockSymbol,
    SnakeDirection,
)

# TODO move to constants file
REWARDS = {
    BoardBlockSymbol.EMPTY.value: -10,
    BoardBlockSymbol.BODY.value: -1000,
    BoardBlockSymbol.GREEN_APPLE.value: 500,
    BoardBlockSymbol.RED_APPLE.value: -250,
    BoardBlockSymbol.WALL.value: -1000,
}


class Training:
    def __init__(self):
        self.__q_table = self.__init_q_table()
        self.__learning_rate = 0.05
        self.__discount_factor = 0.98
        self.__exploration_rate = (
            EXPLORATION_RATE_MAX
            if len(self.__q_table) == 0
            else EXPLORATION_RATE_MIN
        )

        self.__directions = [
            SnakeDirection.UP.value,
            SnakeDirection.RIGHT.value,
            SnakeDirection.DOWN.value,
            SnakeDirection.LEFT.value,
        ]

        schedule.every(30).seconds.do(self.__save_q_table_to_file)

    def __init_q_table(self) -> None:
        q_table = {}
        try:
            with open("q_table.json", "r", encoding="utf-8") as file:
                entries = json.load(file)

            for entry in entries:
                state = entry["state"]
                actions = entry["actions"]
                q_table[state] = {
                    SnakeDirection.UP.value: actions[0],
                    SnakeDirection.RIGHT.value: actions[1],
                    SnakeDirection.DOWN.value: actions[2],
                    SnakeDirection.LEFT.value: actions[3],
                }

            return q_table
        except FileNotFoundError:
            return q_table

    def simplify_context(self, context: dict) -> dict:
        context_props = context.keys()

        direction_props = []
        for prop in context_props:
            blocks = []
            for i, block in enumerate(context[prop]):
                if str(block["block"]) == BoardBlockSymbol.EMPTY.value:
                    continue

                is_wall = str(block["block"]) == BoardBlockSymbol.WALL.value
                is_preceded_by_empty = (
                    str(context[prop][i - 1]["block"])
                    == BoardBlockSymbol.EMPTY.value
                )
                if i > 0 and is_wall and is_preceded_by_empty:
                    blocks.append(BoardBlockSymbol.EMPTY.value)

                blocks.append(str(block["block"]))

            direction_props.append(tuple(dict.fromkeys(blocks)))

        return tuple(direction_props)

    def __is_random_action(self) -> bool:
        is_random_action = random() < self.__exploration_rate

        self.__exploration_rate = max(
            EXPLORATION_RATE_MIN,
            self.__exploration_rate - EXPLORATION_RATE_DECAY,
        )

        return is_random_action

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

    def pick_next_move(self, context: dict) -> SnakeDirection:
        self.__next_move = None

        simplified_context = self.simplify_context(context)

        if simplified_context not in self.__q_table:
            self.__q_table[simplified_context] = {
                direction: 0 for direction in self.__directions
            }

        is_random_action = self.__is_random_action()
        random_index = int(random() * len(self.__directions))

        if is_random_action:
            return self.__directions[random_index]

        if simplified_context in self.__q_table:
            return self.__pick_highest_q_value_action(simplified_context)

        self.__next_move = self.__directions[random_index]
        return self.__next_move

    # TODO improve this
    def __save_q_table_to_file(self) -> None:
        print("Saving Q-table to file...")

        entries = []
        for state, actions in self.__q_table.items():
            entries.append(
                {
                    "state": str(state),
                    "actions": [q_value for q_value in actions.values()],
                }
            )

        with open("q_table.json", "w", encoding="utf-8") as file:
            json.dump(entries, file, indent=2, ensure_ascii=False)

    def train(
        self,
        new_block: str,
        prev_context: dict,
        context: dict,
        move: str,
        current_episode: int,
    ) -> None:
        prev_context = self.simplify_context(prev_context)

        context = self.simplify_context(context)
        if context not in self.__q_table:
            self.__q_table[context] = {
                direction: 0 for direction in self.__directions
            }

        reward = REWARDS.get(new_block, 0)
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
