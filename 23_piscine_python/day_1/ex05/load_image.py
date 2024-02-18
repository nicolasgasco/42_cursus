from matplotlib.image import imread
import numpy as numpy


def ft_load(path: str) -> numpy.ndarray | None:
    try:
        image = imread(path)
    except FileNotFoundError:
        print(f"File not found: {path}")
        return None
    except Exception as e:
        print(f"An error occurred: {e}")
        return None

    return image
