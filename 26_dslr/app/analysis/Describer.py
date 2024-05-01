import numpy as np
import pandas as pd


class Describer:
    def __init__(self, data: pd.DataFrame):
        assert isinstance(
            data, pd.DataFrame), "Data must be a non-empty DataFrame."

        self._data: pd.DataFrame = data
        self._stats: pd.DataFrame | None = None

    def _get_columns(self, data: pd.DataFrame):
        all_columns: pd.Index[str] = data.columns
        columns: list[str] = [column for column in all_columns
                              if data[column].dtype == 'int64'
                              or data[column].dtype == 'float64']

        columns = columns

        return columns

    def _get_valid_entries(self, values):
        return [value for value in values
                if pd.notnull(value) and pd.notna(value)]

    def _calc_count(self, entries: list[float]):
        return len(entries)

    def _calc_mean(self, valid_entries: list[float]):
        if len(valid_entries) == 0:
            return np.nan

        return sum(valid_entries) / len(valid_entries)

    def _calc_std(self, valid_entries: list[float]):
        if len(valid_entries) == 0:
            return np.nan

        mean: float = self._calc_mean(valid_entries)
        squared_diffs: list[float] = [(x - mean) ** 2.0 for x in valid_entries]
        variance: float = sum(squared_diffs) / (len(squared_diffs) - 1)
        std: float = variance ** 0.5

        return std

    def _calc_min(self, valid_entries: list[float]):
        if len(valid_entries) == 0:
            return np.nan

        min_value: float = valid_entries[0]

        for value in valid_entries:
            if value < min_value:
                min_value = value

        return min_value

    def _calc_quantile(self, valid_entries: list[float], quantile: float):
        if len(valid_entries) == 0:
            return np.nan

        index_float: float = (len(valid_entries) - 1) * quantile
        lower_index: int = int(index_float)
        upper_index: int = int(index_float + 1)

        is_integer: bool = index_float == lower_index
        if is_integer:
            return valid_entries[lower_index]
        else:
            mean: float = (valid_entries[lower_index] +
                           valid_entries[upper_index]) / 2.0
            return mean

    def _calc_max(self, valid_entries):
        if len(valid_entries) == 0:
            return np.nan

        max_value: float = valid_entries[0]

        for value in valid_entries:
            if value > max_value:
                max_value: float = value

        return max_value

    def describe(self):
        columns = self._get_columns(self._data)

        stats_values: dict[str, list[str | float]] = {
            '': ['count', 'mean', 'std', 'min', '25%', '50%', '75%', 'max'],
        }

        for column in columns:
            valid_entries: list[float] = self._get_valid_entries(
                self._data[column].values)
            sorted_entries: list[float] = sorted(valid_entries)

            count: float = self._calc_count(sorted_entries)
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
