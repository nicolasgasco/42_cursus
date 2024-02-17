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
        str_result = ""

        percentage = int((count) * 100 / lst_len)
        str_result += f"{percentage}%|["

        # Print the progress bar
        for i in range(int(percentage / 2)):
            str_result += "="
        str_result += ">"

        # Print the empty spaces
        for i in range(int((100 - percentage - 1) / 2)):
            str_result += " "

        str_result += f"]| {count + 1}/{lst_len}"

        if count > 0:
            elapsed_time = time.time() - start_time

            # Print elapsed time
            str_result += f" [{format_time(elapsed_time)}"

            iterations_per_second = count / elapsed_time

            estimated_time = float(lst_len - count) / iterations_per_second

            # Print estimated remaining time
            str_result += f"<{format_time(estimated_time)}"

            # Print iterations per second
            str_result += f", {round(iterations_per_second, 2)}it/s]"
        else:
            str_result += " [00:00<--:--, -.-it/s]"

        print(str_result, end="\r", flush=True)
        count += 1
        yield elem
