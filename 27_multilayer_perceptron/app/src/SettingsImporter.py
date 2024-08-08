import json as json
import os as os

from colorama import Fore, Style


class SettingsImporter:
    def __init__(self, settings_filename: str):
        settings_dir_path: str | None = os.environ.get(
            "SETTINGS_DIR_PATH")

        error_message = "SettingsImporter: invalid SETTINGS_DIR_PATH env var."
        assert settings_dir_path is not None, error_message
        self.__settings_dir_path: str = settings_dir_path

        error_message = "SettingsImporter: invalid settings_filename."
        assert settings_filename is not None, error_message
        self.__settings_file_path: str = os.path.join(
            self.__settings_dir_path, settings_filename)

        self.__settings: dict = {}

    def import_settings(self) -> dict:
        print("Importing settings from ")
        print(f"{Fore.YELLOW}{self.__settings_file_path}{Style.RESET_ALL}")
        print("...\n")

        try:
            with open(self.__settings_file_path) as file:
                settings_data = json.load(file)

                self.__settings = settings_data

                return settings_data
        except FileNotFoundError:
            raise FileNotFoundError(
                "SettingsImporter: Settings file not found.")

    def validate_settings(self):
        settings = self.__settings

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

        error_message = "MultilayerPerceptron: epochs key missing."
        assert "epochs" in settings, error_message
        error_message = "MultilayerPerceptron: epochs is None."
        assert settings["epochs"] is not None, error_message
        error_message = "MultilayerPerceptron: epochs is < 1."
        assert settings["epochs"] > 0, error_message
        error_message = "MultilayerPerceptron: epochs is not an integer."
        assert isinstance(settings["epochs"], int), error_message
        error_message = "MultilayerPerceptron: epochs is too large."
        assert settings["epochs"] < 2_000, error_message

        error_message = "MultilayerPerceptron: batch_size key missing."
        assert "batch_size" in settings, error_message
        error_message = "MultilayerPerceptron: batch_size is None."
        assert settings["batch_size"] is not None, error_message
        error_message = "MultilayerPerceptron: batch_size is < 1."
        assert settings["batch_size"] > 0, error_message
        error_message = "MultilayerPerceptron: batch_size is not an integer."
        assert isinstance(settings["batch_size"], int), error_message
        error_message = "MultilayerPerceptron: batch_size is too large."
        assert settings["batch_size"] < 1_000, error_message
