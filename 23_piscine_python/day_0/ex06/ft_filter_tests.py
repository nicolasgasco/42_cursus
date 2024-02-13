from ft_filter import ft_filter


def ft_filter_assertion(func, values):
    """
    Compare the output of the built-in filter function
    and the custom ft_filter function.
    """

    print(f"- When function is {func} and iterable is {values}")

    res_original = filter(func, values)
    print(f"\tfilter: {list(res_original)}")

    res = ft_filter(func, values)
    print(f"\tft_filter: {list(res)}")

    if list(res_original) == list(res):
        print("\t✅ Check OK ")
    else:
        print("\t❌ Check Fail")

    print("")


def filter_lowercase(c):
    """
    Filters a character based on whether it is lowercase or not.
    """

    return c.islower()


def filter_even(n):
    """
    Check if a number is even.
    """

    try:
        return n % 2 == 0
    except TypeError:
        return False


def main():
    """
    This is the main function that demonstrates
    the usage of the ft_filter_assertion function.
    It calls the ft_filter_assertion function
    with different functions and values to test the filtering functionality.
    """

    func = None
    values = [0, 1, 2, 3, '0', '1', '2', '3', 0.0, 1.0, 2.0, 3.0, False, True]
    ft_filter_assertion(func, values)

    func = filter_lowercase
    values = "Hello World!"
    ft_filter_assertion(func, values)

    func = filter_even
    values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, "0", "1",
              "2", 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, True, False]
    ft_filter_assertion(func, values)

    values = (7, 20)
    ft_filter_assertion(lambda x: (x % 2 != 0), values)

    values = (None, False, True, 0, "0", 0.0, "0.0", "",
              " ", "False", "True", "None", {}, [], ())
    ft_filter_assertion(lambda x: (bool(x) is False), values)


if __name__ == "__main__":
    main()
