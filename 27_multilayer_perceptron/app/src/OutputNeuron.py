from src.Neuron import Neuron

import numpy as np
import pandas as pd


class OutputNeuron(Neuron):
    def __init__(self, weights, bias):
        super().__init__(weights, bias)

    def generate_output(self, inputs: pd.DataFrame) -> pd.DataFrame:
        """
        Generates the output of the output neuron based on the given inputs.

        Args:
          inputs (pd.DataFrame): The input data for the output neuron.

        Returns:
          pd.DataFrame: The generated output of the output neuron.
        """

        weighted_sum: pd.DataFrame = self._weighted_sum(inputs)

        return weighted_sum

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
