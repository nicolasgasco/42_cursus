import numpy as np
import pandas as pd

from src.OutputNeuron import OutputNeuron


class Layer:
    def __init__(self, weights_num: int, inputs_num: int):
        self.__neurons: list[OutputNeuron] = [
            OutputNeuron([self.__random_float()]
                         * weights_num,
                         self.__random_float())
            for _ in range(inputs_num)]

        self.__input: pd.DataFrame = pd.DataFrame()

    @property
    def neurons(self) -> list[OutputNeuron]:
        return self.__neurons

    @property
    def input(self) -> pd.DataFrame:
        return self.__input

    @input.setter
    def input(self, input: pd.DataFrame):
        self.__input = input

    def __random_float(self) -> float:
        num: float = np.random.randn() * 0.01
        return num
