import pandas as pandas


def load(path: str) -> pandas.DataFrame | None:
    """
    Load a CSV file into a pandas DataFrame.

    Args:
        path (str): The path to the CSV file.

    Returns:
        pandas.DataFrame | None: The loaded DataFrame if successful,
        None if the file is not found.
    """

    try:
        file = pandas.read_csv(path)
    except FileNotFoundError:
        print(f"File not found: {path}")
        return None

    print("Loading dataset of dimensions " + str(file.shape))

    return file
