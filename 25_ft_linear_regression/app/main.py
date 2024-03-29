from LinearRegression import LinearRegression
from Plot import Plot
from PriceEstimator import PriceEstimator


def get_mileage_input():
    """
    Get the mileage input from the user.

    Returns:
        int: The mileage value entered by the user.
    """

    while True:
        user_input = input("Enter the mileage (integer value, no separator): ")

        try:
            mileage = int(user_input)
            break
        except ValueError:
            print("Please enter a valid value.")

    return mileage


TEST_MILEAGES = [1_000, 5_000, 10_000, 50_000, 80_000,
                 81_000, 120_000, 150_000, 200_000, 300_000, 400_000]


def main():
    linear_regression = LinearRegression()

    theta0, theta1 = linear_regression.fit()
    price_estimator = PriceEstimator(theta0, theta1)

    for mileage in TEST_MILEAGES:
        estimate = price_estimator.estimate(mileage)

        print(f"{mileage:,} km -> {estimate:.2f}")

    plot = Plot(theta0, theta1)
    plot.show(linear_regression=True)


if __name__ == "__main__":
    main()
