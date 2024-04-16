import sys as sys


def main():
    argc = len(sys.argv)

    if argc != 2:
        raise ValueError("Usage: python3 logreg_train.py <dataset>")


if __name__ == "__main__":
    main()
