import pandas as pd
import os as os

from colorama import Fore, Style
from src.SettingsImporter import SettingsImporter


class InvalidPercentageError(Exception):
    pass


class DataSplitter:
    def __init__(self, data: pd.DataFrame):
        def _parse_percentage() -> int:
            settings_importer = SettingsImporter("split.json")
            settings = settings_importer.import_settings()
            settings_importer.validate_split_settings()

            validation_percentage_str: str = settings['validation_percentage']
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

        self.__validation_percentage: int = _parse_percentage()

        self.__data: pd.DataFrame = data

        self.__validation_set: pd.DataFrame | None = None
        self.__train_set: pd.DataFrame | None = None

    def __str__(self) -> str:
        representation = "DataSplitter(validation_percentage="
        representation += f"{self.__validation_percentage}, "
        representation += f"data={self.__data.shape[0]}, "
        train_size = self.__train_set.shape[0] if self.__train_set is not None\
            else None
        representation += f"train_set={train_size}, "
        validation_size = self.__validation_set.shape[0] if \
            self.__validation_set is not None else None
        representation += f"validation_set={validation_size})"
        representation += "\n"

        return representation

    def split(self) -> None:
        """
        Splits the data into training and validation sets base
        on the specified validation percentage.

        Raises:
            AssertionError: If the validation percentage is None.

        """
        err_message = "DataSplitter: validation_percentage is None."
        assert self.__validation_percentage is not None, err_message

        print("Splitting data into training and validation sets...\n")

        total_rows = self.__data.shape[0]
        upper_bound = total_rows * self.__validation_percentage // 100 - 1

        self.__validation_set = self.__data.iloc[:upper_bound]
        self.__train_set = self.__data.iloc[upper_bound:]

    def save_to_csv(self) -> None:
        """
        Saves the train and validation sets to CSV files.

        Raises:
            ValueError: If the train or validation set is not set.
        """

        if self.__train_set is None or self.__validation_set is None:
            err_message = "DataSplitter: train or validation set is None."
            raise ValueError(err_message)

        print("Saving train and validation sets to CSV files...")

        train_set_path: str | None = os.environ.get("TRAIN_PATH")
        err_message = "DataSplitter: TRAIN_PATH environment variable not set."
        assert train_set_path is not None, err_message
        self.__train_set.to_csv(train_set_path, index=False)

        output = "Train set saved to "
        output += f"{Fore.YELLOW}{train_set_path}{Style.RESET_ALL}.\n"
        print(output)

        validation_set_path: str | None = os.environ.get("TEST_PATH")
        err_message = "DataSplitter: TEST_PATH environment variable not set."
        assert validation_set_path is not None, err_message
        self.__validation_set.to_csv(validation_set_path, index=False)

        output = "Validation set saved to "
        output += f"{Fore.YELLOW}{validation_set_path}{Style.RESET_ALL}.\n"

        print(output)
