import numpy as numpy
import sys as sys


def slice_me(family: list, start: int, end: int) -> list:

    try:
        assert isinstance(family, list), "family is not a list"
        assert isinstance(start, int), "start is not an integer"
        assert isinstance(end, int), "end is not an integer"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)

    new_family = numpy.array(family)

    print(f"My shape is : {numpy.shape(new_family)}")

    try:
        new_family = new_family[start:end]
    except IndexError:
        print("New shape is not valid")
        sys.exit(1)

    print(
        f"My new shape is : {numpy.shape(new_family)}")

    return new_family.tolist()
