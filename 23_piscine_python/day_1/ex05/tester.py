from load_image import ft_load
from pimp_image import ft_invert, ft_red, ft_green, ft_blue, ft_grey


array = ft_load("landscape.jpg")

# Convert to grayscale
ft_grey(array)
print(ft_grey.__doc__)

# Invert the image
ft_invert(array)
print(ft_invert.__doc__)

# Transform to red
ft_red(array)
print(ft_red.__doc__)

# Transform to green
ft_green(array)
print(ft_green.__doc__)

# Transform to blue
ft_blue(array)
print(ft_blue.__doc__)
