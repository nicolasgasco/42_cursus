import sys as sys
from ft_filter import ft_filter


def main():
    try:
        assert len(sys.argv) == 3, "provide exactly two arguments"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)

    try:
        assert isinstance(sys.argv[1], str), "first argument is not a string"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)

    try:
        int(sys.argv[2])
    except ValueError:
        print("AssertionError: second argument is not an integer")
        sys.exit(1)

    string_value = sys.argv[1]
    int_value = int(sys.argv[2])

    tokenized_string = string_value.split()

    res = [
        x for x in ft_filter(lambda x: (len(x) > int_value), tokenized_string)
    ]

    print(res)


if __name__ == "__main__":
    main()
