from colorama import Fore, Style
import pandas as pd
import sys as sys

from LogisticRegression import LogisticRegression


def main():
    argc = len(sys.argv)

    if argc != 3:
        raise ValueError("Usage: python3 logreg_predict.py <dataset> <params>")

    dataset_file_path = sys.argv[1]
    try:
        test_set = pd.read_csv(dataset_file_path)
    except FileNotFoundError:
        raise FileNotFoundError("Dataset file not found.")

    prediction_params_file_path = sys.argv[2]

    try:
        prediction_params = pd.read_csv(prediction_params_file_path)
    except FileNotFoundError:
        print(Fore.RED,
              "Prediction parameters file not found. Train the model first.",
              Style.RESET_ALL)
        sys.exit(1)

    regression = LogisticRegression(test_set, should_fill_na=True)
    regression.predict(prediction_params)


if __name__ == "__main__":
    main()
