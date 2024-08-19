from colorama import Fore, Style
import json as json
import numpy as np
import os as os
import pandas as pd
import sys as sys

from src.Data.DataPlotter import DataPlotter
from src.Layer import Layer
from src.SettingsImporter import SettingsImporter
from src.TaskTimer import TaskTimer
from src.utils.binary_cross_entropy_error import binary_cross_entropy_error
from src.utils.categorical_cross_entropy_error \
    import categorical_cross_entropy_error
from src.utils.save_params_to_json import save_params_to_json
from src.utils.print_output import print_output


class MultilayerPerceptron:
    def __init__(self, train_data: pd.DataFrame | None = None,
                 test_data: pd.DataFrame | None = None):

        settings_importer = SettingsImporter("train.json")
        settings = settings_importer.import_settings()
        settings_importer.validate_perceptron_settings()

        self.__train_data: pd.DataFrame | None = train_data.dropna() \
            if train_data is not None else None
        self.__test_data: pd.DataFrame | None = test_data.dropna() \
            if test_data is not None else None
        self.__batch_data = pd.DataFrame()

        self.__inputs_columns: list[str] = [
            int(column) for column in settings["inputs_columns"]]

        self.__outputs: list[str] = settings["outputs"]
        self.__outputs_column = int(settings["outputs_column"])

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

        self.__frontend_data: bool = settings["frontend_data"]
        
        self.__early_stopping: bool = settings["early_stopping"]

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
        repr = f"{Fore.GREEN}MultilayerPerceptron{Style.RESET_ALL}"
        repr += "(\n"
        repr += f"  activation_function: {self.__activation_function},\n"
        repr += f"  batch_size: {self.__batch_size},\n"
        repr += f"  epochs: {self.__epochs},\n"
        repr += f"  frontend_data: {self.__frontend_data},\n"
        repr += f"  hidden_layer_neurons: {self.__hidden_layer_neurons},\n"
        repr += f"  hidden_layers: {self.__hidden_layers_count},\n"
        repr += f"  inputs_columns: {self.__inputs_columns},\n"
        repr += f"  learning_rate: {self.__learning_rate},\n"
        repr += f"  outputs: {self.__outputs},\n"
        repr += f"  outputs_column: {self.__outputs_column},\n"
        repr += f"  plot_loss: {self.__plot_loss}\n"
        repr += ")\n"

        return repr

    def import_parameters(self, parameters: dict) -> None:
        """
        Imports the parameters for the MultilayerPerceptron from a dictionary.
        Args:
            parameters (dict): A dictionary containing the parameters
            for the MultilayerPerceptron.
        Raises:
            AssertionError: If any of the parameters are None
            or have a different length than the original parameters.
        Returns:
            None
        """

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
        """
        Trains the multilayer perceptron model.
        Returns:
            None
        """

        timer = TaskTimer("Training")

        print(f"{Fore.YELLOW}TRAINING{Style.RESET_ALL}")

        batch_size = self.__batch_size

        loss = None
        accuracy = None

        if self.__plot_loss:
            loss_plotter = DataPlotter()
            loss_plotter.train_plot_init(True)

        accuracy_plotter = DataPlotter()
        accuracy_plotter.train_plot_init(False)

        if self.__frontend_data:
            frontend_data = {
                "data": {},
                "epochs_data": []
            }

        if self.__early_stopping:
            prev_test_loss = np.inf

        n_batches = len(self.__train_data) // batch_size + 1
        for b, i in enumerate(range(0, len(self.__train_data), batch_size)):
            self.__batch_data = self.__train_data[i:i + batch_size]

            for epoch in range(self.__epochs):

                predictions = self.__forward(
                    self.__batch_data.iloc[:, self.__inputs_columns])
                loss = self.__loss_function(predictions, self.__batch_data)

                accuracy = self.__accuracy(
                    predictions,
                    self.__batch_data.iloc[:, self.__outputs_column])

                delta = self.__backpropagation_output_layer(predictions)
                self.__backpropagation_hidden_layers(delta)

                [test_acc, test_loss] = self.test(self.__test_data, False)

                self.__print_epoch_output({
                    'accuracy': accuracy,
                    'b': b,
                    'epoch': epoch,
                    'loss': loss,
                    'n_batches': n_batches,
                    'test_acc': test_acc,
                    'test_loss': test_loss
                })
                
                if (self.__early_stopping):
                    if (test_loss > prev_test_loss):
                        print(f"\n{Fore.YELLOW}Early stopping{Style.RESET_ALL}")
                        break

                total_epoch = b * self.__epochs + epoch
                if self.__plot_loss and (total_epoch) % 10 == 0:
                    loss_plotter.train_plot_update(
                        total_epoch, loss, test_loss)
                    accuracy_plotter.train_plot_update(
                        total_epoch, accuracy, test_acc)

                if self.__frontend_data:
                    data = self.__encode_frontend_epochs_data({
                        'accuracy': accuracy,
                        'b': b,
                        'epoch': epoch,
                        'loss': loss,
                        'predictions': predictions,
                        'test_acc': test_acc,
                        'test_loss': test_loss,
                        'total_epoch': total_epoch
                    })
                    frontend_data["epochs_data"].append(data)

        print("\n")

        timer.stop()

        if self.__plot_loss:
            loss_plotter.train_plot_save(self.__activation_function)
            accuracy_plotter.train_plot_save(self.__activation_function)
            print("\n")

        output = f"Final loss: {Fore.GREEN}{loss.round(5)}{Style.RESET_ALL}"
        output += " - Accuracy: "
        output += f"{Fore.GREEN}{accuracy.round(2)}{Style.RESET_ALL}\n"
        print(output)

        save_params_to_json(self.__hidden_layers, self.__output_layer)

        if self.__frontend_data:
            frontend_data["data"] = {
                'batch_size': batch_size,
                "activation_function": self.__activation_function,
                "data_points": len(self.__train_data),
                "outputs": self.__outputs,
                "test_data_points": len(self.__test_data),
                "total_batches": n_batches,
                "total_epochs": self.__epochs * n_batches
            }
            frontend_data["data"] = self.__encode_frontend_model_data(
                {"batch_size": batch_size, "n_batches": n_batches})
            self.__save_frontend_data(frontend_data)

    def test(self, test_data: pd.DataFrame, print_output: bool = True) -> None:
        """
        Test the multilayer perceptron model on the given test data.
        Parameters:
            test_data (pd.DataFrame): The test data to evaluate the model on.
            print_output (bool, optional): Whether to print the output.
            Defaults to True.
        Returns:
            list: A list containing the accuracy and loss of the model.
        """

        if (print_output):
            print(f"{Fore.YELLOW}TESTING{Style.RESET_ALL}")

        clean_test_data = test_data
        predictions = self.__forward(
            clean_test_data.iloc[:, self.__inputs_columns])
        accuracy = self.__accuracy(
            predictions, clean_test_data.iloc[:, self.__outputs_column])
        loss = self.__loss_function(predictions, clean_test_data)

        if (print_output):
            output = "Loss: "
            output += f"{Fore.GREEN}{loss.round(5)}{Style.RESET_ALL}"
            output += " - Test accuracy: "
            output += f"{Fore.GREEN}{accuracy.round(2)}{Style.RESET_ALL}\n"
            print(output)

        return [accuracy, loss]

    def __forward(self, data: pd.DataFrame) -> np.ndarray:
        """
        Performs forward propagation through the multilayer perceptron.
        Args:
            data (pd.DataFrame): The input data for the forward pass.
        Returns:
            np.ndarray: The output layer probabilities after the forward pass.
        """

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
        Calculate the accuracy of the predictions made
        by the multilayer perceptron model.

        Parameters:
            y (np.ndarray): The predicted values.
            x (pd.DataFrame): The input data.

        Returns:
            float: The percentage precision of the predictions.
        """

        y = pd.DataFrame(y)
        try:
            formatted_predictions = y.idxmax(axis=1).apply(
                lambda x: self.__outputs[int(x)]).values
        except ValueError:
            print("Overflow error. Use smaller values")
            sys.exit(1)

        X = x.values.flatten()

        correct_predictions = sum((formatted_predictions == X))
        percentage_precision = correct_predictions / len(X) * 100

        return percentage_precision

    def __create_y_true(self, data: pd.DataFrame) -> np.ndarray:
        """
        Create a binary encoded target array based on the given data.
        Parameters:
            data (pd.DataFrame): The input data.
        Returns:
            np.ndarray: The binary encoded target array.
        """

        y_true = pd.DataFrame(columns=self.__outputs)

        for index, _ in enumerate(self.__outputs):
            column = self.__outputs[index]
            y_true[column] = data.iloc[:, self.__outputs_column]
            y_true[column] = y_true[column].apply(
                lambda x: 1 if x == column else 0)

        return y_true

    def __loss_function(self, y_pred: np.ndarray, data: pd.DataFrame) -> float:
        """
        Compute the loss function for the multilayer perceptron model.
        Parameters:
        - y_pred (np.ndarray): The predicted output values.
        - data (pd.DataFrame): The input data.
        Returns:
        - float: The computed loss value.
        """

        print_output(f"{Fore.YELLOW}LOSS FUNCTION{Style.RESET_ALL}")

        y_pred = pd.DataFrame(y_pred)
        y_pred = y_pred.clip(1e-7, 1-1e-7)  # to avoid log(0)

        # for compatibility with y_true
        y_pred.columns = self.__outputs

        y_true = self.__create_y_true(data)

        if (len(self.__outputs) > 2):
            loss = categorical_cross_entropy_error(y_pred, y_true)
            print_output("Computing categorical cross-entropy loss...\n")
        else:
            loss = binary_cross_entropy_error(y_pred, y_true)
            print_output("Computing binary cross-entropy loss...\n")

        return loss

    def __backpropagation_output_layer(self,
                                       y_pred: pd.DataFrame) -> np.ndarray:
        """
        Performs backpropagation on the output layer
        of the multilayer perceptron.
        Args:
            y_pred (pd.DataFrame): The predicted output values.
        Returns:
            np.ndarray: The gradient of the output layer.
        """

        print_output(
            f"{Fore.YELLOW}BACKPROPAGATION OUTPUT LAYER{Style.RESET_ALL}")

        print_output(f"{self.__output_layer}\n")

        y_true = self.__create_y_true(self.__batch_data)
        y_true = np.array(y_true)

        output_gradient = y_pred - y_true

        m = len(self.__batch_data)

        weights_gradient = 1 / m * \
            np.dot(output_gradient.T, self.__output_layer.input)
        bias_gradient = 1 / m * np.sum(output_gradient, axis=0)

        self.__output_layer.weights -= self.__learning_rate * weights_gradient
        self.__output_layer.biases -= self.__learning_rate * bias_gradient

        print_output(f"{self.__output_layer}\n")

        return output_gradient

    def __backpropagation_hidden_layers(self, delta_L: np.ndarray) -> None:
        """
        Perform backpropagation on the hidden layers
        of the multilayer perceptron.
        Args:
            delta_L (np.ndarray): The delta values of the output layer.
        Returns:
            None
        """

        print_output(
            f"\n{Fore.YELLOW}BACKPROPAGATION HIDDEN LAYERS{Style.RESET_ALL}")

        delta_prev = delta_L
        for i, hidden_layer in enumerate(reversed(self.__hidden_layers)):
            original_i = len(self.__hidden_layers) - 1 - i
            print_output(
                f"\n{Fore.YELLOW}HIDDEN LAYER {original_i}{Style.RESET_ALL}")

            print_output(f"{hidden_layer}\n")

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

    def __print_epoch_output(self, data: dict) -> str:

        output = "\r"
        if data['n_batches'] != 1:
            output += f"Batch {Fore.YELLOW}{data['b'] + 1}{Style.RESET_ALL}/"
            output += f"{data['n_batches']} - "
        output += f"Epoch {Fore.YELLOW}{data['epoch'] + 1}{Style.RESET_ALL}"
        output += f"/{self.__epochs}"
        output += " - Train(loss: "
        output += f"{Fore.YELLOW}{data['loss'].round(5)}{Style.RESET_ALL}"
        output += ", accuracy: "
        output += f"{Fore.YELLOW}{data['accuracy'].round(2)}{Style.RESET_ALL})"
        output += " - Test(loss: "
        output += f"{Fore.YELLOW}{data['test_loss'].round(5)}{Style.RESET_ALL}"
        output += ", accuracy: "
        output += f"{Fore.YELLOW}{data['test_acc'].round(2)}{Style.RESET_ALL})"
        output += "             "  # to clear previous output

        print(output, end="")

    def __encode_frontend_epochs_data(self, data) -> dict:
        data_limit = 20

        relevant_batch_data = self.__batch_data.iloc[:, self.__inputs_columns]
        batch_data = relevant_batch_data[0:data_limit].T.to_dict()
        return {
            "accuracy": data['accuracy'],
            "batch": data['b'],
            "batch_data": batch_data,
            "epoch": data['epoch'],
            "hidden_layers": [{
                "biases": hidden_layer.biases.tolist(),
                "weights": hidden_layer.weights.tolist()
            } for hidden_layer in self.__hidden_layers],
            "loss": data['loss'],
            "output_layer": {
                "biases": self.__output_layer.biases.tolist(),
                "weights": self.__output_layer.weights.tolist()
            },
            "predictions": data['predictions'][0:data_limit].tolist(),
            "test_accuracy": data['test_acc'],
            "test_loss": data['test_loss'],
            "total_epoch": data['total_epoch'],
            "true_values": self.__batch_data.iloc[
                :, self.__outputs_column][0:data_limit].tolist()
        }

    def __encode_frontend_model_data(self, data) -> dict:
        return {
            'batch_size': data["batch_size"],
            "activation_function": self.__activation_function,
            "data_points": len(self.__train_data),
            "outputs": self.__outputs,
            "test_data_points": len(self.__test_data),
            "total_batches": data["n_batches"],
            "total_epochs": self.__epochs * data["n_batches"]
        }

    def __save_frontend_data(self, data: dict) -> None:
        frontend_data_path = os.environ.get("FRONTEND_DATA_PATH")
        frontend_data_file = os.path.join(frontend_data_path, "data.json")

        output = "Saving frontend data to "
        output += f"{Fore.YELLOW}{frontend_data_file}{Style.RESET_ALL}"
        output += "...\n"
        print(output)

        with open(frontend_data_file, 'w') as file:
            json.dump(data, file)
