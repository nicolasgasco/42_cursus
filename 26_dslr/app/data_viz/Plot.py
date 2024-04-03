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
        figure_height = 3 * n_rows

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
        plt.close()

    def plot_features_similarity(self):
        columns = self.data.columns.values[6:]  # Remove unrelevant columns
        n = len(columns)

        _, axs = plt.subplots(n, n, figsize=(75, 40))

        for y, subject in enumerate(columns):
            for x, other_subject in enumerate(columns):
                is_same_subject: bool = subject == other_subject
                if is_same_subject:
                    axs[y][x].set_visible(False)  # Hide the plot
                    continue

                for house in self.houses:
                    is_curr_house: bool = self.data[HOUSE_COLUMN] == house

                    subj_data = self.data[subject][is_curr_house]
                    other_subj_data = self.data[other_subject][is_curr_house]

                    axs[y][x].scatter(subj_data, other_subj_data,
                                      color=self.house_colors[house],
                                      alpha=0.5)

                font_size = 16
                if x == 0:
                    axs[y][x].set_ylabel(subject, fontsize=font_size)

                if y == n - 1:
                    axs[y][x].set_xlabel(other_subject, fontsize=font_size)

        plt.tight_layout()
        plt.savefig("plots/subjects_similarity.png")
        plt.close()

    def plot_pair_matrix(self):
        columns = self.data.columns.values[6:]  # Remove unrelevant columns
        n = len(columns)

        _, axs = plt.subplots(n, n, figsize=(75, 40))

        for y, subject in enumerate(columns):
            for x, other_subject in enumerate(columns):
                is_same_subject: bool = subject == other_subject

                for house in self.houses:
                    is_curr_house: bool = self.data[HOUSE_COLUMN] == house
                    subj_data = self.data[subject][is_curr_house]

                    if is_same_subject:
                        axs[y][x].hist(
                            subj_data, color=self.house_colors[house],
                            alpha=0.4)
                        continue

                    other_subj_data = self.data[other_subject][is_curr_house]
                    axs[y][x].scatter(subj_data, other_subj_data,
                                      color=self.house_colors[house],
                                      alpha=0.4)

                font_size = 16
                if x == 0:
                    axs[y][x].set_ylabel(subject, fontsize=font_size)

                if y == n - 1:
                    axs[y][x].set_xlabel(other_subject, fontsize=font_size)

        plt.tight_layout()
        plt.savefig("plots/pair_plot_matrix.png")
        plt.close()
