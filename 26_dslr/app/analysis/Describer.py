import numpy as np
import pandas as pd


class Describer:
    def __init__(self, data: pd.DataFrame):
        assert isinstance(
            data, pd.DataFrame), "Data must be a non-empty DataFrame."

        self._data: pd.DataFrame = data
        self._stats: pd.DataFrame | None = None

    def _calc_mean(self, entries: list[float]) -> float:
        """
        Calculates the mean of a list of valid entries.

        Args:
            entries (list[float]): A list of valid entries.

        Returns:
            float: The mean of the valid entries. If the list is empty,
            returns NaN.
        """

        if len(entries) == 0:
            return np.nan

        return sum(entries) / len(entries)

    def _calc_std(self, entries: list[float]) -> float:
        """
        Calculate the standard deviation of a list of valid entries.

        Args:
            entries (list[float]): A list of valid entries.

        Returns:
            float: The standard deviation of the valid entries.
        """
        if len(entries) == 0:
            return np.nan

        mean: float = self._calc_mean(entries)

        squared_diffs: list[float] = [(x - mean) ** 2.0 for x in entries]

        variance: float = sum(squared_diffs) / (len(squared_diffs) - 1)

        return variance ** 0.5

    def _calc_min(self, entries: list[float]) -> float:
        """
        Calculates the minimum value from a list of entries.

        Args:
            entries (list[float]): A list of numerical entries.

        Returns:
            float: The minimum value from the list of entries.
            If the list is empty, returns NaN.
        """
        if len(entries) == 0:
            return np.nan

        return sorted(entries)[0]

    def _calc_quantile(self, entries: list[float], quantile: float) -> float:
        """
        Calculate the quantile value for a given list of entries and quantile.

        Args:
            entries (list[float]): The list of entries.
            quantile (float): The quantile value (between 0 and 1).

        Returns:
            float: The calculated quantile value.

        Raises:
            None

        """
        if len(entries) == 0:
            return np.nan

        index_fraction: float = (len(entries) - 1.0) * quantile
        lower_index: int = int(index_fraction)
        upper_index: int = int(index_fraction + 1)

        is_integer_index: bool = index_fraction == lower_index
        if is_integer_index:
            return entries[lower_index]
        else:
            fraction: float = index_fraction - lower_index
            interpolation = entries[lower_index] * \
                (1 - fraction) + entries[upper_index] * fraction

            return interpolation

    def _calc_max(self, entries: list[float]) -> float:
        """
        Calculates the maximum value from a list of entries.

        Args:
            entries (list[float]): A list of floating-point numbers.

        Returns:
            float: The maximum value from the list.
            If the list is empty, returns NaN.
        """
        if len(entries) == 0:
            return np.nan

        return sorted(entries)[-1]

    def describe(self) -> None:
        """
        Generate descriptive statistics of the numeric columns in the dataset.

        This method calculates various statistical measures
        such as count, mean, standard deviation,
        minimum, first quartile, median, third quartile,
        and maximum for each numeric column in the dataset.
        The calculated statistics are stored in a pandas DataFrame
        and printed to the console.

        Returns:
            None
        """

        columns: list[str] = [column for column in self._data.columns
                              if self._data[column].dtype == 'int64'
                              or self._data[column].dtype == 'float64']

        stats_values: dict[str, list[str | float]] = {
            '': ['count', 'mean', 'std', 'min', '25%', '50%', '75%', 'max'],
        }

        for column in columns:
            entries = self._data[column].values
            valid_entries = [value for value in entries
                             if pd.notnull(value) and pd.notna(value)]
            sorted_entries: list[float] = sorted(valid_entries)

            count: float = len(sorted_entries)

            mean: float = self._calc_mean(sorted_entries)
            std: float = self._calc_std(sorted_entries)

            min: float = self._calc_min(sorted_entries)

            first_quantile: float = self._calc_quantile(sorted_entries, 0.25)
            second_quantile: float = self._calc_quantile(sorted_entries, 0.50)
            third_quantile: float = self._calc_quantile(sorted_entries, 0.75)

            max: float = self._calc_max(sorted_entries)

            stats_values[column] = [count, mean, std, min,
                                    first_quantile, second_quantile,
                                    third_quantile, max]

        self._stats = pd.DataFrame(stats_values)

        print(self._stats.to_string(index=False))
