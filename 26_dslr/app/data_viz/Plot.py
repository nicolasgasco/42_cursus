from colorama import Fore, Style
from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

HOUSE_COLUMN_NAME = "Hogwarts House"

HOUSES_COLORS = {
    "Gryffindor": "#ae0001",
    "Hufflepuff": "#ecb939",
    "Ravenclaw": "#222f5b",
    "Slytherin": "#2a623d"
}


class Plot:
    def __init__(self, data: pd.DataFrame):
        self._validate_inputs(data)

        first_num_col_index = 6

        self.columns = data.columns.values[first_num_col_index:]

        normalized_num_data = self._normalize_data(
            data.iloc[:, first_num_col_index:])
        self.data: pd.DataFrame = pd.concat(
            [data.iloc[:, :6], normalized_num_data], axis=1)

        self.houses: list[str] = np.sort(
            data[HOUSE_COLUMN_NAME].unique()).tolist()
        self.houses_colors = HOUSES_COLORS

    def _validate_inputs(self, data: pd.DataFrame):
        """
        Validates the input data.

        Args:
          data (pd.DataFrame): The input data to be validated.

        Raises:
          AssertionError: If the data is not a non-empty DataFrame
          or if it does not contain all four Hogwarts Houses.
        """

        assert isinstance(data, pd.DataFrame), "Data must be a DataFrame."
        assert not data.empty, "Data must not be empty."

        assert data[HOUSE_COLUMN_NAME].nunique(
        ) == 4, "Data must contain all four Hogwarts Houses."

    def _normalize_data(self, data: pd.DataFrame) -> pd.DataFrame:
        """
        Normalize the given data using min-max scaling.

        Parameters:
        data (pd.DataFrame): The input data to be normalized.

        Returns:
        pd.DataFrame: The normalized data.
        """

        normalized_data: pd.DataFrame = (
            data - data.min()) / (data.max() - data.min())

        return normalized_data

    def _get_valid_entries(self, values: pd.Series) -> list:
        """
        Returns a list of valid entries from the given values.

        Parameters:
        values (list): A list of values to filter.

        Returns:
        list: A list of valid entries, where valid entries
        are non-null and non-NaN values.
        """

        valid_entries = [value for value in values
                         if pd.notnull(value) and pd.notna(value)]

        return valid_entries

    def _save_plot(self, filename: str):
        """
        Save the current plot to a file.

        Args:
          filename (str): The name of the file to save the plot to.

        Returns:
          None
        """
        PLOTS_PATH = "/dslr/app/data_viz/plots/"
        file_path = PLOTS_PATH + filename

        plt.tight_layout()
        plt.savefig(file_path)
        plt.close()

        print(f"{Fore.GREEN}Plot saved successfully: ",
              f"{file_path}{Style.RESET_ALL}")

    def plot_score_distribution(self, subject: str):
        """
        Plots the score distribution for a given subject.

        Args:
          subject (str): The subject
          for which the score distribution is plotted.

        Returns:
          None
        """

        sorted_data: pd.Series = self.data[subject].sort_values()

        num_bins: int = 20

        min_score: float = sorted_data.min()
        max_score: float = sorted_data.max()

        for house in self.houses:
            is_current_house = self.data[HOUSE_COLUMN_NAME] == house
            house_data: list[bool] = self._get_valid_entries(
                sorted_data[is_current_house])

            plt.hist(house_data, bins=num_bins,
                     color=self.houses_colors[house], alpha=0.5)
            plt.title(f'{subject}')
            plt.xlabel("Score")
            plt.ylabel("Frequency")
            plt.xlim(min_score, max_score)
            plt.legend(self.houses)

        serialized_subject = subject.replace(" ", "_").lower()
        self._save_plot(
            f"score_distribution/{serialized_subject}.png")

    def plot_score_distributions(self):
        """
        Plots the score distributions for each subject and house.

        This method generates a histogram
        for each subject and house combination,
        showing the distribution of scores.
        The histograms are plotted in a grid
        layout with the number of columns specified by `n_cols`.

        Returns:
          None
        """

        n_cols: int = 3
        n_rows: int = len(self.columns) // n_cols + 1

        num_bins: int = 20
        figure_height: int = 5 * n_rows
        _, axs = plt.subplots(
            n_rows, n_cols, figsize=(num_bins, figure_height))

        x: int = 0
        y: int = 0
        for subject in self.columns:

            sorted_data: pd.Series = self.data[subject].sort_values()

            min_score: float = sorted_data.min()
            max_score: float = sorted_data.max()

            for house in self.houses:
                is_current_house = self.data[HOUSE_COLUMN_NAME] == house
                house_data: list[bool] = self._get_valid_entries(
                    sorted_data[is_current_house])

                axs[y][x].hist(house_data, bins=num_bins,
                               color=self.houses_colors[house], alpha=0.5)
                axs[y][x].set_title(f'{subject}')
                axs[y][x].set_xlabel("Score")
                axs[y][x].set_ylabel("Frequency")
                axs[y][x].set_xlim(min_score, max_score)
                axs[y][x].legend(self.houses)

            x = (x + 1) % n_cols
            y = y + 1 if x == 0 else y

        # Hide remaining subplots
        for i in range(x, n_cols):
            axs[y][i].axis("off")

        self._save_plot("score_distribution.png")

    def _plot_scatter_grid(self, n_rows: int, n_cols: int,
                           plot_data: list, axs):
        """
        Plot scatter grid with multiple subplots.

        Args:
          n_rows (int): Number of rows in the grid.
          n_cols (int): Number of columns in the grid.
          plot_data (list): List of data to be plotted.
          axs: Axes objects for the subplots.

        Returns:
          None
        """

        for y in range(n_rows):
            for x in range(n_cols):
                no_data_to_plot: bool = len(plot_data) == 0
                if (no_data_to_plot):
                    axs[y][x].set_visible(False)
                    continue

                all_data: list = plot_data.pop(0)
                for data in all_data:
                    axs[y][x].scatter(data["subj_data"],
                                      data["other_subj_data"],
                                      color=self.houses_colors[data["house"]],
                                      alpha=0.5)
                    axs[y][x].set_title(
                        f'{data["subj"]} vs {data["other_subj"]}')
                    axs[y][x].legend(self.houses)

    def plot_similarities(self):
        """
        Plots the similarity between different features.

        This method generates a grid of histograms to visualize
        the similarity between different features.
        It iterates over each pair of features and each house,
        and plots the histograms of the feature values
        for each house. The resulting grid of histograms provides
        a visual representation of the similarity
        between different features.

        Parameters:
        None

        Returns:
        None
        """

        n_rows, n_cols = 8, 10
        _, axs = plt.subplots(n_rows, n_cols, figsize=(75, 40))

        plot_data: list = []
        for subject in self.columns:
            for other_subject in self.columns:
                is_same_subject: bool = subject == other_subject
                if is_same_subject:
                    break

                single_plot_data: list = []
                for house in self.houses:
                    is_curr_house = self.data[HOUSE_COLUMN_NAME] == house

                    subj_data: list[bool] = self.data[subject][is_curr_house]
                    other_subj_data = self.data[other_subject][is_curr_house]

                    single_plot_data.append({"subj_data": subj_data,
                                             "subj": subject,
                                             "other_subj_data": other_subj_data,
                                             "other_subj": other_subject,
                                             "house": house})
                plot_data.append(single_plot_data)

        self._plot_scatter_grid(n_rows, n_cols, plot_data, axs)
        self._save_plot("subjects_similarity.png")

    def plot_similarity(self, subject: str, other_subject: str):
        plt.figure(figsize=(10, 6))

        for house in self.houses:
            is_curr_house = self.data[HOUSE_COLUMN_NAME] == house
            subj_data = self.data[subject][is_curr_house]

            other_subj_data = self.data[other_subject][is_curr_house]
            plt.scatter(subj_data, other_subj_data,
                        color=self.houses_colors[house],
                        alpha=0.4)

            plt.ylabel(subject)
            plt.xlabel(other_subject)
            plt.legend(self.houses)

        serialized_subject = subject.replace(" ", "_").lower()
        serialized_other_subject = other_subject.replace(" ", "_").lower()
        self._save_plot("subject_similarity/" +
                        f"{serialized_subject}-{serialized_other_subject}.png")

    def plot_pair_matrix(self):
        """
        Plot a pair matrix of scatter plots and histograms.

        This method generates a pair matrix of scatter plots and histograms
        for each combination of columns in the dataset.
        The scatter plots show the relationship between two different columns,
        while the histograms show the distribution
        of a single column.

        Returns:
          None

        Raises:
          None
        """

        n: int = len(self.columns)

        _, axs = plt.subplots(n, n, figsize=(75, 40))

        for y, subject in enumerate(self.columns):
            for x, other_subject in enumerate(self.columns):
                is_same_subject: bool = subject == other_subject

                for house in self.houses:
                    is_curr_house = self.data[HOUSE_COLUMN_NAME] == house
                    subj_data: list[bool] = self.data[subject][is_curr_house]

                    if is_same_subject:
                        axs[y][x].hist(
                            subj_data, color=self.houses_colors[house],
                            alpha=0.4)
                        continue

                    other_subj_data = self.data[other_subject][is_curr_house]
                    axs[y][x].scatter(subj_data, other_subj_data,
                                      color=self.houses_colors[house],
                                      alpha=0.4)

                font_size: int = 16
                if x == 0:
                    axs[y][x].set_ylabel(subject, fontsize=font_size)

                if y == n - 1:
                    axs[y][x].set_xlabel(other_subject, fontsize=font_size)

        self._save_plot("pair_plot_matrix.png")
