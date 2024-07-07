import numpy as np
import pandas as pd

from src.SettingsImporter import SettingsImporter
from src.Neuron import Neuron


class MultilayerPerceptron:
    def __init__(self, train_data: pd.DataFrame):
        def _validate_settings(settings: dict):
            assert "inputs_columns" in settings, "MultilayerPerceptron: inputs key missing."
            assert settings["inputs_columns"] is not None, "MultilayerPerceptron: inputs is None."
            assert len(settings["inputs_columns"]
                       ) > 0, "MultilayerPerceptron: inputs is empty."

            assert "outputs" in settings, "MultilayerPerceptron: outputs key missing."
            assert settings["outputs"] is not None, "MultilayerPerceptron: outputs is None."
            assert len(settings["outputs"]
                       ) > 0, "MultilayerPerceptron: outputs is empty."

            assert "outputs_columns" in settings, "MultilayerPerceptron: outputs key missing."
            assert settings["outputs_columns"] is not None, "MultilayerPerceptron: outputs is None."
            assert len(settings["outputs_columns"]
                       ) > 0, "MultilayerPerceptron: outputs is empty."

            assert "hidden_layers" in settings, "MultilayerPerceptron: hidden_layers key missing."
            assert settings["hidden_layers"] is not None, "MultilayerPerceptron: hidden_layers is None."
            assert settings["hidden_layers"] > 0, "MultilayerPerceptron: hidden_layers is less than 1."

            assert "hidden_layer_neurons" in settings, "MultilayerPerceptron: hidden_layer_neurons key missing."
            assert settings["hidden_layer_neurons"] is not None, "MultilayerPerceptron: hidden_layer_neurons is None."
            assert settings["hidden_layer_neurons"] > 0, "MultilayerPerceptron: hidden_layer_neurons is less than 1."

            assert "learning_rate" in settings, "MultilayerPerceptron: learning_rate key missing."
            assert settings["learning_rate"] is not None, "MultilayerPerceptron: learning_rate is None."
            assert settings["learning_rate"] > 0, "MultilayerPerceptron: learning_rate is less than 1."

        settings_importer = SettingsImporter("train.json")
        settings = settings_importer.import_settings()
        _validate_settings(settings)

        self._train_data: pd.DataFrame = train_data

        self._inputs_columns: list[str] = settings["inputs_columns"]
        self._outputs: list[str] = settings["outputs"]
        self._outputs_columns: list[str] = settings["outputs_columns"]
        self._hidden_layers_count: int = settings["hidden_layers"]
        self._hidden_layer_neurons: int = settings["hidden_layer_neurons"]

        self._learning_rate: float = settings["learning_rate"]

    def __str__(self) -> str:
        representation = "MultilayerPerceptron("
        representation += f"inputs_columns={self._inputs_columns}, "
        representation += f"outputs={self._outputs}, "
        representation += f"outputs_columns={self._outputs_columns}, "
        representation += f"hidden_layers_count={self._hidden_layers_count}, "
        representation += f"hidden_layer_neurons={self._hidden_layer_neurons})"
        representation += "\n"

        return representation

    def train(self) -> None:
        x = self._train_data[self._inputs_columns]
        print("\n")

        print(
            f"My model has {self._hidden_layers_count} hidden layers with {self._hidden_layer_neurons} neurons")
        print("\n")

        # Initialize the hidden layers
        hidden_layers = []
        for i in range(self._hidden_layers_count):
            print(f"Initializing hidden layer {i}")
            weights_num = len(x.columns)
            hidden_layer = [Neuron([self._random_float() * weights_num],
                                   self._random_float())
                            for _ in range(self._hidden_layer_neurons)]
            hidden_layers.append(hidden_layer)
            print(hidden_layer)
        print("\n")

        # Initialize the output layer
        print("Initializing output layer")
        weights_num = self._hidden_layer_neurons
        output_layer = [Neuron([self._random_float()] * weights_num,
                               self._random_float())
                        for _ in range(len(self._outputs))]
        print(output_layer)
        print("\n")

        neurons_input = x
        for i, hidden_layer in enumerate(hidden_layers):
            print(f"Hidden layer {i}")
            print("\n")

            neurons_outputs = []
            for i, neuron in enumerate(hidden_layer):
                print(f"\tNeuron {i}: {neuron}")
                print(
                    f"\tInput is: {len(neurons_input)} data points with shape {neurons_input.shape}")
                neuron_output = neuron.generate_output(neurons_input)
                print("\tOutput is: ", neuron_output)
                neurons_outputs.append(neuron_output)
                print("\n")

            neurons_input = neuron_output
            # print(f"Hidden layer outputs: {neurons_outputs[:3]}")

    # Use later, for now it's easier to see with 0.0

    def _random_float(self) -> float:
        num: float = np.random.randn() * 0.01
        return num
