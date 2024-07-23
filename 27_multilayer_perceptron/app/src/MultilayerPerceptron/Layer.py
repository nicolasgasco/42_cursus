import pandas as pd

from src.Neuron import Neuron
from src.utils import rand_small_float


class Layer:
    def __init__(self, n_inputs: int, n_neurons: int):

        self.__neurons: list[Neuron] = [
            Neuron([rand_small_float()] * n_inputs, rand_small_float())
            for _ in range(n_neurons)]

        self.__input: pd.DataFrame = pd.DataFrame()

    @ property
    def neurons(self) -> list[Neuron | Neuron]:
        return self.__neurons

    @ property
    def input(self) -> pd.DataFrame:
        return self.__input

    @ input.setter
    def input(self, input: pd.DataFrame):
        self.__input = input
