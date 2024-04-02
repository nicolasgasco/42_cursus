from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

HOUSE_COLUMN = "Hogwarts House"


class Plot:
    def __init__(self, data: pd.DataFrame):
        assert isinstance(
            data, pd.DataFrame) and not data.empty, "Data must be a non-empty DataFrame."

        assert data[HOUSE_COLUMN].nunique(
        ) == 4, "Data must contain all four Hogwarts Houses."

        self.data: pd.DataFrame = data
        self.houses = np.sort(data[HOUSE_COLUMN].unique())
        self.house_colors = {
            "Gryffindor": "#ae0001",
            "Hufflepuff": "#ecb939",
            "Ravenclaw": "#222f5b",
            "Slytherin": "#2a623d"
        }

    # TODO refactor this to util function
    def _get_valid_entries(self, values):
        return [value for value in values
                if pd.notnull(value) and pd.notna(value)]

    def plot_score_distribution(self):
        columns = self.data.columns.values[6:]  # Remove unrelevant columns

        n_rows = len(columns)
        n_cols = len(self.houses)

        num_bins = 20
        figure_height = 5 * n_rows

        _, axs = plt.subplots(
            n_rows, n_cols, figsize=(num_bins, figure_height))

        for y, subject in enumerate(columns):

            sorted_data = self.data[subject].sort_values()

            min_score = sorted_data.min()
            max_score = sorted_data.max()

            for x, house in enumerate(self.houses):
                is_current_house: bool = self.data[HOUSE_COLUMN] == house
                house_data = self._get_valid_entries(
                    sorted_data[is_current_house])

                axs[y][x].hist(house_data, bins=num_bins,
                               color=self.house_colors[house])
                axs[y][x].set_title(f'{subject} ({house})')
                axs[y][x].set_xlabel("Score")
                axs[y][x].set_ylabel("Frequency")

                axs[y][x].set_xlim(min_score, max_score)

        plt.tight_layout()
        plt.savefig("plots/subjects_score_distribution.png")
