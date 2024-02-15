def ft_filter(function, iterable):
    """
    Filters the elements of an iterable based on a given function.

    Args:
        function: A function that takes an element from the iterable as input
        and returns a boolean value.
        iterable: An iterable object containing the elements to be filtered.

    Returns:
        An iterator containing the filtered elements.

    Raises:
        AssertionError: If the function is not callable or is None.
        AssertionError: If the iterable is None or not iterable.
    """

    try:
        assert (callable(function)
                or function is None), "function is not callable or is None"

        assert (iterable is not None), "iterable is None"
        assert (hasattr(iterable, "__iter__")), "iterable is not iterable"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        return None

    if (function is None):
        return iter([i for i in iterable if bool(i) is True])

    return iter([i for i in iterable if function(i) is True])
