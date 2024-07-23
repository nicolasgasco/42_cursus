import os as os


def print_output(args):
    should_print = os.getenv("PRINT_OUTPUT") == "1"

    if (should_print):
        print(args)
