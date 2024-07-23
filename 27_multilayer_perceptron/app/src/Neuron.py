class Neuron:
    def __init__(self, weights, bias):
        self.__bias: float = bias
        self.__weights: list[float] = weights

    @property
    def bias(self) -> float:
        return self.__bias

    @bias.setter
    def bias(self, bias: float):
        self.__bias = bias

    @property
    def weights(self) -> list[float]:
        return self.__weights

    @weights.setter
    def weights(self, weights: list[float]):
        self.__weights = weights

    def __repr__(self) -> str:
        """
        Returns a string representation of the Neuron object.

        The string representation includes the weights and bias of the neuron.
        If the number of weights is greater than 3,
        only the first 3 weights are shown followed by '...'.

        Returns:
            str: A string representation of the Neuron object.
        """

        representation = "Neuron("
        weights = self.__weights if len(
            self.__weights) <= 3 else self.__weights[:3]
        representation += f"weights={weights}"
        representation += f"{'...' if len(self.__weights) > 3 else ''}, "
        representation += f"bias={self.__bias})"

        return representation
