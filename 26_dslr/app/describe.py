from Describer import Describer

import sys as sys


def main():
    argc = len(sys.argv)
    argv = sys.argv

    if argc != 2:
        print("Usage: python describe.py <filename>")
        exit(1)

    file_name = argv[1]

    describer = Describer()

    describer.load_data(file_name)

    describer.describe()


if __name__ == "__main__":
    main()
