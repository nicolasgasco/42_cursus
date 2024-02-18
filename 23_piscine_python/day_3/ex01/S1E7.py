from S1E9 import Character


class Baratheon(Character):
    def __init__(self, first_name, is_alive=True):
        """
        Initializes a new instance of the class.

        Args:
            first_name (str): The first name of the person.
            is_alive (bool, optional): Indicates if the person is alive.
            Defaults to True.
        """
        super().__init__(first_name, is_alive)
        self.eyes = 'brown'
        self.hair = 'dark'

    def __repr__(self):
        """
        Returns a string representation of the Baratheon character.
        """
        return f"Baratheon('{self.first_name}', '{self.eyes}', '{self.hair}')"

    def __str__(self):
        """
        Returns a string representation of the Baratheon character.
        """
        return f"Baratheon with first_name={self.first_name}, \
            is_alive={self.is_alive}, and eyes={self.eyes}, hair={self.hair}"

    def die(self):
        """
        This method is called when the Baratheon character dies.
        It calls the `die` method of the superclass.
        """
        super().die()


class Lannister(Character):
    def __init__(self, first_name, is_alive=True):
        """
        Initializes a new instance of the class.

        Args:
            first_name (str): The first name of the person.
            is_alive (bool, optional): Indicates if the person is alive.
            Defaults to True.
        """
        super().__init__(first_name, is_alive)
        self.eyes = 'blue'
        self.hair = 'light'

    def __repr__(self):
        """
        Returns a string representation of the Lannister character.
        """
        return f"Lannister('{self.first_name}', '{self.eyes}', '{self.hair}')"

    def __str__(self):
        """
        Returns a string representation of the Lannister character.
        """
        return f"Lannister with first_name={self.first_name}, \
            is_alive={self.is_alive}, and eyes={self.eyes}, hair={self.hair}"

    def die(self):
        """
        This method is called when the Lannister character dies.
        It calls the `die` method of the superclass.
        """
        super().die()

    @staticmethod
    def create_lannister(first_name, is_alive):
        """
        Creates a new Lannister character.
        """
        return Lannister(first_name, is_alive)
