import json as json
import re
import pandas as pd
import os as os

from colorama import Fore, Style


class InvalidPercentageError(Exception):
    pass


class DataSplitter:
    def __init__(self, data: pd.DataFrame):
        def _parse_percentage() -> int:
            """
            Parses the validation percentage from the settings file.

            Returns:
                int: The validation percentage value.

            Raises:
                FileNotFoundError: If the settings file is missing.
                InvalidPercentageError: If the percentage value is invalid.
                ValueError: If the percentage value is not an integer.
                KeyError: If the 'validation_percentage' key is missing in the settings file.
            """

            try:
                settings_dir_path: str | None = os.environ.get(
                    "SETTINGS_DIR_PATH")
                assert settings_dir_path is not None, "DataSplitter: SETTINGS_DIR_PATH environment variable not set."

                settings_file_name = settings_dir_path + "/split.json"
                print(
                    f"Importing settings from {Fore.YELLOW}{settings_dir_path}/split.json{Style.RESET_ALL}...\n")

                with open(settings_file_name) as file:
                    data = json.load(file)
            except FileNotFoundError:
                raise FileNotFoundError("DataSplitter: Settings file missing.")

            validation_percentage_str: str = data['validation_percentage']
            try:
                percentage = int(validation_percentage_str)
                if percentage < 0 or percentage > 90:
                    raise InvalidPercentageError(

                        "DataSplitter: Invalid percentage value.")
                return percentage
            except ValueError:
                raise ValueError("DataSplitter: Invalid percentage value.")
            except KeyError:
                raise KeyError(

                    "DataSplitter: validation_percentage key missing.")

        assert data is not None, "DataSplitter: data is None."

        data_dir_path = os.environ.get("DATA_DIR_PATH")
        assert data_dir_path is not None, "DataSplitter: DATA_DIR_PATH environment variable not set."
        self._data_dir_path: str = data_dir_path

        self._validation_percentage: int = _parse_percentage()

        self._data: pd.DataFrame = data

        self._validation_set: pd.DataFrame | None = None
        self._train_set: pd.DataFrame | None = None

    def __str__(self) -> str:
        representation = "DataSplitter("
        representation += f"validation_percentage={self._validation_percentage}, "
        representation += f"data={self._data.shape[0]}, "
        representation += f"train_set={self._train_set.shape[0] if self._train_set is not None else None}, "
        representation += f"validation_set={self._validation_set.shape[0] if self._validation_set is not None else None})"
        representation += "\n"

        return representation

    def split(self) -> None:
        """
        Splits the data into training and validation sets base
        on the specified validation percentage.

        Raises:
            AssertionError: If the validation percentage is None.

        """
        assert self._validation_percentage is not None, "DataSplitter: validation_percentage is None."

        print("Splitting data into training and validation sets...\n")

        total_rows = self._data.shape[0]
        upper_bound = total_rows * self._validation_percentage // 100 - 1

        self._validation_set = self._data.iloc[:upper_bound]
        self._train_set = self._data.iloc[upper_bound:]

    def save_to_csv(self) -> None:
        """
        Saves the train and validation sets to CSV files.

        Raises:
            ValueError: If the train or validation set is not set.
        """

        if self._train_set is None or self._validation_set is None:
            raise ValueError(
                "DataSplitter: split method must be called before saving to CSV.")

        print("Saving train and validation sets to CSV files...")

        train_set_path = self._data_dir_path + "/train_set.csv"
        self._train_set.to_csv(train_set_path, index=False)
        print(
            f"Train set saved to {Fore.YELLOW}{train_set_path}{Style.RESET_ALL}.")

        validation_set_path = self._data_dir_path + "/validation_set.csv"
        self._validation_set.to_csv(validation_set_path, index=False)
        print(
            f"Validation set saved to {Fore.YELLOW}{validation_set_path}{Style.RESET_ALL}.\n")

    def get_train_set(self) -> pd.DataFrame | None:
        return self._train_set

    def get_validation_percentage(self) -> int:
        return self._validation_percentage

    def get_validation_set(self) -> pd.DataFrame | None:
        return self._validation_set
