import numpy as np
from colorama import Fore, Style


class Layer:
    def __init__(self, n_inputs: int, n_neurons: int):
        self.__weights = np.random.rand(n_neurons, n_inputs) - 0.5

        self.__biases = [0.0 for _ in range(n_neurons)]

        self.__input = np.array([])
        self.__output = np.array([])
        self.__raw_output = np.array([])

    @property
    def weights(self) -> np.ndarray:
        return self.__weights

    @weights.setter
    def weights(self, weights: np.ndarray):
        self.__weights = weights

    @property
    def biases(self) -> list[float]:
        return self.__biases

    @biases.setter
    def biases(self, biases: list[float]):
        self.__biases = biases

    @property
    def input(self) -> np.ndarray:
        return self.__input

    @input.setter
    def input(self, input: np.ndarray):
        self.__input = input

    @property
    def output(self) -> np.ndarray:
        return self.__output

    @output.setter
    def output(self, output: np.ndarray):
        self.__output = output

    @property
    def raw_output(self) -> np.ndarray:
        return self.__raw_output

    @raw_output.setter
    def raw_output(self, raw_output: np.ndarray):
        self.__raw_output = raw_output

    def __repr__(self) -> str:
        """
        Returns a string representation of
         Layer object.

        The string representation includes
         weights and biases of layer.

        Returns:
            str: A string representation of
             Layer object.
        """

        representation = "Layer(\n"

        for i in range(len(self.__weights)):
            representation += f"  {Fore.BLUE}Neuron {i}{Style.RESET_ALL}: "
            representation += f"weights: {self.__weights[i]}, "
            representation += f"bias: {self.__biases[i]}\n"

        representation += ")"

        return representation

    def forward(self, inputs: np.ndarray, activation_function: str):
        """
        Perform the forward pass of the layer.
        Args:
            inputs (np.ndarray): The input data for the layer.
            activation_function (str): The activation function to be applied.
        Returns:
            np.ndarray: The output of the layer after applying
            the activation function.
        """

        self.__input = inputs

        weighted_sum = self.weighted_sum(inputs)
        self.__raw_output = weighted_sum

        if (activation_function == "sigmoid"):
            outputs = Layer.activation_sigmoid(weighted_sum)
        elif (activation_function == "relu"):
            outputs = Layer.activation_relu(weighted_sum)
        elif (activation_function == "softmax"):
            outputs = Layer.activation_softmax(weighted_sum)

        self.__output = outputs

    def weighted_sum(self, inputs: np.ndarray) -> np.ndarray:
        """
        Calculates the weighted sum of the inputs.

        Parameters:
            inputs (np.ndarray): The input values.

        Returns:
            np.ndarray: The weighted sum of the inputs.
        """

        result = np.dot(inputs, self.__weights.T) + self.__biases

        return result

    @staticmethod
    def activation_sigmoid(x: np.ndarray) -> np.ndarray:
        """
        Applies the sigmoid activation function to the input.

        Parameters:
        x (np.ndarray): The input array.

        Returns:
        np.ndarray: The output array after applying the sigmoid function.
        """

        return 1 / (1 + np.exp(-x))

    @staticmethod
    def activation_sigmoid_derivative(x: np.ndarray) -> np.ndarray:
        """
        Calculates the derivative of the sigmoid activation function.

        Parameters:
        x (np.ndarray): Input array.

        Returns:
        np.ndarray: Derivative of the sigmoid activation function.
        """

        return x * (1 - x)

    @staticmethod
    def activation_relu(x: np.ndarray) -> np.ndarray:
        """
        Applies 
         Rectified Linear Unit (ReLU) activation function
        to 
         input.

        Parameters:
        x (np.ndarray): The input array.

        Returns:
        np.ndarray: The output array after applying
        the ReLU activation function.
        """
        return np.maximum(0, x)

    def activation_relu_derivative(x: np.ndarray) -> np.ndarray:
        """
        Calculates the derivative of the ReLU activation function.

        Parameters:
        x (np.ndarray): Input array.

        Returns:
        np.ndarray: Derivative of the ReLU activation function.
        """

        return np.where(x > 0, 1, 0)

    @staticmethod
    def activation_step_function(x: float):
        """
        Applies the step function activation to the input.
        Parameters:
        x (float): The input value.
        Returns:
        int: The output value after applying the step function.
        """

        return 1 if x > 0 else 0

    @staticmethod
    def activation_softmax(x: np.ndarray) -> np.ndarray:
        """
        Applies the softmax activation function to the input array.
        Parameters:
        - x (np.ndarray): Input array.
        Returns:
        - np.ndarray: Output array after applying
        the softmax activation function.
        """

        exp = np.exp(x)
        return exp / np.sum(exp, axis=1, keepdims=True)
