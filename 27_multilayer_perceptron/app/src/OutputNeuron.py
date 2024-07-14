from src.Neuron import Neuron

import numpy as np
import pandas as pd


class OutputNeuron(Neuron):
    def __init__(self, weights, bias):
        super().__init__(weights, bias)

    def generate_output(self, inputs: np.ndarray) -> np.ndarray:
        """
        Generates the output of the output neuron based on the given inputs.

        Args:
          inputs (np.ndarray): The input values for the neuron.

        Returns:
          np.ndarray: The generated output of the neuron.
        """

        weighted_sum = self._weighted_sum(inputs)

        return weighted_sum.reshape(-1, 1)

    @staticmethod
    def softmax(x: np.ndarray):
        """
        Applies the softmax function to the input array.

        Parameters:
        x (np.ndarray): Input array.

        Returns:
        np.ndarray: Array with softmax applied to each element.
        """

        e_x = np.exp(x - np.max(x))
        return e_x / e_x.sum(axis=1).reshape(-1, 1)
