from constants import BoardBlockSymbol


class INTERACTIVE_ACTION:
    FORWARD = "FORWARD"
    BACKWARD = "BACKWARD"


DEFAULT_MAX_EPISODES = 1_000
EXPLORATION_RATE_DECAY = 0.001
EXPLORATION_RATE_MIN = 0.02
EXPLORATION_RATE_MAX = 1.0

REWARDS = {
    BoardBlockSymbol.EMPTY.value: -10,
    BoardBlockSymbol.BODY.value: -1000,
    BoardBlockSymbol.GREEN_APPLE.value: 500,
    BoardBlockSymbol.RED_APPLE.value: -250,
    BoardBlockSymbol.WALL.value: -1000,
}
