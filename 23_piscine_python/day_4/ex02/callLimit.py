
def callLimit(limit: int):
    count = 0

    def callLimiter(function):
        def limit_function():
            nonlocal count

            if (count >= limit):
                print(
                    f"Error: {function} call too many times")
                return
            else:
                function()

            count += 1

        return limit_function

    return callLimiter
