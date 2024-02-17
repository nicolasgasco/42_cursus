from load_image import ft_load
import numpy as numpy
import matplotlib.pyplot as plt


def main():
    image = ft_load("animal.jpeg")
    print(image)

    image = numpy.array(image)[100:500, 450:850]

    image = numpy.dot(image[..., :3], [0.2989, 0.5870, 0.1140])
    plt.imshow(image, cmap=plt.get_cmap("gray"))
    plt.savefig('new_image.jpeg')

    print(f"The shape of image is: {image.shape}")
    print(image)


if __name__ == "__main__":
    main()
