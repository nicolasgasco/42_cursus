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
            print(
                f"{Fore.RED}",
                "Please enter a valid value (positive integer, no separators)",
                f"{Style.RESET_ALL}")

    return mileage


def main():
    theta0, theta1 = 0.0, 0.0

    try:
        thetas_df = pd.read_csv('/ft_linear_regression/data/thetas.csv')
        theta0: float = thetas_df['theta0'].values[0]
        theta1: float = thetas_df['theta1'].values[0]

        print("Thetas loaded from thetas.csv.",
              f"\nTheta0: {Fore.GREEN}{theta0:.2f}{Style.RESET_ALL}",
              f"\nTheta1: {Fore.GREEN}{theta1:.6f}{Style.RESET_ALL}")

    except FileNotFoundError:
        print(f"{Fore.RED}",
              "File thetas.csv not found.",
              "Defaulting theta0 and theta1 to 0.",
              f"{Style.RESET_ALL}")

    price_estimator = PriceEstimator(theta0, theta1)

    print("\n",
          "Press Ctrl+C to exit the program.")
    try:
        while True:
            mileage: int = get_mileage_input()

            estimate: float = price_estimator.estimate(mileage)

            print(
                "\n"
                "\t",
                "Estimated price for",
                f"{Fore.YELLOW}{mileage:,}{Style.RESET_ALL} km is",
                f"{Fore.GREEN}{estimate:,.2f}{Style.RESET_ALL}")

    except KeyboardInterrupt:
        print("\n\nGoodbye!")


if __name__ == "__main__":
    main()
