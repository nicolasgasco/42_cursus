import json as json
import pandas as pd
import os as os


class InvalidPercentageError(Exception):
    pass


class DataPrepper:
    def __init__(self, data: pd.DataFrame):
        def _parse_percentage() -> int:
            try:
                settings_dir_path: str | None = os.environ.get(
                    "SETTINGS_DIR_PATH")
                assert settings_dir_path is not None, "DataPrepper: SETTINGS_DIR_PATH environment variable not set."

                with open(settings_dir_path + "/split.json") as file:
                    data = json.load(file)
            except FileNotFoundError:
                raise FileNotFoundError("DataPrepper: Settings file missing.")

            validation_percentage_str: str = data['validation_percentage']
            try:
                percentage = int(validation_percentage_str)
                if percentage < 0 or percentage > 90:
                    raise InvalidPercentageError(
                        "DataPrepper: Invalid percentage value.")
                return percentage
            except ValueError:
                raise ValueError("DataPrepper: Invalid percentage value.")
            except KeyError:
                raise KeyError(
                    "DataPrepper: validation_percentage key missing.")

        assert data is not None, "DataPrepper: data is None."

        data_dir_path = os.environ.get("DATA_DIR_PATH")
        assert data_dir_path is not None, "DataPrepper: DATA_DIR_PATH environment variable not set."
        self._data_dir_path: str = data_dir_path

        self._validation_percentage: int = _parse_percentage()

        self._data: pd.DataFrame = data

        self._validation_set: pd.DataFrame | None = None
        self._train_set: pd.DataFrame | None = None

    def split(self) -> None:
        assert self._validation_percentage is not None, "DataPrepper: validation_percentage is None."

        print("Splitting data into training and validation sets.")

        total_rows = self._data.shape[0]
        upper_bound = total_rows * self._validation_percentage // 100 - 1

        self._validation_set = self._data.iloc[:upper_bound]
        self._train_set = self._data.iloc[upper_bound:]

    def save_to_csv(self) -> None:
        if self._train_set is None or self._validation_set is None:
            raise ValueError(
                "DataPrepper: split method must be called before saving to CSV.")

        self._train_set.to_csv(self._data_dir_path +
                               "/train_set.csv", index=False)
        self._validation_set.to_csv(
            self._data_dir_path + "/validation_set.csv", index=False)

    def get_train_set(self) -> pd.DataFrame | None:
        return self._train_set

    def get_validation_percentage(self) -> int:
        return self._validation_percentage

    def get_validation_set(self) -> pd.DataFrame | None:
        return self._validation_set
