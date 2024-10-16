import numpy as np
import os as os


def print_output(*args, **kwargs) -> None:
    """
    Prints the given arguments
    if the environment variable PRINT_OUTPUT is set to 1.

    Args:
      *args: Variable length argument list.
      **kwargs: Arbitrary keyword arguments.

    Returns:
      None
    """

    should_print = os.getenv("PRINT_OUTPUT") == "1"

    if should_print:
        for arg in args:
            if isinstance(arg, np.ndarray):
                np.set_printoptions(precision=6, suppress=True)
                for index, element in enumerate(arg):
                    print(f"{index}: {element}")
            else:
                print(arg)
