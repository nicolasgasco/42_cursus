from typing import Any


def _print_mean(values: list[int]) -> None:
    try:
        mean = sum(values) / len(values)
        print(f"mean : {mean}")
    except ZeroDivisionError:
        print("ERROR")


def _print_median(values: list[int]) -> None:
    try:
        ordered_values = sorted(values)

        result = 0
        if (len(ordered_values) % 2 == 0):
            left_value = ordered_values[len(ordered_values) // 2 - 1]
            right_value = ordered_values[len(ordered_values) // 2]
            result = (left_value + right_value) / 2
        else:
            result = ordered_values[len(ordered_values) // 2]
        print("median :", result)
    except ZeroDivisionError:
        print("ERROR")
    except IndexError:
        print("ERROR")


def _print_quartile(values: list[int]) -> None:
    try:
        ordered_values = sorted(values)

        lower_quartile = float(ordered_values[len(values) // 4])
        upper_quartile = float(ordered_values[len(values) * 3 // 4])
        print(f"quartile : {[lower_quartile, upper_quartile]}")
    except ZeroDivisionError:
        print("ERROR")
    except IndexError:
        print("ERROR")


def _print_std(values: list[int]) -> None:
    try:
        mean = sum(values) / len(values)
        variance = sum([((x - mean) ** 2) for x in values]) / len(values)
        standard_deviation = variance ** 0.5
        print(f"std : {standard_deviation}")
    except ZeroDivisionError:
        print("ERROR")
    except IndexError:
        print("ERROR")


def _print_var(values: list[int]) -> None:
    try:
        mean = sum(values) / len(values)
        variance = sum([((x - mean) ** 2) for x in values]) / len(values)
        print(f"var : {variance}")
    except ZeroDivisionError:
        print("ERROR")
    except IndexError:
        print("ERROR")


def ft_statistics(*args: Any, **kwargs: Any) -> None:
    values = list(args)

    operations = [op for op in kwargs.values()]

    for operation in operations:
        if operation == "mean":
            _print_mean(values)
        elif operation == "median":
            _print_median(values)
        elif operation == "quartile":
            _print_quartile(values)
        elif operation == "std":
            _print_std(values)
        elif operation == "var":
            _print_var(values)
        else:
            pass
