import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

PLOTS_DIR = "/multilayer_perceptron/app/data_viz/plots"


class DataPlotter:
    def __init__(self, data: pd.DataFrame):
        self._data: pd.DataFrame = data
        assert self._data is not None, "DataPlotter: data is None."

    def histograms(self) -> None:
        print("Creating histograms...")

        numeric_data = self._data.iloc[:, 2:]

        fig, axs = plt.subplots(len(numeric_data.columns), figsize=(
            10, 6*len(numeric_data.columns)))

        for ax, column in zip(axs, numeric_data.columns):
            ax.hist(self._data[self._data.iloc[:, 1] == 'M']
                    [column], color='red', alpha=0.5, label='M')
            ax.hist(self._data[self._data.iloc[:, 1] == 'B']
                    [column], color='blue', alpha=0.5, label='B')
            ax.set_title(f'Histogram of {column}')
            ax.set_xlabel(column)
            ax.set_ylabel('Frequency')
            ax.legend()

        plt.tight_layout()
        plt.savefig(f'{PLOTS_DIR}/all_histograms.png')
        plt.close()

        print(f"Histograms saved to {PLOTS_DIR}/all_histograms.png")

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
        filename = PLOTS_DIR + "/pair_plot.png"
        plot.savefig(filename)

        print(f"Pair plot saved to {filename}")

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

        print("Saving correlation matrix plot...")
        filename = PLOTS_DIR + "/correlation_matrix.png"
        plot.get_figure().savefig(filename)

        print(f"Correlation matrix plot saved to {filename}")
