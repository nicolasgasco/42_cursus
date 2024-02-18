import numpy as numpy
import matplotlib.pyplot as plt
from load_image import ft_load

PATH = "animal.jpeg"


def _crop_image(image) -> numpy.ndarray:
    return numpy.array(image)[100:500, 450:850]


def _convert_to_grayscale(image: numpy.ndarray) -> numpy.ndarray:
    return numpy.dot(image[..., :3], [0.2989, 0.5870, 0.1140])


def _describe_image(image: numpy.ndarray) -> None:
    print(f"The shape of image is: {image.shape}")
    print(image)


def _rotate_image(image: numpy.ndarray) -> numpy.ndarray:
    new_image = image.copy()
    for y, row in enumerate(image):
        for x, pixel in enumerate(row):
            new_image[y][x] = image[x][y]

    return new_image


def main():
    image = ft_load(PATH)
    image = _crop_image(image)
    image = _convert_to_grayscale(image)

    _describe_image(image)

    new_image = image.copy()
    for y, row in enumerate(image):
        for x, pixel in enumerate(row):
            new_image[y][x] = image[x][y]

    plt.imshow(new_image, cmap=plt.get_cmap("gray"))
    plt.savefig('new_image.jpeg')

    _describe_image(new_image)


if __name__ == "__main__":
    main()
