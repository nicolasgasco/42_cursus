import pandas as pd
import sys as sys

from LogisticRegression import LogisticRegression


def main():
    argc = len(sys.argv)

    if argc != 2:
        raise ValueError("Usage: python3 logreg_train.py <dataset>")

    dataset_file_path = sys.argv[1]
    try:
        train_set = pd.read_csv(dataset_file_path)
    except FileNotFoundError:
        raise FileNotFoundError("Dataset file not found.")

    regression = LogisticRegression(train_set, should_fill_na=False)

    regression.train()


if __name__ == "__main__":
    main()
