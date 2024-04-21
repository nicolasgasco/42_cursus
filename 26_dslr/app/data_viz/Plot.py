from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

HOUSE_COLUMN = "Hogwarts House"


class Plot:
    def __init__(self, data: pd.DataFrame):
        self._validate_inputs(data)

        self.columns = data.columns.values[6:]  # Remove unrelevant columns
        self.data: pd.DataFrame = data
        self.houses: list[str] = np.sort(data[HOUSE_COLUMN].unique()).tolist()
        self.house_colors = {
            "Gryffindor": "#ae0001",
            "Hufflepuff": "#ecb939",
            "Ravenclaw": "#222f5b",
            "Slytherin": "#2a623d"
        }

    def _validate_inputs(self, data: pd.DataFrame):
        assert isinstance(
            data, pd.DataFrame) and not data.empty, "Data must be a non-empty DataFrame."

        assert data[HOUSE_COLUMN].nunique(
        ) == 4, "Data must contain all four Hogwarts Houses."

    def _get_valid_entries(self, values):
        return [value for value in values
                if pd.notnull(value) and pd.notna(value)]

    def _save_plot(self, filename):
        PLOTS_PATH = "/dslr/app/data_viz/plots/"
        file_path = PLOTS_PATH + filename
        plt.tight_layout()
        plt.savefig(file_path)
        plt.close()

        print(f"Plot saved successfully: {file_path}")

    def plot_score_distribution(self, subject: str):
        sorted_data = self.data[subject].sort_values()

        num_bins = 20

        min_score: float = sorted_data.min()
        max_score: float = sorted_data.max()

        for x, house in enumerate(self.houses):
            is_current_house = self.data[HOUSE_COLUMN] == house
            house_data = self._get_valid_entries(
                sorted_data[is_current_house])

            plt.hist(house_data, bins=num_bins,
                     color=self.house_colors[house], alpha=0.5)
            plt.title(f'{subject} ({house})')
            plt.xlabel("Score")
            plt.ylabel("Frequency")

            plt.xlim(min_score, max_score)

        serialized_subject = subject.replace(" ", "_").lower()
        self._save_plot(f"score_distribution_{serialized_subject}.png")

    def plot_score_distributions(self):
        n_rows: int = len(self.columns)
        n_cols: int = len(self.houses)

        num_bins = 20
        figure_height = 3 * n_rows

        _, axs = plt.subplots(
            n_rows, n_cols, figsize=(num_bins, figure_height))

        for y, subject in enumerate(self.columns):

            sorted_data = self.data[subject].sort_values()

            min_score: float = sorted_data.min()
            max_score: float = sorted_data.max()

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

        self._save_plot("score_distribution.png")

    def _plot_histogram_grid(self, n_rows, n_cols, plot_data, axs):
        for y in range(n_rows):
            for x in range(n_cols):
                no_data_to_plot: bool = len(plot_data) == 0
                if (no_data_to_plot):
                    axs[y][x].set_visible(False)
                    continue

                all_data = plot_data.pop(0)
                for data in all_data:
                    axs[y][x].scatter(data["subj_data"], data["other_subj_data"],
                                      color=self.house_colors[data["house"]],
                                      alpha=0.5)
                    axs[y][x].set_title(
                        f'{data["subj"]} vs {data["other_subj"]}')

    def plot_features_similarity(self):
        n_rows, n_cols = 8, 10
        _, axs = plt.subplots(n_rows, n_cols, figsize=(75, 40))

        plot_data = []
        for subject in self.columns:
            for other_subject in self.columns:
                is_same_subject: bool = subject == other_subject
                if is_same_subject:
                    break

                single_plot_data = []
                for house in self.houses:
                    is_curr_house: bool = self.data[HOUSE_COLUMN] == house

                    subj_data = self.data[subject][is_curr_house]
                    other_subj_data = self.data[other_subject][is_curr_house]

                    single_plot_data.append({"subj_data": subj_data,
                                             "subj": subject,
                                             "other_subj_data": other_subj_data,
                                             "other_subj": other_subject,
                                             "house": house})
                plot_data.append(single_plot_data)

        self._plot_histogram_grid(n_rows, n_cols, plot_data, axs)
        self._save_plot("subjects_similarity.png")

    def plot_pair_matrix(self):
        n = len(self.columns)

        _, axs = plt.subplots(n, n, figsize=(75, 40))

        for y, subject in enumerate(self.columns):
            for x, other_subject in enumerate(self.columns):
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

        self._save_plot("pair_plot_matrix.png")
