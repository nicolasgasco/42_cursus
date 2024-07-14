import math as math
import pandas as pd
import numpy as np


class Neuron:
    def __init__(self, weights, bias):
        self.bias: float = bias
        self.weights: list[float] = weights

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
        if (len(self.weights) > 3):
            representation += f"weights={self.weights[:3]}... , "
        else:
            representation += f"weights={self.weights}, "
        representation += f"bias={self.bias})"

        return representation

    def generate_output(self, inputs: pd.DataFrame) -> np.ndarray:
        """
        Generates the output of the neuron for the given inputs.

        Args:
            inputs (pd.DataFrame): The input data as a pandas DataFrame.

        Returns:
            np.ndarray: The generated output as a numpy array.
        """

        weighted_sum = self._weighted_sum(inputs)

        weighted_sum = np.array([self._activation_sigmoid(x)
                                for x in weighted_sum])

        return weighted_sum.reshape(-1, 1)

    def _weighted_sum(self, inputs: pd.DataFrame) -> np.ndarray:
        """
        Calculates the weighted sum of the inputs.

        Args:
            inputs (pd.DataFrame): The input data as a pandas DataFrame.

        Returns:
            np.ndarray: The calculated weighted sum.
        """

        result = np.array([])
        for input in inputs:
            if len(input) != len(self.weights):
                raise ValueError(
                    "The number of weights must match the number of inputs.")

            dot_product = np.dot(self.weights, input)
            weighted_sum = dot_product + self.bias

            result = np.append(result, weighted_sum)

        return result

    def _activation_sigmoid(self, x: float):
        """
        Applies the sigmoid activation function to the input value.

        Args:
            x (float): The input value.

        Returns:
            float: The output value after applying the sigmoid function.
        """

        return 1 / (1 + math.exp(-x))

    def _activation_relu(self, x: float):
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
