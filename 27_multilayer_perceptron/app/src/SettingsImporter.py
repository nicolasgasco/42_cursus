import json as json
import os as os

from colorama import Fore, Style


class SettingsImporter:
    def __init__(self, settings_filename: str):
        settings_dir_path: str | None = os.environ.get(
            "SETTINGS_DIR_PATH")

        err_message = "SettingsImporter: invalid SETTINGS_DIR_PATH env var"
        assert settings_dir_path is not None, err_message
        self.__settings_dir_path: str = settings_dir_path

        err_message = "SettingsImporter: invalid settings_filename"
        assert settings_filename is not None, err_message
        self.__settings_file_path: str = os.path.join(
            self.__settings_dir_path, settings_filename)

        self.__settings: dict = {}

    def import_settings(self) -> dict:
        print("Importing settings from ", end="")
        print(f"{Fore.YELLOW}{self.__settings_file_path}{Style.RESET_ALL}",
              end="")
        print("...\n")

        try:
            with open(self.__settings_file_path) as file:
                settings_data = json.load(file)

                self.__settings = settings_data

                return settings_data
        except FileNotFoundError:
            raise FileNotFoundError(
                "SettingsImporter: Settings file not found")

    def validate_split_settings(self):
        settings = self.__settings

        err_message = "DataSplitter: validation_percentage key missing"
        assert "validation_percentage" in settings, err_message
        err_message = "DataSplitter: validation_percentage is None"
        assert settings["validation_percentage"] is not None, err_message
        err_message = "DataSplitter: validation_percentage is < 1"
        assert settings["validation_percentage"] > 0, err_message
        err_message = "DataSplitter: validation_percentage is > 100"
        assert settings["validation_percentage"] <= 100, err_message

    def validate_perceptron_settings(self):
        settings = self.__settings

        err_message = "MultilayerPerceptron: activation_function missing"
        assert "activation_function" in settings, err_message
        err_message = "MultilayerPerceptron: activation_function is None"
        assert settings["activation_function"] is not None, err_message
        activations = ["relu", "sigmoid"]
        err_message = "MultilayerPerceptron: activation_function not supported"
        assert settings["activation_function"] in activations, err_message

        err_message = "MultilayerPerceptron: batch_size key missing"
        assert "batch_size" in settings, err_message
        err_message = "MultilayerPerceptron: batch_size is None"
        assert settings["batch_size"] is not None, err_message
        err_message = "MultilayerPerceptron: batch_size is < 1"
        assert settings["batch_size"] > 0, err_message
        err_message = "MultilayerPerceptron: batch_size is not an integer"
        assert isinstance(settings["batch_size"], int), err_message
        err_message = "MultilayerPerceptron: batch_size is too large"
        assert settings["batch_size"] <= 1_000, err_message

        err_message = "MultilayerPerceptron: epochs key missing"
        assert "epochs" in settings, err_message
        err_message = "MultilayerPerceptron: epochs is None"
        assert settings["epochs"] is not None, err_message
        err_message = "MultilayerPerceptron: epochs is < 1"
        assert settings["epochs"] > 0, err_message
        err_message = "MultilayerPerceptron: epochs is not an integer"
        assert isinstance(settings["epochs"], int), err_message
        err_message = "MultilayerPerceptron: epochs is too large"
        assert settings["epochs"] <= 5_000, err_message

        err_message = "MultilayerPerceptron: hidden_layer_neurons missing"
        assert "hidden_layer_neurons" in settings, err_message
        err_message = "MultilayerPerceptron: hidden_layer_neurons is None"
        assert settings["hidden_layer_neurons"] is not None, err_message
        err_message = "MultilayerPerceptron: hidden_layer_neurons < 1"
        assert settings["hidden_layer_neurons"] > 0, err_message

        err_message = "MultilayerPerceptron: hidden_layers key missing"
        assert "hidden_layers" in settings, err_message
        err_message = "MultilayerPerceptron: hidden_layers is None"
        assert settings["hidden_layers"] is not None, err_message
        err_message = "MultilayerPerceptron: hidden_layers less than 1"
        assert settings["hidden_layers"] > 0, err_message

        err_message = "MultilayerPerceptron: inputs_columns key missing"
        assert "inputs_columns" in settings, err_message
        err_message = "MultilayerPerceptron: inputs is None"
        assert settings["inputs_columns"] is not None, err_message
        err_message = "MultilayerPerceptron: inputs is empty"
        assert len(settings["inputs_columns"]) > 0, err_message

        err_message = "MultilayerPerceptron: learning_rate key missing"
        assert "learning_rate" in settings, err_message
        err_message = "MultilayerPerceptron: learning_rate is None"
        assert settings["learning_rate"] is not None, err_message
        err_message = "MultilayerPerceptron: learning_rate is < 1"
        assert settings["learning_rate"] > 0, err_message

        err_message = "MultilayerPerceptron: outputs key missing"
        assert "outputs" in settings, err_message
        err_message = "MultilayerPerceptron: outputs is None"
        assert settings["outputs"] is not None, err_message
        err_message = "MultilayerPerceptron: outputs is empty"
        assert len(settings["outputs"]) > 0, err_message

        err_message = "MultilayerPerceptron: outputs_column key missing"
        assert "outputs_column" in settings, err_message
        err_message = "MultilayerPerceptron: outputs_column is None"
        assert settings["outputs_column"] is not None, err_message
        err_message = "MultilayerPerceptron: outputs_column is empty"
        assert len(settings["outputs_column"]) > 0, err_message

        err_message = "MultilayerPerceptron: plot_loss key missing"
        assert "plot_loss" in settings, err_message
        err_message = "MultilayerPerceptron: plot_loss is None"
        assert settings["plot_loss"] is not None, err_message
        err_message = "MultilayerPerceptron: plot_loss is not a boolean"
        assert isinstance(settings["plot_loss"], bool), err_message
