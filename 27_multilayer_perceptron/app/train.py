import pandas as pd

from src.DataImporter import DataImporter
from src.MultilayerPerceptron import MultilayerPerceptron


def main():
    train_data: pd.DataFrame = DataImporter.import_train_data()

    multilayer_perceptron = MultilayerPerceptron(train_data)
    print(multilayer_perceptron)


if __name__ == "__main__":
    main()
