class calculator:
    def __repr__(self) -> str:
        """
        Returns a string representation of the object.

        Returns:
            str: A string representation of the object.
        """

        return f"{self.lst}"

    class Calculator:
        def __init__(self, lst) -> None:
            """
            Initializes a Calculator object.

            Args:
                lst (list): The list of numbers to perform calculations on.
            """
            self.lst = lst

    def __add__(self, object) -> None:
        """
        Add the given object to each element in the list.

        Args:
            object: The object to be added to each element in the list.

        Returns:
            None
        """
        self.lst = [x + object for x in self.lst]
        print(self)

    def __mul__(self, object) -> None:
        """
        Multiply each element in the list by the given object.

        Args:
            object: The object to multiply each element with.

        Returns:
            None
        """
        self.lst = [x * object for x in self.lst]
        print(self)

    def __sub__(self, object) -> None:
        """
        Subtract the given object from each element in the list.

        Args:
            object: The object to subtract from each element in the list.

        Returns:
            None
        """
        self.lst = [x - object for x in self.lst]
        print(self)

    def __truediv__(self, object) -> None:
        """
        Divide each element in the list by the given object.

        Args:
            object: The object to divide each element by.

        Raises:
            AssertionError: If the object is zero.

        Returns:
            None
        """
        assert object != 0, "Division by zero"

        self.lst = [x / object for x in self.lst]
        print(self)
