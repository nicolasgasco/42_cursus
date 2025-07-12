from constants import BoardBlockSymbol, SnakeDirection


class INTERACTIVE_ACTION:
    FORWARD = "FORWARD"
    BACKWARD = "BACKWARD"


DEFAULT_EXISTING_MODEL = "Start anew"
DEFAULT_MAX_EPISODES = 1_000
EXPLORATION_RATE_DECAY = 0.001
EXPLORATION_RATE_MIN = 0.01
EXPLORATION_RATE_MAX = 1.0

REWARDS = {
    BoardBlockSymbol.EMPTY.value: -1,
    BoardBlockSymbol.BODY.value: -1000,
    BoardBlockSymbol.GREEN_APPLE.value: 500,
    BoardBlockSymbol.RED_APPLE.value: -250,
    BoardBlockSymbol.WALL.value: -1000,
}

DIRECTIONS = [
    SnakeDirection.UP.value,
    SnakeDirection.RIGHT.value,
    SnakeDirection.DOWN.value,
    SnakeDirection.LEFT.value,
]

DIRECTION_SYMBOLS = {
    SnakeDirection.UP.value: "⬆️",
    SnakeDirection.RIGHT.value: "➡️",
    SnakeDirection.DOWN.value: "⬇️",
    SnakeDirection.LEFT.value: "⬅️",
}
