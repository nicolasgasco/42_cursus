import pandas as pd

DATA_PATH = "../../data/"

TRAIN_SET_FILENAME = "dataset_train.csv"
TEST_SET_FILENAME = "dataset_test.csv"


class DataImporter:
    def __init__(self):
        try:
            self.train_set = pd.read_csv(DATA_PATH + TRAIN_SET_FILENAME)
            self.test_set = pd.read_csv(DATA_PATH + TEST_SET_FILENAME)
        except FileNotFoundError:
            print("DataImporter: Error: file not found.")
            exit(1)

    def get_sets(self) -> tuple[pd.DataFrame, pd.DataFrame]:
        return self.train_set, self.test_set
