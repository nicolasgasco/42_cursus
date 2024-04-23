import pandas as pd
import sys as sys

from LogisticRegression import LogisticRegression


def main():
    argc = len(sys.argv)

    if argc != 2:
        raise ValueError("Usage: python3 logreg_train.py <dataset>")

    dataset_file_path = sys.argv[1]
    train_set = pd.read_csv(dataset_file_path)

    regression = LogisticRegression(train_set)

    regression.train()


if __name__ == "__main__":
    main()
