import math as math
import pandas as pd


class Neuron:
    def __init__(self, weights, bias):
        self.weights = pd.DataFrame(weights)
        self.bias = pd.DataFrame([bias])

    def __repr__(self) -> str:
        representation = "Neuron("
        if (len(self.weights) > 3):
            representation += f"weights={self.weights[:3]}... , "
        else:
            representation += f"weights={self.weights}, "
        representation += f"bias={self.bias})"

        return representation

    def generate_output(self, inputs: pd.DataFrame):
        print("\tNeuron: generating output...")
        weighted_sum: pd.DataFrame = (
            inputs * self.weights).sum(axis=1) + self.bias

        output = self._activation_sigmoid(weighted_sum)

        return output

    def _activation_sigmoid(self, weighted_sum: pd.DataFrame):
        return pd.DataFrame([1 / (1 + math.exp(-sum)) for sum in weighted_sum])
