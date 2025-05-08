from constants import SnakeDirection


def is_opposite_direction(
    direction: SnakeDirection, prev_direction: SnakeDirection
) -> bool:
    return (
        (
            direction == SnakeDirection.UP.value
            and prev_direction == SnakeDirection.DOWN.value
        )
        or (
            direction == SnakeDirection.DOWN.value
            and prev_direction == SnakeDirection.UP.value
        )
        or (
            direction == SnakeDirection.LEFT.value
            and prev_direction == SnakeDirection.RIGHT.value
        )
        or (
            direction == SnakeDirection.RIGHT.value
            and prev_direction == SnakeDirection.LEFT.value
        )
    )
