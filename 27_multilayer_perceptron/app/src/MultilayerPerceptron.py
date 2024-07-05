import pandas as pd

from src.SettingsImporter import SettingsImporter


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

        settings_importer = SettingsImporter("train.json")
        settings = settings_importer.import_settings()
        _validate_settings(settings)

        self._train_data: pd.DataFrame = train_data

        self._inputs_columns: list[str] = settings["inputs_columns"]
        self._outputs: list[str] = settings["outputs"]
        self._outputs_columns: list[str] = settings["outputs_columns"]
        self._hidden_layers: int = settings["hidden_layers"]
        self._hidden_layer_neurons: int = settings["hidden_layer_neurons"]
