from random import random
import json

from constants import (
    SnakeDirection,
    EXPLORATION_RATE_DECAY,
    EXPLORATION_RATE_MIN,
    BoardBlockSymbol,
)

# TODO move to constants file
REWARDS = {
    BoardBlockSymbol.EMPTY.value: -1,
    BoardBlockSymbol.BODY.value: -200,
    BoardBlockSymbol.GREEN_APPLE.value: 50,
    BoardBlockSymbol.RED_APPLE.value: -10,
    BoardBlockSymbol.WALL.value: -200,
}


class Training:
    def __init__(self):
        self.__q_table = {}
        self.__learning_rate = 0.1
        self.__discount_factor = 0.99
        self.__exploration_rate = 1.0

        self.__directions = [
            SnakeDirection.UP.value,
            SnakeDirection.RIGHT.value,
            SnakeDirection.DOWN.value,
            SnakeDirection.LEFT.value,
        ]

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
            print("Picking a random action (exploration)...")
            return self.__directions[random_index]

        print("Picking the best action (exploitation)...")
        if simplified_context in self.__q_table:
            print("Context found in Q-table.")
            return self.__pick_highest_q_value_action(simplified_context)

        print("Context not found in Q-table")

        self.__next_move = self.__directions[random_index]
        return self.__next_move

    # TODO improve this
    def __save_q_table_to_file(self) -> None:
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
        self, new_block: str, prev_context: dict, context: dict, move: str
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
        # TODO review this
        new_q_value = prev_q_value + self.__learning_rate * temp_diff_error

        self.__q_table[prev_context][move] = new_q_value

        self.__save_q_table_to_file()
