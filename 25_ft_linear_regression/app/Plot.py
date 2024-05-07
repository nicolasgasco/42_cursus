import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import pandas as pd


class Plot:
    def __init__(self, data: pd.DataFrame, theta0: float, theta1: float):
        self._theta0, self._theta1 = theta0, theta1

        self._data: pd.DataFrame = data

        self._labels: dict = {
            'x_label': 'Mileage',
            'y_label': 'Price',
            'title': 'Mileage vs Price'
        }

    def generate_plot(self, linear_regression=False):
        """
        Display the scatter plot of the data.

        Args:
            linear_regression (bool, optional): Whether to plot the linear \
            regression line. Defaults to False.
        """

        def _plot_linear_regression(x_data: pd.Series):
            """
            Plot the linear regression line.

            Args:
                x_data (numpy.ndarray): The input x data.

            Returns:
                None
            """

            estimated_y_data: pd.Series = self._theta0 + self._theta1 * x_data

            plt.plot(x_data, estimated_y_data, 'y-')

        x_data: pd.Series = self._data['km']
        y_data: pd.Series = self._data['price']

        plt.clf()  # Reset plot options
        plt.title(self._labels['title'])
        plt.scatter(x_data, y_data)
        plt.xlabel(self._labels['x_label'])
        plt.ylabel(self._labels['y_label'])

        # Format number on both axes
        formatter = ticker.FuncFormatter(lambda x, pos: f'{x/1000:.0f}k')
        plt.gca().xaxis.set_major_formatter(formatter)
        plt.gca().yaxis.set_major_formatter(formatter)

        plt.grid(True, which='both', linestyle='--', linewidth=0.5)

        if (linear_regression):
            _plot_linear_regression(x_data)

        plot_name: str = self._labels['title'].lower().replace(' ', '_')
        plot_name += '-linear_regression' if linear_regression else ''
        plot_name += '.png'

        plt.savefig(f"/ft_linear_regression/app/plots/{plot_name}",
                    bbox_inches='tight', pad_inches=0, dpi=500)
