import os as os
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from colorama import Fore, Style

PLOTS_DIR = "/multilayer_perceptron/app/plots"


class DataPlotter:
    def __init__(self, data: pd.DataFrame):
        self._data: pd.DataFrame = data
        assert self._data is not None, "DataPlotter: data is None."

    def histograms(self) -> None:
        """
        Create histograms for numeric data.

        This method creates histograms for each numeric column in the dataset.
        The histograms are saved as a PNG file.

        Returns:
            None
        """
        print("Creating histograms...")

        numeric_data = self._data.iloc[:, 2:]

        num_plots = len(numeric_data.columns)
        num_columns = 8
        num_rows = np.ceil(num_plots / num_columns).astype(int)

        fig, axs = plt.subplots(num_rows, num_columns, figsize=(
            24, 4*num_rows))

        axs = axs.flatten()

        for i, column in enumerate(numeric_data.columns):
            ax = axs[i]
            ax.hist(self._data[self._data.iloc[:, 1] == 'M']
                    [column], color='red', alpha=0.5, label='M')
            ax.hist(self._data[self._data.iloc[:, 1] == 'B']
                    [column], color='blue', alpha=0.5, label='B')
            ax.set_title(column)
            ax.set_xlabel(column)
            ax.set_ylabel('Frequency')
            ax.legend()

        for i in range(num_plots, num_rows*num_columns):
            axs[i].axis('off')

        plt.tight_layout()
        file_name = os.path.join(PLOTS_DIR, 'histograms.png')
        plt.savefig(file_name)
        plt.close()

        print(
            f"Histograms saved to {Fore.YELLOW}{file_name}{Style.RESET_ALL}")

    def pair_plot(self) -> None:
        """
            Create a pair plot of the data.

            This method generates a pair plot using seaborn library
            to visualize the relationships between pair
            of variables in the data.

            Returns:
            None
            """

        print("Creating pair plot...")

        column_name = self._data.columns[1]
        column_unique = self._data[column_name].unique()
        plot = sns.pairplot(self._data, hue=column_name,
                            palette={column_unique[0]: 'red',
                                     column_unique[1]: 'blue'},
                            plot_kws={'alpha': 0.5},
                            diag_kind='hist',
                            corner=True)

        print("Saving pair plot...")
        filename = os.path.join(PLOTS_DIR, "pair_plot.png")
        plot.savefig(filename)

        print(f"Pair plot saved to {Fore.YELLOW}{filename}{Style.RESET_ALL}")

    def correlation_matrix(self) -> None:
        """
        Create a correlation matrix plot of the data.

        This method generates a correlation matrix plot using seaborn library
        to visualize the relationships between pair of variables in the data.

        Returns:
        None
        """

        print("Creating correlation matrix plot...")

        numeric_values = self._data.iloc[:, 2:]

        correlation_matrix = numeric_values.corr()

        plt.figure(figsize=(75, 75))

        plot = sns.heatmap(correlation_matrix, annot=True,
                           cmap='coolwarm', annot_kws={"size": 24})
        plt.tight_layout()

        print("Saving correlation matrix plot...")
        filename = os.path.join(PLOTS_DIR, "correlation_matrix.png")
        plot.get_figure().savefig(filename)

        print(
            f"Correlation matrix plot saved to {Fore.YELLOW}{filename}{Style.RESET_ALL}")
