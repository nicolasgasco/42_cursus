from colorama import Fore, Style
import json as json
import numpy as np
import os as os
import pandas as pd

from src.Data.DataPlotter import DataPlotter
from src.Layer import Layer
from src.SettingsImporter import SettingsImporter
from src.TaskTimer import TaskTimer
from src.utils import print_output
import src.utils_loss as utils_loss
from src.utils_json import save_params_to_json


class MultilayerPerceptron:
    def __init__(self, train_data: pd.DataFrame | None = None):

        settings_importer = SettingsImporter("train.json")
        settings = settings_importer.import_settings()

        self.__train_data: pd.DataFrame | None = train_data \
            if train_data is not None else None
        self.__batch_data = pd.DataFrame()

        self.__inputs_columns: list[str] = [
            str(column) for column in settings["inputs_columns"]]

        self.__outputs: list[str] = settings["outputs"]
        self.__outputs_column: list[str] = settings["outputs_column"]

        self.__hidden_layers_count: int = settings["hidden_layers"]
        self.__hidden_layer_neurons: int = settings["hidden_layer_neurons"]

        self.__activation_function: str = settings["activation_function"]

        self.__learning_rate: float = settings["learning_rate"]
        self.__epochs: int = settings["epochs"]
        self.__batch_size: int = settings["batch_size"]

        self.__hidden_layers: list[Layer] = self.__generate_hidden_layers()
        self.__output_layer = Layer(
            self.__hidden_layer_neurons, len(self.__outputs))

        self.__plot_loss: bool = settings["plot_loss"]

    def __generate_hidden_layers(self) -> list[Layer]:
        """
        Generates the hidden layers for the multilayer perceptron.

        Returns:
            A list of lists, where each inner list represents a hidden layer
            and contains instances of the Neuron class.
        """

        hidden_layers: list[Layer] = []

        n_inputs = len(self.__inputs_columns)
        n_neurons = self.__hidden_layer_neurons
        for _ in range(self.__hidden_layers_count):
            hidden_layer = Layer(n_inputs, n_neurons)
            hidden_layers.append(hidden_layer)
            n_inputs = n_neurons

        return hidden_layers

    def __str__(self) -> str:
        representation = f"{Fore.GREEN}MultilayerPerceptron{Style.RESET_ALL}"
        representation += "(\n"
        representation += f"  inputs_columns: {self.__inputs_columns},\n"
        representation += f"  outputs: {self.__outputs},\n"
        representation += f"  outputs_column: {self.__outputs_column},\n"
        representation += f"  hidden_layers_count: {self.__hidden_layers_count}\n"
        representation += "  hidden_layer_neurons: "
        representation += f"{self.__hidden_layer_neurons}\n"
        representation += f"  learning_rate: {self.__learning_rate}\n"
        representation += ")\n"

        return representation

    def import_parameters(self, parameters: dict) -> None:
        def __validate_parameter(param: np.array, original: np.array,
                                 name: str) -> None:
            err_message = f"MultilayerPerceptron: {name} are None."
            assert param is not None, err_message
            err_message = "MultilayerPerceptron: {name} malformed."
            assert len(param) == len(original), err_message

        print("Importing parameters from JSON file...\n")

        output_layer = parameters["output_layer"]

        output_layer_weights = np.array(output_layer["weights"])
        __validate_parameter(output_layer_weights, self.__output_layer.weights,
                             "output layer weights")
        self.__output_layer.weights = output_layer_weights

        output_layer_biases = np.array(output_layer["biases"])
        __validate_parameter(output_layer_biases, self.__output_layer.biases,
                             "output layer biases")
        self.__output_layer.biases = output_layer_biases

        hidden_layers = parameters["hidden_layers"]

        for i, hidden_layer in enumerate(self.__hidden_layers):
            hidden_layer_parameters = hidden_layers[i]

            hidden_layer_weights = np.array(hidden_layer_parameters["weights"])
            __validate_parameter(hidden_layer_weights, hidden_layer.weights,
                                 "hidden layer weights")
            hidden_layer.weights = hidden_layer_weights

            hidden_layer_biases = np.array(hidden_layer_parameters["biases"])
            __validate_parameter(hidden_layer_biases, hidden_layer.biases,
                                 "hidden layer biases")
            hidden_layer.biases = hidden_layer_biases

    def train(self) -> None:
        timer = TaskTimer("Training")

        print("Starting training...\n")

        batch_size = self.__batch_size

        loss = None
        accuracy = None

        if self.__plot_loss:
            loss_plotter = DataPlotter()
            loss_plotter.train_plot_init(True)

        accuracy_plotter = DataPlotter()
        accuracy_plotter.train_plot_init(False)

        n_batches = len(self.__train_data) // batch_size + 1
        for b, i in enumerate(range(0, len(self.__train_data), batch_size)):
            self.__batch_data = self.__train_data[i:i + batch_size]

            for epoch in range(self.__epochs):

                predictions = self.__forward(
                    self.__batch_data[self.__inputs_columns])
                loss = self.__loss_function(predictions)

                accuracy = self.__accuracy(
                    predictions, self.__batch_data[self.__outputs_column])

                delta = self.__backpropagation_output_layer(predictions)
                self.__backpropagation_hidden_layers(delta)

                output = "\r"
                if n_batches != 1:
                    output += f"Batch {Fore.YELLOW}{b + 1}{Style.RESET_ALL}/"
                    output += f"{n_batches} - "
                output += f"Epoch {Fore.YELLOW}{epoch + 1}{Style.RESET_ALL}"
                output += f"/{self.__epochs}"
                output += " - Loss: "
                output += f"{Fore.YELLOW}{loss.round(5)}{Style.RESET_ALL}"
                output += " - Accuracy: "
                output += f"{Fore.YELLOW}{accuracy.round(2)}{Style.RESET_ALL}"
                print(output, end="")

                total_epoch = b * self.__epochs + epoch
                if self.__plot_loss and (total_epoch) % 10 == 0:
                    loss_plotter.train_plot_update(total_epoch, loss)
                    accuracy_plotter.train_plot_update(total_epoch, accuracy)

        print("\n")

        if self.__plot_loss:
            loss_plotter.train_plot_save()
            accuracy_plotter.train_plot_save()
            print("\n")

        output = f"Final loss: {Fore.GREEN}{loss.round(5)}{Style.RESET_ALL}"
        output += " - Accuracy: "
        output += f"{Fore.GREEN}{accuracy.round(2)}{Style.RESET_ALL}\n"
        print(output)

        timer.stop()

        save_params_to_json(self.__hidden_layers, self.__output_layer)

    def test(self, test_data: pd.DataFrame) -> None:
        print("Starting testing...\n")

        predictions = self.__forward(test_data[self.__inputs_columns])
        accuracy = self.__accuracy(
            predictions, test_data[self.__outputs_column])
        print(
            f"Test accuracy: {Fore.GREEN}{accuracy.round(2)}{Style.RESET_ALL}")

    def __forward(self, data: pd.DataFrame) -> np.ndarray:
        X = np.array(data)

        print_output(f"{Fore.YELLOW}INPUT LAYER{Style.RESET_ALL}")
        print_output(X, "\n")

        hidden_layer_inputs: np.ndarray = X

        hidden_layer_outputs = None

        for i, hidden_layer in enumerate(self.__hidden_layers):
            print_output(f"{Fore.YELLOW}HIDDEN LAYER {i}{Style.RESET_ALL}")
            print_output("Hidden layer input:", hidden_layer_inputs, "\n")

            print_output(hidden_layer, "\n")

            hidden_layer.forward(hidden_layer_inputs,
                                 self.__activation_function)

            hidden_layer_outputs = hidden_layer.output
            print_output("Hidden layer output:", hidden_layer_outputs, "\n")

            hidden_layer_inputs = hidden_layer_outputs

        print_output(f"{Fore.YELLOW}OUTPUT LAYER{Style.RESET_ALL}")
        print_output("Output layer inputs:", hidden_layer_outputs, "\n")

        print_output(self.__output_layer, "\n")
        output_layer_inputs = hidden_layer_outputs
        self.__output_layer.forward(output_layer_inputs, "softmax")

        output_layer_probabilities = self.__output_layer.output

        print_output("Softmax outputs:", output_layer_probabilities, "\n")

        return output_layer_probabilities

    def __accuracy(self, y: np.ndarray, x: pd.DataFrame) -> float:
        """
        Calculates the accuracy of the predictions made
        by the multilayer perceptron model.

        Parameters:
        - y (pd.DataFrame): The predicted values.

        Returns:
        - float: The accuracy of the predictions as a percentage.
        """

        y = pd.DataFrame(y)

        formatted_predictions = y.idxmax(axis=1).apply(
            lambda x: self.__outputs[int(x)]).values
        X = x.values.flatten()

        correct_predictions = sum((formatted_predictions == X))
        percentage_precision = correct_predictions / len(X) * 100

        return percentage_precision

    def __create_y_true(self) -> np.ndarray:
        y_true = pd.DataFrame(columns=self.__outputs)

        malignant_column = self.__outputs[0]
        y_true[malignant_column] = self.__batch_data[
            self.__outputs_column]
        y_true[malignant_column] = y_true[malignant_column].apply(
            lambda x: 1 if x == malignant_column else 0)

        benign_column = self.__outputs[1]
        y_true[benign_column] = self.__batch_data[self.__outputs_column]
        y_true[benign_column] = y_true[benign_column].apply(
            lambda x: 1 if x == benign_column else 0)

        return y_true

    def __loss_function(self, y_pred: np.ndarray) -> float:

        print_output(f"{Fore.YELLOW}LOSS FUNCTION{Style.RESET_ALL}")

        y_pred = pd.DataFrame(y_pred)
        y_pred = y_pred.clip(1e-7, 1-1e-7)  # to avoid log(0)

        # for compatibility with y_true
        y_pred.columns = self.__outputs  # type: ignore[assignment]

        y_true = self.__create_y_true()

        # TODO add setting for function
        # TODO activate this later
        if (len(self.__outputs) > 20):
            loss = utils_loss.categorical_cross_entropy_error(y_pred, y_true)
            print_output("Computing categorical cross-entropy loss...\n")
        else:
            loss = utils_loss.binary_cross_entropy_error(y_pred, y_true)
            print_output("Computing binary cross-entropy loss...\n")

        return loss

    def __backpropagation_output_layer(self,
                                       y_pred: pd.DataFrame) -> np.ndarray:
        print_output(
            f"{Fore.YELLOW}BACKPROPAGATION OUTPUT LAYER{Style.RESET_ALL}")

        print_output(f"{self.__output_layer}\n")

        y_true = self.__create_y_true()
        y_true = np.array(y_true)

        output_gradient = y_pred - y_true

        m = len(self.__batch_data)

        weights_gradient = 1 / m * \
            np.dot(output_gradient.T, self.__output_layer.input)
        bias_gradient = 1 / m * np.sum(output_gradient, axis=0)

        self.__output_layer.weights -= self.__learning_rate * weights_gradient
        self.__output_layer.biases -= self.__learning_rate * bias_gradient[0]

        print_output(f"{self.__output_layer}\n")

        return output_gradient

    def __backpropagation_hidden_layers(self, delta_L: np.ndarray) -> None:
        print_output(
            f"\n{Fore.YELLOW}BACKPROPAGATION HIDDEN LAYERS{Style.RESET_ALL}")

        delta_prev = delta_L
        for i, hidden_layer in enumerate(reversed(self.__hidden_layers)):
            original_i = len(self.__hidden_layers) - 1 - i
            print_output(
                f"\n{Fore.YELLOW}HIDDEN LAYER {original_i}{Style.RESET_ALL}")

            print_output(f"{hidden_layer}, i is {original_i}\n")

            weights = self.__output_layer.weights if i == 0 else \
                self.__hidden_layers[original_i + 1].weights

            m = len(self.__batch_data)

            output_gradient = None
            if self.__activation_function == "relu":
                output_gradient = np.dot(delta_prev, weights) * \
                    Layer.activation_relu_derivative(
                    hidden_layer.raw_output)
            elif self.__activation_function == "sigmoid":
                output_gradient = np.dot(delta_prev, weights) * \
                    Layer.activation_sigmoid_derivative(
                    hidden_layer.raw_output)

            weights_gradient = 1 / m * \
                np.dot(output_gradient.T, hidden_layer.input)
            bias_gradient = 1 / m * np.sum(output_gradient, axis=0)

            hidden_layer.weights -= self.__learning_rate * weights_gradient
            hidden_layer.biases -= self.__learning_rate * bias_gradient

            delta_prev = output_gradient

            print_output(f"{hidden_layer}\n")
