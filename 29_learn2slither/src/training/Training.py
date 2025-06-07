from constants import SnakeDirection
from random import random

EXPLORATION_RATE_DECAY = 0.001
EXPLORATION_RATE_MIN = 0.1


class Training:
    def __init__(self):
        self.__q_table = {}
        self.__learning_rate = 0.1
        self.__discount_factor = 0.9
        self.__exploration_rate = 1.0

        self.__directions = [
            SnakeDirection.UP.value,
            SnakeDirection.RIGHT.value,
            SnakeDirection.DOWN.value,
            SnakeDirection.LEFT.value,
        ]

    def __simplify_context(self, context: dict) -> dict:
        context_props = context.keys()

        direction_props = []
        for prop in context_props:
            blocks = [
                str(block["block"])
                for block in context[prop]
                if str(block["block"]) != "⬛"
            ]
            direction_props.append(tuple(blocks))

        return tuple(direction_props)

    def __is_random_action(self) -> bool:
        is_random_action = random() < self.__exploration_rate

        self.__exploration_rate = max(
            0.1,
            self.__exploration_rate - EXPLORATION_RATE_DECAY,
        )

        return is_random_action

    def pick_next_move(self, context: dict) -> SnakeDirection:
        simplified_context = self.__simplify_context(context)

        is_random_action = self.__is_random_action()
        random_index = int(random() * len(self.__directions))

        if is_random_action:
            print("Picking a random action (exploration)...")
            return self.__directions[random_index]

        print("Picking the best action (exploitation)...")
        if simplified_context in self.__q_table:
            print("Context found in Q-table.")
            return SnakeDirection.UP.value

        print("Context not found in Q-table")
        self.__q_table[simplified_context] = {
            direction: 0 for direction in self.__directions
        }
        return self.__directions[random_index]
