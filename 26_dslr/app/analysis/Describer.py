import numpy as np
import pandas as pd


class Describer:
    def __init__(self, data):
        assert isinstance(
            data, pd.DataFrame), "Data must be a non-empty DataFrame."

        self._data = data
        self._stats = pd.DataFrame()

    def _get_columns(self, data):
        all_columns = data.columns
        columns = [column for column in all_columns
                   if data[column].dtype == 'int64'
                   or data[column].dtype == 'float64']

        columns = columns

        return columns

    def _get_valid_entries(self, values):
        return [value for value in values
                if pd.notnull(value) and pd.notna(value)]

    def _get_counts(self, data, columns):
        counts = []
        for column in columns:
            valid_entries = self._get_valid_entries(data[column].values)

            len_valid_entries = len(valid_entries)

            counts.append(len_valid_entries)

        return counts

    def _get_mins(self, data, columns):
        min_values = []
        for column in columns:
            values = data[column].values
            min_value = values[0]

            for value in values:
                if value < min_value:
                    min_value = value

            min_values.append(min_value)

        return min_values

    def _get_maxes(self, data, columns):
        max_values = []
        for column in columns:
            values = data[column].values
            max_value = values[0]

            for value in values:
                if value > max_value:
                    max_value = value

            max_values.append(max_value)

        return max_values

    def _get_means(self, data, columns):
        means = []

        for column in columns:
            values = data[column].values
            valid_values = self._get_valid_entries(values)

            if len(valid_values) == 0:
                means.append(np.nan)
                continue

            mean = sum(valid_values) / len(valid_values)
            means.append(mean)

        return means

    def _get_stds(self, data, columns):
        stds = []

        for column in columns:
            values = data[column].values
            valid_values = self._get_valid_entries(values)

            if len(valid_values) == 0:
                stds.append(np.nan)
                continue

            mean = sum(valid_values) / len(valid_values)
            squared_diffs = [(value - mean) ** 2 for value in valid_values]
            variance = sum(squared_diffs) / len(squared_diffs)
            std = variance ** 0.5

            stds.append(std)

        return stds

    def _get_first_quartiles(self, data, columns):
        quartiles = []

        for column in columns:
            values = data[column].sort_values().values
            valid_values = self._get_valid_entries(values)

            if len(valid_values) == 0:
                quartiles.append(np.nan)
                continue

            first_quartile_index = (len(valid_values) + 1) // 4
            first_quartile_value = valid_values[first_quartile_index - 1]

            quartiles.append(first_quartile_value)

        return quartiles

    def _get_second_quartiles(self, data, columns):
        quartiles = []

        for column in columns:
            values = data[column].sort_values().values
            valid_values = self._get_valid_entries(values)

            if len(valid_values) == 0:
                quartiles.append(np.nan)
                continue

            second_quartile_index = (len(valid_values) + 1) // 2
            second_quartile_value = valid_values[second_quartile_index - 1]

            quartiles.append(second_quartile_value)

        return quartiles

    def _get_third_quartiles(self, data, columns):
        quartiles = []

        for column in columns:
            values = data[column].sort_values().values
            valid_values = self._get_valid_entries(values)

            if len(valid_values) == 0:
                quartiles.append(np.nan)
                continue

            third_quartile_index = 3 * (len(valid_values) + 1) // 4
            third_quartile_value = valid_values[third_quartile_index - 1]

            quartiles.append(third_quartile_value)

        return quartiles

    def describe(self):
        columns = self._get_columns(self._data)

        table_columns = [''] + columns
        self._stats = pd.DataFrame(columns=table_columns)

        counts = self._get_counts(self._data, columns)
        self._stats.loc[0] = ['count'] + counts

        means = self._get_means(self._data, columns)
        self._stats.loc[1] = ['mean'] + means

        stds = self._get_stds(self._data, columns)
        self._stats.loc[2] = ['std'] + stds

        min_values = self._get_mins(self._data, columns)
        self._stats.loc[3] = ['min'] + min_values

        first_quartiles = self._get_first_quartiles(self._data, columns)
        self._stats.loc[4] = ['25%'] + first_quartiles

        second_quartiles = self._get_second_quartiles(self._data, columns)
        self._stats.loc[5] = ['50%'] + second_quartiles

        third_quartiles = self._get_third_quartiles(self._data, columns)
        self._stats.loc[6] = ['75%'] + third_quartiles

        max_values = self._get_maxes(self._data, columns)
        self._stats.loc[7] = ['max'] + max_values

        print(self._stats.to_string(index=False))

        print(self._data.describe())
