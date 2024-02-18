from load_csv import load


def main():
    """
    This is the main function that loads and prints the contents of a CSV file.
    """
    print(load("life_expectancy_years.csv"))


if __name__ == "__main__":
    main()
