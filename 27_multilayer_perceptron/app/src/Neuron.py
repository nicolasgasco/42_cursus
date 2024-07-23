import math as math
import numpy as np
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

    @staticmethod
    def weighted_sum(inputs: pd.DataFrame,
                     weights: pd.DataFrame,
                     biases: list[float]) -> pd.DataFrame:
        result = np.dot(inputs, np.array(weights).T) + biases

        return pd.DataFrame(result)

    @staticmethod
    def activation_sigmoid(x: float):
        """
        Applies the sigmoid activation function to the input value.

        Args:
            x (float): The input value.

        Returns:
            float: The output value after applying the sigmoid function.
        """

        return 1 / (1 + math.exp(-x))

    @staticmethod
    def activation_relu(x: float):
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

    @staticmethod
    def activation_step_function(x: float):
        """
        Applies the step function to the input value.

        Args:
            x (float): The input value.

        Returns:
            float: The output value after applying the step function.
        """

        return 1 if x > 0 else 0

    @staticmethod
    def softmax(x: pd.DataFrame) -> pd.DataFrame:
        """
        Applies the softmax function to the input DataFrame.

        Parameters:
        x (pd.DataFrame): The input DataFrame.

        Returns:
        pd.DataFrame: The DataFrame with softmax applied to each element.
        """
        e_row = np.exp(x - np.max(x))
        return e_row / e_row.sum()
