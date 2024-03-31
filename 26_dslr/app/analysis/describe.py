from Describer import Describer

import pandas as pd
import sys as sys


def main():
    argc = len(sys.argv)
    argv = sys.argv

    if argc != 2:
        print("Usage: python describe.py <filename>")
        exit(1)

    file_name = argv[1]

    data = pd.DataFrame()
    try:
        data = pd.read_csv(file_name)
    except FileNotFoundError:
        print("The file was not found.")
        exit(1)

    describer = Describer(data)

    describer.describe()


if __name__ == "__main__":
    main()
