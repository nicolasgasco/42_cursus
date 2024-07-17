import math as math
import pandas as pd


class Neuron:
    def __init__(self, weights, bias):
        self.__bias: float = bias
        self.__weights: list[float] = weights

        self.__output: pd.DataFrame = pd.DataFrame()

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

    @property
    def output(self) -> pd.DataFrame:
        return self.__output

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

    def generate_output(self, inputs: pd.DataFrame) -> pd.DataFrame:
        """
        Generates the output of the neuron based on the given inputs.

        Args:
            inputs (pd.DataFrame): The input data for the neuron.

        Returns:
            pd.DataFrame: The generated output of the neuron.
        """

        weighted_sum: pd.DataFrame = self._weighted_sum(inputs)

        result = weighted_sum.apply(lambda x: self.__activation_sigmoid(x))

        self.__output = result

        return result

    def _weighted_sum(self, inputs: pd.DataFrame) -> pd.DataFrame:
        """
        Calculates the weighted sum of the inputs.

        Args:
            inputs (pd.DataFrame): The input data as a DataFrame.

        Returns:
            pd.DataFrame: The weighted sum of the inputs.
        """

        err_message = "Number of weights should be equal to number of inputs."
        assert len(inputs.columns) == len(self.__weights), err_message

        dot_product = inputs.dot(self.__weights)
        weighted_sum = dot_product + self.__bias

        return weighted_sum

    def __activation_sigmoid(self, x: float):
        """
        Applies the sigmoid activation function to the input value.

        Args:
            x (float): The input value.

        Returns:
            float: The output value after applying the sigmoid function.
        """

        return 1 / (1 + math.exp(-x))

    def __activation_relu(self, x: float):
        """
        Applies the Rectified Linear Unit (ReLU) activation function
        to the input.

        Args:
            x (float): The input value.

        Returns:
            float: The output value after applying
            the ReLU activation function.
        """

        return max(0, x)
