import time as time


def format_time(seconds: float) -> str:
    """
    Format the given number of seconds into a string representation of time in the format "MM:SS".

    Args:
        seconds (float): The number of seconds to format.

    Returns:
        str: The formatted time string in the format "MM:SS".
    """

    int_seconds = int(seconds)
    int_minutes = int(int_seconds) // 60

    str_seconds = str(int_seconds % 60).zfill(2)
    str_minutes = str(int_minutes % 60).zfill(2)

    return f"{str_minutes}:{str_seconds}"


def ft_tqdm(lst: range):
    """
    A custom implementation of the tqdm library for tracking the progress
    of an iteration.

    Args:
        lst (range): The range or iterable object to iterate over.

    Yields:
        Any: The elements of the input iterable.

    """
    lst_len = len(lst)
    start_time = time.time()

    count = 0

    for elem in lst:
        percentage = int((count) * 100 / lst_len)
        print(f"{percentage}%|[", end="")

        # Print the progress bar
        for i in range(percentage):
            print("=", end="")
        print(">", end="")

        # Print the empty spaces
        for i in range(100 - percentage - 1):
            print(" ", end="")

        print(f"]| {count + 1}/{lst_len}", end="")

        if count > 0:
            elapsed_time = time.time() - start_time

            # Print elapsed time
            print(f"[{format_time(elapsed_time)}", end="")

            iterations_per_second = count / elapsed_time

            estimated_time = float(lst_len - count) / iterations_per_second

            # Print estimated remaining time
            print(f"<{format_time(estimated_time)}", end="")

            # Print iterations per second
            print(
                f", {round(iterations_per_second, 2)}it/s]")
        else:
            print(" [00:00<--:--, -.-it/s]")

        count += 1
        yield elem
