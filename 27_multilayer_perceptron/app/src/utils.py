import os as os
import numpy as np


def print_output(args):
    should_print = os.getenv("PRINT_OUTPUT") == "1"

    if (should_print):
        print(args)


def rand_small_float() -> float:
    num: float = np.random.randn() * 0.1
    return num
