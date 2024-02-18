class calculator:
    """
    A class representing a calculator.
    """

    @staticmethod
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """
        Calculates the dot product of two vectors.

        Args:
            V1 (list[float]): The first vector.
            V2 (list[float]): The second vector.

        Returns:
            None: Prints the dot product of the two vectors.
        """
        dot_product = sum([V1[i] * V2[i] for i in range(len(V1))])
        print(f"Dot product is: {dot_product}")

    @staticmethod
    def add_vec(V1: list[float], V2: list[float]) -> None:
        """
        Adds two vectors element-wise and prints the result.

        Args:
            V1 (list[float]): The first vector.
            V2 (list[float]): The second vector.

        Returns:
            None
        """
        add_vector = [V1[i] + V2[i] for i in range(len(V1))]
        print(f"Add vector is: {add_vector}")

    @staticmethod
    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """
        Calculates the element-wise subtraction of two vectors and prints the result.

        Args:
            V1 (list[float]): The first vector.
            V2 (list[float]): The second vector.

        Returns:
            None
        """
        sous_vector = [V1[i] - V2[i] for i in range(len(V1))]
        print(f"Sous vector is: {sous_vector}")
