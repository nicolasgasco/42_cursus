import pandas as pd
import sys as sys

from LogisticRegression import LogisticRegression


def main():
    argc = len(sys.argv)

    if argc != 3:
        raise ValueError("Usage: python3 logreg_predict.py <dataset> <params>")

    dataset_file_path = sys.argv[1]
    test_set = pd.read_csv(dataset_file_path)

    prediction_params_file_path = sys.argv[2]
    prediction_params = pd.read_csv(prediction_params_file_path)

    regression = LogisticRegression(test_set)
    regression.predict(prediction_params)


if __name__ == "__main__":
    main()
