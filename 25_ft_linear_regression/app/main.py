from LinearRegression import LinearRegression
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


def main():
    mileages = [1_000, 5_000, 10_000, 50_000, 80_000,
                81_000, 120_000, 150_000, 200_000, 300_000, 400_000]

    linear_regression = LinearRegression()

    theta0, theta1 = linear_regression.fit()

    for mileage in mileages:
        price_estimator = PriceEstimator(mileage, theta0, theta1)
        estimate = price_estimator.estimate_price()
        print(f"{mileage:,} km -> {estimate:.2f}")


if __name__ == "__main__":
    main()
