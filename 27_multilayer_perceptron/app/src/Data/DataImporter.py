import json as json
import os as os
import pandas as pd


class DataImporter:
    def __init__(self):
        data_path: str | None = os.environ.get("DATA_PATH")

        err_message = "DataImporter: DATA_PATH environment variable not set."
        assert data_path is not None, err_message

        self.__data_path: str = data_path
        self.__data: pd.DataFrame = pd.DataFrame()

    @property
    def data(self) -> pd.DataFrame:
        return self.__data

    def import_data(self) -> pd.DataFrame:
        """
        Imports data from a CSV file.

        Returns:
            pd.DataFrame: The imported data as a pandas DataFrame.

        Raises:
            FileNotFoundError: If the dataset file is not found.
        """

        try:
            data: pd.DataFrame = pd.read_csv(self.__data_path)

            self.__data = data

            return self.__data
        except FileNotFoundError:
            raise FileNotFoundError("DataImporter: Dataset file not found.")

    @staticmethod
    def normalize_data(data: pd.DataFrame) -> pd.DataFrame:
        """
        Normalizes the data.

        Returns:
            pd.DataFrame: The normalized data as a pandas DataFrame.
        """
        # Support for datasets with mixed data types
        first_numeric_col = data[data.columns[1:]].select_dtypes(
            include="number").columns[0]
        col_index = data.columns.get_loc(first_numeric_col)
        data_to_normalize: pd.DataFrame = data.iloc[:, col_index:]

        # Min-max normalization
        normalized_data: pd.DataFrame = (data_to_normalize -
                                         data_to_normalize.min()) / \
            (data_to_normalize.max() - data_to_normalize.min())

        result: pd.DataFrame = pd.concat(
            [data.iloc[:, :col_index], normalized_data], axis=1)

        return result

    @staticmethod
    def import_train_data() -> pd.DataFrame:
        """
        Imports the training data from the specified path.

        Returns:
            pd.DataFrame: The imported training data.
        """
        train_data_path: str | None = os.environ.get("TRAIN_PATH")

        err_message = "TRAIN_PATH environment variable not set."
        assert train_data_path is not None, err_message

        try:
            train_data: pd.DataFrame = pd.read_csv(train_data_path)
        except FileNotFoundError:
            raise FileNotFoundError(
                "DataImporter: Training data file not found.")

        return train_data

    @staticmethod
    def import_test_data() -> pd.DataFrame:
        """
        Imports the test data from the specified path.

        Returns:
            pd.DataFrame: The imported test data.
        """
        test_data_path: str | None = os.environ.get("TEST_PATH")

        err_message = "TEST_PATH environment variable not set."
        assert test_data_path is not None, err_message

        test_data: pd.DataFrame = pd.read_csv(test_data_path)

        return test_data

    @staticmethod
    def import_parameters() -> dict:
        parameters_path: str | None = os.environ.get("PARAMETERS_PATH")

        err_message = "PARAMETERS_PATH environment variable not set."
        assert parameters_path is not None, err_message

        try:
            with open(parameters_path, "r") as file:
                parameters = json.load(file)

                return parameters
        except FileNotFoundError:
            raise FileNotFoundError("DataImporter: Parameters file not found.")
