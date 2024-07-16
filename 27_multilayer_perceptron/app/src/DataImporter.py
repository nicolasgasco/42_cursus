import os
import pandas as pd


class DataImporter:
    def __init__(self):
        data_path: str | None = os.environ.get("DATA_PATH")
        assert data_path is not None, "DataImporter: DATA_PATH environment variable not set."

        self.__data_path: str = data_path
        self.__data: pd.DataFrame = pd.DataFrame()

    def import_data(self) -> pd.DataFrame:
        """
        Imports data from a CSV file.

        Returns:
            pd.DataFrame: The imported data as a pandas DataFrame.

        Raises:
            FileNotFoundError: If the dataset file is not found.
        """

        try:
            text_field_types: dict = {0: str, 1: str}
            data: pd.DataFrame = pd.read_csv(
                self.__data_path, header=None, dtype=text_field_types)

            self.__data = data

            return self.__data
        except FileNotFoundError:
            raise FileNotFoundError("DataImporter: Dataset file not found.")

    def normalize_data(self) -> pd.DataFrame:
        """
        Normalizes the data.

        Returns:
            pd.DataFrame: The normalized data as a pandas DataFrame.
        """

        # Exclude the first non-numeric column
        data_to_normalize: pd.DataFrame = self.__data.iloc[:, 2:]

        # Min-max normalization
        normalized_data: pd.DataFrame = (data_to_normalize - data_to_normalize.min()) / \
            (data_to_normalize.max() - data_to_normalize.min())

        result: pd.DataFrame = pd.concat(
            [self.__data.iloc[:, :2], normalized_data], axis=1)

        return result

    @staticmethod
    def import_train_data() -> pd.DataFrame:
        """
        Imports the training data from the specified path.

        Returns:
            pd.DataFrame: The imported training data.
        """
        train_data_path: str | None = os.environ.get("TRAIN_PATH")
        assert train_data_path is not None, "TRAIN_PATH environment variable not set."

        train_data: pd.DataFrame = pd.read_csv(train_data_path)

        return train_data

    @staticmethod
    def import_test_data() -> pd.DataFrame:
        """
        Imports the test data from the specified path.

        Returns:
            pd.DataFrame: The imported test data.
        """
        test_data_path: str | None = os.environ.get("TEST_PATH")
        assert test_data_path is not None, "TEST_PATH environment variable not set."

        test_data: pd.DataFrame = pd.read_csv(test_data_path)

        return test_data
