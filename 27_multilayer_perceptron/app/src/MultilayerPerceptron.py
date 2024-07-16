import numpy as np
import pandas as pd

from colorama import Fore, Style
from src.SettingsImporter import SettingsImporter
from src.Neuron import Neuron
from src.OutputNeuron import OutputNeuron


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
        x: pd.DataFrame = self._train_data[self._inputs_columns]

        print(f"{Fore.YELLOW}INPUT LAYER{Style.RESET_ALL}")
        print(f"\n{x}\n")

        weights_num = len(x.columns)

        hidden_layers = []
        for i in range(self._hidden_layers_count):
            hidden_layer = [Neuron([self._random_float()] * weights_num,
                                   self._random_float())
                            for _ in range(self._hidden_layer_neurons)]
            hidden_layers.append(hidden_layer)
            weights_num = self._hidden_layer_neurons

        hidden_neurons_inputs: pd.DataFrame = x
        hidden_layer_outputs: pd.DataFrame = pd.DataFrame()

        for i, hidden_layer in enumerate(hidden_layers):
            print(f"{Fore.YELLOW}HIDDEN LAYER {i}{Style.RESET_ALL}")
            print(f"Hidden layer inputs:\n{hidden_neurons_inputs}\n")

            hidden_neurons_outputs = pd.DataFrame(
                columns=range(len(hidden_layer)))
            for i, neuron in enumerate(hidden_layer):
                print(f"{Fore.GREEN}Neuron {i}{Style.RESET_ALL}: {neuron}")

                neuron_output = neuron.generate_output(hidden_neurons_inputs)
                print(f"Output:\n{neuron_output}\n")

                hidden_neurons_outputs[i] = neuron_output

            hidden_neurons_inputs = hidden_neurons_outputs
            hidden_layer_outputs = hidden_neurons_outputs

            print(f"Hidden layer outputs:\n{hidden_layer_outputs}\n")

        output_layer = [OutputNeuron([self._random_float()] * weights_num,
                                     self._random_float())
                        for _ in range(len(self._outputs))]

        print(f"{Fore.YELLOW}OUTPUT LAYER{Style.RESET_ALL}")
        print(f"Output layer inputs:\n{hidden_layer_outputs}\n")

        output_layer_neurons_outputs = pd.DataFrame()
        for i, neuron in enumerate(output_layer):
            print(f"{Fore.GREEN}Neuron {i}{Style.RESET_ALL}: {neuron}")

            neuron_output = neuron.generate_output(hidden_layer_outputs)
            print(f"Output:\n{neuron_output}\n")

            output_layer_neurons_outputs[i] = neuron_output

        output_layer_outputs = output_layer_neurons_outputs

        output_layer_probabilities = output_layer_outputs.apply(
            lambda x: OutputNeuron.softmax(x), axis=1)
        print(f"Probabilities:\n{output_layer_probabilities}\n")

        # formatted_probabilities = output_layer_probabilities.idxmax(axis=1)
        # print(f"Formatted probabilities:\n{formatted_probabilities}\n")

    def _random_float(self) -> float:
        num: float = np.random.randn() * 0.01
        return num
