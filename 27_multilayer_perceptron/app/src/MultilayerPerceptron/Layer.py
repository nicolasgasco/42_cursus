import pandas as pd

from src.Neuron import Neuron
from src.utils import rand_small_float


class Layer:
    def __init__(self, is_output_layer: bool,
                 weights_num: int, inputs_num: int):

        if (is_output_layer):
            self.__neurons: list[Neuron] = [
                Neuron([rand_small_float()] * weights_num, rand_small_float())
                for _ in range(inputs_num)]
        else:
            self.__neurons: list[Neuron] = [
                Neuron([rand_small_float()] * weights_num, rand_small_float())
                for _ in range(inputs_num)]

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
