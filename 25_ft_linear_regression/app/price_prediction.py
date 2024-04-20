from PriceEstimator import PriceEstimator

from colorama import Fore, Style
import pandas as pd


def get_mileage_input() -> int:
    """
    Get the mileage input from the user.

    Returns:
        int: The mileage value entered by the user.
    """

    while True:
        user_input: str = input(
            "\nEnter the mileage (integer value, no separator): ")

        try:
            mileage: int = int(user_input)

            if (mileage < 0):
                raise ValueError()
            break
        except ValueError:
            print(f"{Fore.RED}Please enter a valid value.{Style.RESET_ALL}")

    return mileage


def main():
    theta0, theta1 = 0.0, 0.0

    try:
        thetas_df = pd.read_csv('../data/thetas.csv')
        theta0: float = thetas_df['theta0'].values[0]
        theta1: float = thetas_df['theta1'].values[0]

        print("Thetas loaded from thetas.csv.",
              f"\nTheta0: {Fore.GREEN}{theta0:.2f}{Style.RESET_ALL}",
              f"\nTheta1: {Fore.GREEN}{theta1:.6f}{Style.RESET_ALL}")

    except FileNotFoundError:
        print(f"{Fore.RED}File thetas.csv not found.",
              f"Using default values for theta0 and theta1.{Style.RESET_ALL}")

    price_estimator = PriceEstimator(theta0, theta1)

    print("\nPress Ctrl+C to exit the program.")
    try:
        while True:
            mileage: int = get_mileage_input()

            estimate: float = price_estimator.estimate(mileage)

            print(
                f"\nThe estimated price for {mileage:,} km is ",
                f"{Fore.YELLOW}{estimate:,.2f}{Style.RESET_ALL}")

    except KeyboardInterrupt:
        print("\n\nGoodbye!")


if __name__ == "__main__":
    main()
