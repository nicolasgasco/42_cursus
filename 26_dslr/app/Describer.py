import pandas as pd


class Describer:
    def __init__(self):
        self._data = pd.DataFrame()
        self._stats = pd.DataFrame()

    def load_data(self, file_name):
        try:
            self._data = pd.read_csv(file_name)
        except FileNotFoundError:
            print("The file was not found.")
            exit(1)

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

            mean = sum(valid_values) / len(valid_values)
            means.append(mean)

        return means

    def _get_stds(self, data, columns):
        stds = []

        for column in columns:
            values = data[column].values
            valid_values = self._get_valid_entries(values)

            mean = sum(valid_values) / len(valid_values)
            squared_diffs = [(value - mean) ** 2 for value in valid_values]
            variance = sum(squared_diffs) / len(squared_diffs)
            std = variance ** 0.5

            stds.append(std)

        return stds

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

        max_values = self._get_maxes(self._data, columns)
        self._stats.loc[4] = ['max'] + max_values

        print(self._stats)
        print(self._data.describe())
