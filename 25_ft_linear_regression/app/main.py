from LinearRegression import LinearRegression
from Plot import Plot
from PriceEstimator import PriceEstimator

from colorama import Fore, Style
import time as time
import pandas as pd


def get_mileage_input():
    """
    Get the mileage input from the user.

    Returns:
        int: The mileage value entered by the user.
    """

    while True:
        user_input = input(
            "\nEnter the mileage (integer value, no separator): ")

        try:
            mileage = int(user_input)
            break
        except ValueError:
            print("Please enter a valid value.")

    return mileage


def import_data():
    """
    Import and preprocess the data from a CSV file.

    Returns:
        pandas.DataFrame: The preprocessed data.
    """

    data = pd.read_csv("../data/data.csv")
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

    elapsed_time = time.time() - start
    formatted_elapsed_time = "{:.2f}".format(elapsed_time)
    print(f"\nOperation completed in {formatted_elapsed_time} seconds")


def estimate_user_input(price_estimator):
    """
    Estimates the price based on user input mileage.

    Args:
        price_estimator: An instance of the PriceEstimator class.

    Returns:
        None
    """

    mileage = get_mileage_input()

    estimate = price_estimator.estimate(mileage)

    print(f"\nThe estimated price for {mileage:,} km is {Fore.YELLOW}{estimate:,.2f}{Style.RESET_ALL}")


def main():
    start = time.time()

    data = import_data()

    linear_regression = LinearRegression(data)

    print("Training linear regression model... (this might take long)")
    theta0, theta1 = linear_regression.fit()
    linear_regression.accuracy()

    price_estimator = PriceEstimator(theta0, theta1)

    print("\nPlotting the data and linear regression line...")
    plot = Plot(data, theta0, theta1)
    plot.show(linear_regression=True)

    show_elapsed_time(start)

    print("\nPress Ctrl+C to exit the program.")

    try:
        while True:
            estimate_user_input(price_estimator)

    except KeyboardInterrupt:
        print("\nGoodbye!")


if __name__ == "__main__":
    main()
