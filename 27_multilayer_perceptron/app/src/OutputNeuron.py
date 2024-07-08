from src.Neuron import Neuron

import numpy as np
import pandas as pd


class OutputNeuron(Neuron):
    def __init__(self, weights, bias):
        super().__init__(weights, bias)

    def generate_output(self, inputs: pd.DataFrame):
        """
        Generates the output of the output neuron based on the given inputs.

        Args:
          inputs (pd.DataFrame): The input data for the neuron.

        Returns:
          pd.DataFrame: The weighted sum of the inputs plus the bias.
        """

        weighted_sum: pd.DataFrame = self._weighted_sum(inputs)

        return weighted_sum

    @staticmethod
    def softmax(x: pd.DataFrame):
        """
        Applies the softmax function to the input array.

        Parameters:
        x (pd.DataFrame): The input array.

        Returns:
        pd.DataFrame: The output array after applying the softmax function.
        """
        return np.exp(x) / np.sum(np.exp(x), axis=1).values.reshape(-1, 1)
