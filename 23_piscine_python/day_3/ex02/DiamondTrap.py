from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    def __init__(self, first_name):
        """
        Initializes a new instance of the class.

        Args:
            first_name (str): The first name of the person.
        """
        super().__init__(first_name)

    def set_eyes(self, color):
        """
        Sets the color of the King's eyes.

        Args:
            color (str): The color of the King's eyes.
        """
        self.eyes = color

    def get_eyes(self):
        """
        Returns the color of the King's eyes.
        """
        return self.eyes

    def set_hair(self, color):
        """
        Sets the color of the King's hair.

        Args:
            color (str): The color of the King's hair.
        """
        self.hair = color

    def get_hair(self):
        """
        Returns the color of the King's hair.
        """
        return self.hair
