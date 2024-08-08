import os as os
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from colorama import Fore, Style

PLOTS_DIR = "/multilayer_perceptron/app/plots"


class DataPlotter:
    def __init__(self, data: pd.DataFrame = None):
        self.__data: pd.DataFrame = data if data is not None else None

        self.__ax = None
        self.__fig = None
        self.__line = None

        self.__epochs = []
        self.__values = []

        self.__is_loss = True

    def histograms(self) -> None:
        """
        Create histograms for numeric data.

        This method creates histograms for each numeric column in the dataset.
        The histograms are saved as a PNG file.

        Returns:
            None
        """
        print("Creating histograms...")

        numeric_data = self.__data.iloc[:, 2:]

        num_plots = len(numeric_data.columns)
        num_columns = 8
        num_rows = np.ceil(num_plots / num_columns).astype(int)

        _, axs = plt.subplots(num_rows, num_columns, figsize=(
            24, 4*num_rows))

        axs = axs.flatten()

        for i, column in enumerate(numeric_data.columns):
            ax = axs[i]
            ax.hist(self.__data[self.__data.iloc[:, 1] == 'M']
                    [column], color='red', alpha=0.5, label='M')
            ax.hist(self.__data[self.__data.iloc[:, 1] == 'B']
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

        column_name = self.__data.columns[1]
        column_unique = self.__data[column_name].unique()
        plot = sns.pairplot(self.__data, hue=column_name,
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

        numeric_values = self.__data.iloc[:, 2:]

        correlation_matrix = numeric_values.corr()

        plt.figure(figsize=(75, 75))

        plot = sns.heatmap(correlation_matrix, annot=True,
                           cmap='coolwarm', annot_kws={"size": 24})
        plt.tight_layout()

        print("Saving correlation matrix plot...")
        filename = os.path.join(PLOTS_DIR, "correlation_matrix.png")

        figure = plot.get_figure()

        if figure:
            figure.savefig(filename)

        print("Correlation matrix plot saved to", end=" ")
        print(f"{Fore.YELLOW}{filename}{Style.RESET_ALL}")

    def train_plot_init(self, is_loss: bool):
        """
        Initializes a plot for displaying loss or accuracy over epochs.

        Parameters:
        - is_loss (bool): Indicates whether the plot is for loss or accuracy.

        Returns:
        None
        """

        self.__is_loss = is_loss

        fig, ax = plt.subplots()
        ax.set_xlabel('Epoch')
        y_label = 'Loss' if is_loss else 'Accuracy'
        ax.set_ylabel(y_label)
        line, = ax.plot([], [], 'bo-', linewidth=0.5, markersize=0)
        legend = ['Loss'] if is_loss else ['Accuracy']
        ax.legend(legend)
        title = 'Loss vs Epoch' if is_loss else 'Accuracy vs Epoch'
        ax.set_title(title)
        ax.grid(linestyle='--', linewidth=0.5, color='lightgray')

        self.__ax = ax
        self.__line = line
        self.__fig = fig

    def train_plot_update(self, epoch: int, value: float):
        """
        Update the loss plot with a new epoch and corresponding loss value.
        Args:
            epoch (int): The epoch number.
            value (float): The loss value.
        Raises:
            AssertionError: If the loss plot is not initialized.
        """

        error_message = "Loss plot not initialized"
        assert self.__ax is not None, error_message
        assert self.__line is not None, error_message

        self.__epochs.append(epoch)
        self.__values.append(value)

        self.__line.set_xdata(self.__epochs)
        self.__line.set_ydata(self.__values)

        self.__ax.relim()
        self.__ax.autoscale_view()
        self.__fig.canvas.draw()
        self.__fig.canvas.flush_events()

    def train_plot_save(self):
        """
        Saves the plot as an image file.
        The plot can be either a loss plot or an accuracy plot,
        depending on the value of `self.__is_loss`.
        The image file is saved in the directory specified by `PLOTS_DIR`
        with the filename "loss.png" if `self.__is_loss` is True,
        or "accuracy.png" if `self.__is_loss` is False.
        Returns:
            None
        Raises:
            None
        """

        filename = "loss.png" if self.__is_loss else "accuracy.png"
        file_path = os.path.join(PLOTS_DIR, filename)
        self.__fig.savefig(file_path)
        self.__fig.canvas.flush_events()

        print(f"Plot saved to {Fore.YELLOW}{file_path}{Style.RESET_ALL}")
