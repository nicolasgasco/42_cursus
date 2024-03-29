from LinearRegression import LinearRegression
from Plot import Plot
from PriceEstimator import PriceEstimator
import time as time


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


def main():
    start = time.time()

    linear_regression = LinearRegression()

    print("Training linear regression model... (this might take longer)")
    theta0, theta1 = linear_regression.fit()
    price_estimator = PriceEstimator(theta0, theta1)

    print("\nPlotting the data and linear regression line...")
    plot = Plot(theta0, theta1)
    plot.show(linear_regression=True)

    elapsed_time = time.time() - start
    formatted_elapsed_time = time.strftime("%S", time.gmtime(elapsed_time))
    print(f"\nOperation compled in {formatted_elapsed_time} seconds")

    print("\nPress Ctrl+C to exit the program.")

    try:
        while True:
            mileage = get_mileage_input()

            estimate = price_estimator.estimate(mileage)

            print(
                f"\nThe estimated price for {mileage:,} km is {estimate:.2f}")
    except KeyboardInterrupt:
        print("\nGoodbye!")


if __name__ == "__main__":
    main()
