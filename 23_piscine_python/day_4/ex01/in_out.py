def square(x: int | float) -> int | float:
    return x * x


def pow(x: int | float) -> int | float:
    return x ** x


def outer(x: int | float, function) -> object:
    def inner() -> float:
        nonlocal x
        result = function(x)
        x = result
        return result

    return inner
