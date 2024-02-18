import numpy as numpy
import matplotlib.pyplot as plt


def _describe_image(image: numpy.ndarray) -> None:
    print(f"The shape of image is: {image.shape}")
    print(image)


def _save_image(array: numpy.ndarray, name: str, is_gray: bool = False) \
        -> None:
    """Save the given image array as a file with the specified name.

    Args:
        array (numpy.ndarray): The image array to be saved.
        name (str): The name of the file to be saved.

    Returns:
        None
    """
    plt.axis('off')
    if is_gray:
        plt.imshow(array, cmap='gray')
    else:
        plt.imshow(array)
    plt.savefig(name, bbox_inches='tight', pad_inches=0)


def ft_invert(array) -> None:
    """
    Invert the image.
    """

    MAX_RGB = 255

    new_image = numpy.copy(array)

    for y in range(len(array)):
        for x in range(len(array[y])):
            rgb_values = array[y][x]
            red_value = rgb_values[0]
            green_value = rgb_values[1]
            blue_value = rgb_values[2]

            new_image[y][x] = [MAX_RGB - red_value,
                               MAX_RGB - green_value, MAX_RGB - blue_value]

    _save_image(new_image, 'inverted.jpg')
    _describe_image(new_image)


def ft_red(array) -> None:
    """
    Make the image red.
    """
    new_image = numpy.copy(array)

    for y in range(len(array)):
        for x in range(len(array[y])):
            rgb_values = array[y][x]
            red_value = rgb_values[0]

            new_image[y][x] = [red_value, 0, 0]

    _save_image(new_image, 'red.jpg')
    _describe_image(new_image)


def ft_green(array) -> None:
    """
    Make the image green.
    """
    new_image = numpy.copy(array)

    for y in range(len(array)):
        for x in range(len(array[y])):
            rgb_values = array[y][x]
            green_value = rgb_values[1]

            new_image[y][x] = [0, green_value, 0]

    _save_image(new_image, 'green.jpg')
    _describe_image(new_image)


def ft_blue(array) -> None:
    """
    Make the image blue.
    """
    new_image = numpy.copy(array)

    for y in range(len(array)):
        for x in range(len(array[y])):
            rgb_values = array[y][x]
            blue_value = rgb_values[2]

            new_image[y][x] = [0, 0, blue_value]

    _save_image(new_image, 'blue.jpg')
    _describe_image(new_image)


def ft_grey(array) -> None:
    """
    Convert the image to grayscale.
    """

    new_image = numpy.copy(array)

    new_image = numpy.median(array, axis=2)

    _save_image(new_image, 'greyscale.jpg', True)
    _describe_image(new_image)
