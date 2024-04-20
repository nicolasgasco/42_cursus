import pandas as pd
import time as time

from LinearRegression import LinearRegression
from Plot import Plot


def import_data() -> pd.DataFrame:
    """
    Import and preprocess the data from a CSV file.

    Returns:
        pandas.DataFrame: The preprocessed data.
    """

    data = pd.read_csv("data/data.csv")
    data = data.sort_values(by='km')

    return data


def show_elapsed_time(start):
    """
    Prints the elapsed time since the given start time.

    Parameters:
    start (float): The start time in seconds.

    Returns:
    None
    """

    elapsed_time: float = time.time() - start
    formatted_elapsed_time: str = "{:.2f}".format(elapsed_time)
    print(f"\nOperation completed in {formatted_elapsed_time} seconds")


def main():
    data: pd.DataFrame = import_data()

    start: float = time.time()

    linear_regression = LinearRegression(data)
    print("\nTraining linear regression model... (this might take long)")
    theta0, theta1 = linear_regression.fit()
    linear_regression.accuracy()

    print("\nPlotting the data and linear regression line...")
    plot = Plot(data, theta0, theta1)
    plot.generate_plot(linear_regression=True)

    show_elapsed_time(start)


if __name__ == "__main__":
    main()
