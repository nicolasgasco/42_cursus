from abc import ABC, abstractmethod


class Character(ABC):
    """
    Represents a character in a story.

    Attributes:
        first_name (str): The first name of the character.
        is_alive (bool): Indicates if the character is alive.
    """

    def __init__(self, first_name, is_alive=True):
        """
        Initializes a Character object.

        Args:
            first_name (str): The first name of the character.
            is_alive (bool, optional): Indicates if the character is alive.
            Defaults to True.
        """
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self):
        """
        Sets the 'is_alive' attribute to False,
        indicating that the character has died.
        """
        self.is_alive = False


class Stark(Character):
    """
    A class representing a Stark character.

    Attributes:
        first_name (str): The first name of the Stark character.
        is_alive (bool): Whether the Stark character is alive or not.
    """

    def __init__(self, first_name, is_alive=True):
        """
        Initialize a Stark character object.

        Args:
            first_name (str): The first name of the Stark character.
            is_alive (bool, optional): Whether the Stark character is alive or not.
                Defaults to True.
        """
        super().__init__(first_name, is_alive)

    def die(self):
        """
        This method is called when the Stark character dies.
        It calls the `die` method of the superclass.
        """
        super().die()
