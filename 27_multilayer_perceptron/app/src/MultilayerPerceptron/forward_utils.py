from src.Neuron import Neuron

import pandas as pd


def calc_layer_output(neurons: list[Neuron],
                      input: pd.DataFrame) -> pd.DataFrame:
    """
    Calculates the output of the hidden layer in a multilayer perceptron.

    Args:
      neurons (list[Neuron]): List of Neuron objects representing
      the neurons in the hidden layer.
      input (pd.DataFrame): Input data for the hidden layer.

    Returns:
      pd.DataFrame: Output of the hidden layer.

    """

    weights = [
        neuron.weights for neuron in neurons]
    biases = [
        neuron.bias for neuron in neurons]

    weighted_sum = Neuron.weighted_sum(
        input, pd.DataFrame(weights), biases)

    output = weighted_sum.map(
        lambda x: Neuron.activation_sigmoid(x))

    return output
