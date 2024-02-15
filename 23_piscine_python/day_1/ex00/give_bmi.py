import sys as sys
import numpy as numpy


def _calc_bmi(weight: float | int, height: float | int):
    """Calculate the Body Mass Index (BMI) using the given weight and height.

    Args:
        weight (float | int): The weight of the person in kilograms or pounds.
        height (float | int): The height of the person in meters or inches.

    Returns:
        float: The calculated BMI value.
    """

    height_square = numpy.square([height])[0]
    return weight / height_square


def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """
    Calculate the Body Mass Index (BMI) for each pair of height and weight.

    Args:
        height (list[int | float]): A list of heights.
        weight (list[int | float]): A list of weights.

    Returns:
        list[int | float]: A list of BMIs corresponding
        to each pair of height and weight.

    Raises:
        AssertionError: If the length of the height
        and weight lists are not equal.
        AssertionError: If the height
        or weight lists contain non-numeric values.
    """

    len_height = len(height)
    len_weight = len(weight)

    try:
        assert len_height == len_weight, "height and weight lists not equal"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)

    height_list = list(filter(lambda x: isinstance(x, (int, float)), height))
    weight_list = list(filter(lambda x: isinstance(x, (int, float)), weight))

    try:
        assert len(height_list) == len(
            height), "height list contains non-numeric values"
        assert len(weight_list) == len(
            weight), "weight list contains non-numeric values"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)

    return [_calc_bmi(weight_list[i], height_list[i])
            for i in range(len_height)]


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """
    Apply a limit to each BMI value in the given list and return a list of booleans indicating whether each BMI value is greater than the limit.

    Args:
        bmi (list[int | float]): The list of BMI values.
        limit (int): The limit to apply to each BMI value.

    Returns:
        list[bool]: A list of booleans indicating whether each BMI value is greater than the limit.
    """
    return [i > limit for i in bmi]
    pass
