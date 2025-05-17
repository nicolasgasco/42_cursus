from enum import Enum


class SnakeDirection(Enum):
    UP = "UP"
    DOWN = "DOWN"
    LEFT = "LEFT"
    RIGHT = "RIGHT"


DEFAULT_SNAKE_DIRECTION = SnakeDirection.LEFT.value

DEFAULT_SPEED = "10"
