import numpy as np
import pandas as pd
from colorama import Fore, Style

from src.SettingsImporter import SettingsImporter
from src.Layer import Layer
import src.MultilayerPerceptron.utils_loss as utils_loss
from src.utils import print_output


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

            err_message = "MultilayerPerceptron: outputs_column key missing."
            assert "outputs_column" in settings, err_message
            err_message = "MultilayerPerceptron: outputs_column is None."
            assert settings["outputs_column"] is not None, err_message
            err_message = "MultilayerPerceptron: outputs_column is empty."
            assert len(settings["outputs_column"]) > 0, err_message

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

            error_message = "MultilayerPerceptron: activation_function missing."
            assert "activation_function" in settings, error_message
            error_message = "MultilayerPerceptron: activation_function is None."
            assert settings["activation_function"] is not None, error_message
            supported_activations = ["relu", "sigmoid"]
            error_message = "MultilayerPerceptron: activation_function not supported."
            assert settings["activation_function"] in supported_activations, error_message

        settings_importer = SettingsImporter("train.json")
        settings = settings_importer.import_settings()
        __validate_settings(settings)

        self.__train_data: pd.DataFrame = train_data
        self.__batch_data = pd.DataFrame()

        self.__inputs_columns: list[str] = settings["inputs_columns"]

        self.__outputs: list[str] = settings["outputs"]
        self.__outputs_column: list[str] = settings["outputs_column"]

        self.__hidden_layers_count: int = settings["hidden_layers"]
        self.__hidden_layer_neurons: int = settings["hidden_layer_neurons"]

        self.__activation_function: str = settings["activation_function"]

        self.__learning_rate: float = settings["learning_rate"]
        self.__epochs: int = 300

        self.__hidden_layers: list[Layer] = self.__generate_hidden_layers()
        self.__output_layer = Layer(
            self.__hidden_layer_neurons, len(self.__outputs))

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
        representation = "MultilayerPerceptron(\n"
        representation += f"  inputs_columns: {self.__inputs_columns},\n"
        representation += f"  outputs: {self.__outputs},\n"
        representation += f"  outputs_column: {self.__outputs_column},\n"
        representation += f"  hidden_layers_count: {self.__hidden_layers_count}\n"
        representation += "  hidden_layer_neurons: "
        representation += f"{self.__hidden_layer_neurons}\n"
        representation += f"  learning_rate: {self.__learning_rate}\n"
        representation += ")\n"

        return representation

    def train(self) -> None:
        self.__batch_data = self.__train_data

        print("Starting training...\n")

        loss = None
        accuracy = None

        for epoch in range(self.__epochs):

            predictions = self.__forward()
            loss = self.__loss_function(predictions)

            predictions = pd.DataFrame(predictions)
            pd.columns = self.__outputs

            accuracy = self.__accuracy(predictions)

            delta = self.__backpropagation_output_layer(predictions)
            self.__backpropagation_hidden_layers(delta)

            print(
                f"\rEpoch {epoch + 1}/{self.__epochs} - Loss: {loss.round(10)}", end="")

        print("\n")
        print("Loss: ", loss.round(10))
        print("Accuracy: ", accuracy.round(2))
        print("\n")

    def __forward(self) -> np.ndarray:
        X = np.array(self.__batch_data[self.__inputs_columns])

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

    def __accuracy(self, y: pd.DataFrame) -> float:
        """
        Calculates the accuracy of the predictions made
        by the multilayer perceptron model.

        Parameters:
        - y (pd.DataFrame): The predicted values.

        Returns:
        - float: The accuracy of the predictions as a percentage.
        """

        formatted_predictions = y.idxmax(axis=1).apply(
            lambda x: self.__outputs[int(x)]).values
        X = self.__batch_data[self.__outputs_column].values.flatten()

        correct_predictions = sum((formatted_predictions == X))
        percentage_precision = correct_predictions / len(X) * 100

        return percentage_precision

    def __create_y_true(self) -> np.ndarray:
        y_true = pd.DataFrame(columns=self.__outputs)

        malignant_column = self.__outputs[0]
        y_true[malignant_column] = self.__train_data[
            self.__outputs_column]
        y_true[malignant_column] = y_true[malignant_column].apply(
            lambda x: 1 if x == malignant_column else 0)

        benign_column = self.__outputs[1]
        y_true[benign_column] = self.__train_data[self.__outputs_column]
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

            output_gradient = np.dot(delta_prev, weights) * \
                Layer.activation_relu_derivative(
                hidden_layer.raw_output)

            weights_gradient = 1 / m * \
                np.dot(output_gradient.T, hidden_layer.input)
            bias_gradient = 1 / m * np.sum(output_gradient, axis=0)

            hidden_layer.weights -= self.__learning_rate * weights_gradient
            hidden_layer.biases -= self.__learning_rate * bias_gradient

            delta_prev = output_gradient

            print_output(f"{hidden_layer}\n")
