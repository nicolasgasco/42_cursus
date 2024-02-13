import sys
from ft_filter import ft_filter


def main():
    assert len(sys.argv) == 3, "provide exactly two arguments"

    assert isinstance(sys.argv[1], str), "first argument is not a string"

    string_value = sys.argv[1]
    int_value = int(sys.argv[2])

    try:
        int(sys.argv[2])
    except ValueError:
        raise AssertionError(
            "second argument is not an integer")

    tokenized_string = string_value.split()

    res = [
        x for x in ft_filter(lambda x: (len(x) > int_value), tokenized_string)
    ]

    print("Original string: ", string_value)
    print("Word length: ", int_value)
    print(res)


if __name__ == "__main__":
    main()
