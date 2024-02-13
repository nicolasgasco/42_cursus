def ft_filter(function, iterable):
    """ Return an iterator yielding those items of iterable
    for which function(item) is true.
    If function is None, return the items that are true."""

    assert (callable(function)
            or function is None), "function is not callable or is None"

    assert (iterable is not None), "iterable is None"
    assert (hasattr(iterable, "__iter__")), "iterable is not iterable"

    if (function is None):
        return iter([i for i in iterable if bool(i) is True])

    return iter([i for i in iterable if function(i) is True])
