import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker


class Plot:
    def __init__(self, theta0, theta1):
        self._theta0 = theta0
        self._theta1 = theta1

        self._data = self._prepare_data()

        self._labels = {
            'x_label': 'Mileage',
            'y_label': 'Price',
            'title': 'Mileage vs Price'
        }

    def _prepare_data(self):
        """
        Reads the data from a CSV file and sorts it by the 'km' column.

        Returns:
            pandas.DataFrame: The sorted data.
        """
        data = pd.read_csv("../data.csv")
        data = data.sort_values(by='km')

        return data

    def _plot_linear_regression(self, x_data):
        """
        Plot the linear regression line.

        Args:
            x_data (numpy.ndarray): The input x data.

        Returns:
            None
        """

        scaled_x_data = x_data / 1_000
        scaled_estimated_y_data = self._theta0 + self._theta1 * scaled_x_data

        estimated_y_data = scaled_estimated_y_data * 1_000

        plt.plot(x_data, estimated_y_data, 'y-')

    def show(self, linear_regression=False):
        """
        Display the scatter plot of the data.

        Args:
            linear_regression (bool, optional): Whether to plot the linear \
            regression line. Defaults to False.
        """

        x_data = self._data['km']
        y_data = self._data['price']

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
            self._plot_linear_regression(x_data)

        plot_name = self._labels['title'].lower().replace(' ', '_')
        plot_name += '-linear_regression' if linear_regression else ''
        plot_name += '.png'

        plt.savefig(plot_name, bbox_inches='tight', pad_inches=0, dpi=500)
