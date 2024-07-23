from src.Layer import Layer

import pandas as pd


def layer_output(layer: Layer,
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

    weights = layer.weights
    biases = layer.biases

    weighted_sum = Layer.weighted_sum(input, weights, biases)

    output = weighted_sum.map(
        lambda x: Layer.activation_relu(x))

    return output
