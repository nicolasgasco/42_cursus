import os as os
import numpy as np


def print_output(*args, **kwargs) -> None:
    """
    Prints the given arguments
    if the environment variable 'PRINT_OUTPUT' is set to '1'.

    Args:
      *args: Variable number of arguments to be printed.

    Returns:
      None
    """

    should_print = os.getenv("PRINT_OUTPUT") == "1"

    if should_print:
        print(*args, **kwargs)


def rand_small_float() -> float:
    """
    Generate a random small float number.

    Returns:
      float: A random small float number.
    """

    num: float = np.random.randn() * 0.01

    return num
