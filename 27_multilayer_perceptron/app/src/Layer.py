import pandas as pd
import numpy as np
import math as math

from src.Neuron import Neuron
from src.utils import rand_small_float


class Layer:
    def __init__(self, n_inputs: int, n_neurons: int):
        self.__neurons: list[Neuron] = [
            Neuron([rand_small_float()] * n_inputs, rand_small_float())
            for _ in range(n_neurons)]

        self.__input: pd.DataFrame = pd.DataFrame()
        self.__output: pd.DataFrame = pd.DataFrame()

    @property
    def neurons(self) -> list[Neuron | Neuron]:
        return self.__neurons

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
