import pandas as pd
import numpy as np
import math as math
from colorama import Fore, Style

from src.utils import rand_small_float


class Layer:
    def __init__(self, n_inputs: int, n_neurons: int):
        # By initializing the weights with this shape,
        # we don't need to transpose weights when calculating dot product
        self.__weights = pd.DataFrame(
            np.full((n_inputs, n_neurons), rand_small_float()))

        self.__biases = [rand_small_float() for _ in range(n_neurons)]

        self.__input: pd.DataFrame = pd.DataFrame()
        self.__output: pd.DataFrame = pd.DataFrame()

    @property
    def weights(self) -> pd.DataFrame:
        return self.__weights

    @property
    def biases(self) -> list[float]:
        return self.__biases

    @property
    def input(self) -> pd.DataFrame:
        return self.__input

    @input.setter
    def input(self, input: pd.DataFrame):
        self.__input = input

    @property
    def output(self) -> pd.DataFrame:
        return self.__output

    @output.setter
    def output(self, output: pd.DataFrame):
        self.__output = output

    def __repr__(self) -> str:
        """
        Returns a string representation of the Layer object.

        The string representation includes the weights and biases of the layer.

        Returns:
            str: A string representation of the Layer object.
        """

        representation = "Layer(\n"

        for i in self.__weights.columns:
            representation += f"  {Fore.BLUE}Neuron {i}{Style.RESET_ALL}: "
            representation += f"weights: {self.__weights[i].to_list()}, "
            representation += f"bias: {self.__biases[i]}\n"

        representation += ")"

        return representation

    def weighted_sum(self, inputs: pd.DataFrame) -> pd.DataFrame:
        """
        Calculates the weighted sum of the inputs.

        Args:
            inputs (pd.DataFrame): The input data.

        Returns:
            pd.DataFrame: The result of the weighted sum.
        """

        result = np.dot(inputs, np.array(self.__weights)) + self.__biases

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
