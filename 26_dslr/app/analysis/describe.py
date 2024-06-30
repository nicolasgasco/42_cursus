from Describer import Describer

import pandas as pd
import sys as sys


def main():
    argc: int = len(sys.argv)
    argv: list[str] = sys.argv

    if argc != 2:
        print("Usage: python describe.py <filename>")
        exit(1)

    file_name: str = argv[1]

    try:
        data: pd.DataFrame = pd.read_csv(file_name)
    except FileNotFoundError:
        print("The file was not found.")
        exit(1)

    print("My describe function:")
    describer = Describer(data)
    describer.describe()

    print("\n")

    print("Pandas describe function:")
    print(data.describe())


if __name__ == "__main__":
    main()
