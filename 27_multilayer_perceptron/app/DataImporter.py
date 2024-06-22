import os
import pandas as pd


class DataImporter:
    def __init__(self):
        data_path = os.environ.get("DATA_PATH")
        assert data_path is not None, "DataImporter: DATA_PATH environment variable not set."

        self._data_path: str = data_path
        self._data: pd.DataFrame = pd.DataFrame()

    def import_data(self) -> pd.DataFrame:
        """
        Imports data from a CSV file.

        Returns:
            pd.DataFrame: The imported data as a pandas DataFrame.

        Raises:
            FileNotFoundError: If the dataset file is not found.
        """

        try:
            text_field_types = {0: str, 1: str}
            data: pd.DataFrame = pd.read_csv(
                self._data_path, header=None, dtype=text_field_types)

            self._data = data

            return self._data
        except FileNotFoundError:
            raise FileNotFoundError("DataImporter: Dataset file not found.")

    def normalize_data(self) -> pd.DataFrame:
        """
        Normalizes the data.

        Returns:
            pd.DataFrame: The normalized data as a pandas DataFrame.
        """

        # Exclude the first column (M/B)
        data_to_normalize = self._data.iloc[:, 2:]

        # Apply min-max normalization manually
        normalized_data = (data_to_normalize - data_to_normalize.min()) / \
            (data_to_normalize.max() - data_to_normalize.min())

        # # Concatenate the first column with the normalized data
        result = pd.concat([self._data.iloc[:, :2], normalized_data], axis=1)

        # return result
        return result
