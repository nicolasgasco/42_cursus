import numpy as np
import pandas as pd

from colorama import Fore, Style
from src.SettingsImporter import SettingsImporter
from src.Neuron import Neuron
from src.OutputNeuron import OutputNeuron
from src.MultilayerPerceptron.Layer import Layer

import src.MultilayerPerceptron.loss_utils as loss_utils


class MultilayerPerceptron:
    def __init__(self, train_data: pd.DataFrame):
        def __validate_settings(settings: dict):
            err_message = "MultilayerPerceptron: settings validation failed."
            assert "inputs_columns" in settings, err_message
            err_message = "MultilayerPerceptron: inputs is None."
            assert settings["inputs_columns"] is not None, err_message
            err_message = "MultilayerPerceptron: inputs is empty."
            assert len(settings["inputs_columns"]) > 0, err_message

            err_message = "MultilayerPerceptron: outputs key missing."
            assert "outputs" in settings, err_message
            err_message = "MultilayerPerceptron: outputs is None."
            assert settings["outputs"] is not None, err_message
            err_message = "MultilayerPerceptron: outputs is empty."
            assert len(settings["outputs"]) > 0, err_message

            err_message = "MultilayerPerceptron: outputs_columns key missing."
            assert "outputs_columns" in settings, err_message
            err_message = "MultilayerPerceptron: outputs is None."
            assert settings["outputs_columns"] is not None, err_message
            err_message = "MultilayerPerceptron: outputs is empty."
            assert len(settings["outputs_columns"]) > 0, err_message

            err_message = "MultilayerPerceptron: hidden_layers key missing."
            assert "hidden_layers" in settings, err_message
            err_message = "MultilayerPerceptron: hidden_layers is None."
            assert settings["hidden_layers"] is not None, err_message
            err_message = "MultilayerPerceptron: hidden_layers less than 1."
            assert settings["hidden_layers"] > 0, err_message

            err_message = "MultilayerPerceptron: hidden_layer_neurons missing."
            assert "hidden_layer_neurons" in settings, err_message
            err_message = "MultilayerPerceptron: hidden_layer_neurons is None."
            assert settings["hidden_layer_neurons"] is not None, err_message
            err_message = "MultilayerPerceptron: hidden_layer_neurons < 1."
            assert settings["hidden_layer_neurons"] > 0, err_message

            error_message = "MultilayerPerceptron: learning_rate key missing."
            assert "learning_rate" in settings, error_message
            error_message = "MultilayerPerceptron: learning_rate is None."
            assert settings["learning_rate"] is not None, error_message
            error_message = "MultilayerPerceptron: learning_rate is < 1."
            assert settings["learning_rate"] > 0, error_message

        settings_importer = SettingsImporter("train.json")
        settings = settings_importer.import_settings()
        __validate_settings(settings)

        self.__train_data: pd.DataFrame = train_data
        self.__inputs_columns: list[str] = settings["inputs_columns"]
        self.__outputs: list[str] = settings["outputs"]
        self.__outputs_columns: list[str] = settings["outputs_columns"]
        self.__hidden_layers_count: int = settings["hidden_layers"]
        self.__hidden_layer_neurons: int = settings["hidden_layer_neurons"]

        self.__learning_rate: float = settings["learning_rate"]

        self.__hidden_layers = self.__generate_hidden_layers()

        self.__output_layer = Layer(
            self.__hidden_layer_neurons, len(self.__outputs))

    def __generate_hidden_layers(self) -> list[list[Neuron]]:
        """
        Generates the hidden layers for the multilayer perceptron.

        Returns:
            A list of lists, where each inner list represents a hidden layer
            and contains instances of the Neuron class.
        """

        x = self.__train_data[self.__inputs_columns]

        hidden_layers: list[Layer] = []

        weights_num = len(x.columns)
        for _ in range(self.__hidden_layers_count):
            hidden_layer = Layer(weights_num, self.__hidden_layer_neurons)
            hidden_layers.append(hidden_layer)
            weights_num = self.__hidden_layer_neurons

        return hidden_layers

    def ___str__(self) -> str:
        representation = "MultilayerPerceptron("
        representation += f"inputs_columns={self.__inputs_columns}, "
        representation += f"outputs={self.__outputs}, "
        representation += f"outputs_columns={self.__outputs_columns}, "
        representation += f"hidden_layers_count={self.__hidden_layers_count}, "
        representation += f"hidden_layer_neurons={self.__hidden_layer_neurons}"
        representation += "\n"

        return representation

    def train(self) -> None:
        predictions: pd.DataFrame = self.__forward_propagation()

        loss: float = self.__loss_function(predictions)
        print(f"\nLoss: {loss}\n")

        precision: int = loss_utils.calc_precision(
            self.__train_data, self.__outputs_columns, predictions)
        print(f"\nPrecision: {precision.round(2)}%\n")

        self.__backpropagation(predictions)

    def __forward_propagation(self) -> pd.DataFrame:
        x: pd.DataFrame = self.__train_data[self.__inputs_columns]

        print(f"{Fore.YELLOW}INPUT LAYER{Style.RESET_ALL}")
        print(f"\n{x}\n")

        hidden_neurons_inputs: pd.DataFrame = x
        hidden_layer_outputs: pd.DataFrame = pd.DataFrame()

        for i, hidden_layer in enumerate(self.__hidden_layers):
            print(f"{Fore.YELLOW}HIDDEN LAYER {i}{Style.RESET_ALL}")
            print(f"Hidden layer inputs:\n{hidden_neurons_inputs}\n")

            hidden_neurons_outputs = pd.DataFrame(
                columns=range(len(hidden_layer.neurons)))
            for i, neuron in enumerate(hidden_layer.neurons):
                print(f"{Fore.GREEN}Neuron {i}{Style.RESET_ALL}: {neuron}")

                neuron_output = neuron.generate_output(hidden_neurons_inputs)
                print(f"Output:\n{neuron_output}\n")

                hidden_neurons_outputs[i] = neuron_output

            hidden_neurons_inputs = hidden_neurons_outputs
            hidden_layer_outputs = hidden_neurons_outputs

            print(f"Hidden layer outputs:\n{hidden_layer_outputs}\n")

        print(f"{Fore.YELLOW}OUTPUT LAYER{Style.RESET_ALL}")
        print(f"Output layer inputs:\n{hidden_layer_outputs}\n")

        self.__output_layer.input = hidden_layer_outputs

        output_layer_neurons_outputs = pd.DataFrame()
        for i, neuron in enumerate(self.__output_layer.neurons):
            print(f"{Fore.GREEN}Neuron {i}{Style.RESET_ALL}: {neuron}")

            neuron_output = neuron.generate_output(hidden_layer_outputs)
            print(f"Output:\n{neuron_output}\n")

            output_layer_neurons_outputs[i] = neuron_output

        output_layer_outputs = output_layer_neurons_outputs

        output_layer_probabilities = output_layer_outputs.apply(
            lambda x: OutputNeuron.softmax(x), axis=1)
        print(f"Probabilities:\n{output_layer_probabilities}\n")

        return output_layer_probabilities

    def __create_y_true(self) -> pd.DataFrame:
        """
        Create a DataFrame containing the true labels
        for the training data.

        Returns:
            pd.DataFrame: A DataFrame containing the true labels
            for the training data.
        """

        y_true = pd.DataFrame(columns=self.__outputs)

        malignant_column = self.__outputs[0]
        y_true[malignant_column] = self.__train_data[
            self.__outputs_columns]
        y_true[malignant_column] = y_true[malignant_column].apply(
            lambda x: 1 if x == malignant_column else 0)

        benign_column = self.__outputs[1]
        y_true[benign_column] = self.__train_data[self.__outputs_columns]
        y_true[benign_column] = y_true[benign_column].apply(
            lambda x: 1 if x == benign_column else 0)

        return y_true

    def __loss_function(self, y_pred: pd.DataFrame) -> float:
        """
        Calculate the loss for the predicted labels.

        Args:
            y_pred (pd.DataFrame): A DataFrame containing the predicted labels.

        Returns:
            float: The calculated loss.
        """

        print(f"{Fore.YELLOW}LOSS CALCULATION{Style.RESET_ALL}")

        y_pred_clipped = y_pred.clip(1e-7, 1 - 1e-7)  # to avoid log(0)
        y_pred_clipped.columns = self.__outputs  # for compatibility with y_true
        print("y_pred:\n", y_pred_clipped)

        y_true = self.__create_y_true()
        print(f"\ny_true:\n{y_true}")

        loss = loss_utils.binary_cross_entropy_error(y_pred_clipped, y_true)

        return loss

    def __backpropagation(self, y_pred: pd.DataFrame) -> None:
        print(f"{Fore.YELLOW}BACKPROPAGATION{Style.RESET_ALL}")

        y_pred.columns = self.__outputs  # for compatibility with y_true
        print("y_pred:\n", y_pred)

        y_true = self.__create_y_true()
        print(f"\ny_true:\n{y_true}")

        gradient = y_pred - y_true

        print(f"\nGradient:\n{gradient}")

        activation_output_layer = self.__output_layer.input
        print(f"\nActivation output layer:\n{activation_output_layer}")

        weights_gradient = pd.DataFrame(np.dot(
            activation_output_layer.T, gradient) / len(y_pred))
        print(f"\nWeights gradient:\n{weights_gradient}")

        bias_gradient = np.sum(gradient, axis=0) / len(y_pred)
        print(f"\nBias gradient:\n{bias_gradient}")

        for i, neuron in enumerate(self.__output_layer.neurons):
            print(f"\n{Fore.GREEN}Neuron {i}{Style.RESET_ALL}")

            print("Before: ", neuron)

            neuron.weights -= (self.__learning_rate *
                               weights_gradient[i]).values
            neuron.bias -= self.__learning_rate * bias_gradient.values[i]

            print("After: ", neuron)
