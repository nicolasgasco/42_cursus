import numpy as np

from src.Data.DataImporter import DataImporter
from src.MultilayerPerceptron import MultilayerPerceptron


def main():
    np.random.seed(0)

    train_data = DataImporter.import_train_data()
    train_data = DataImporter.normalize_data(train_data)

    test_data = DataImporter.import_test_data()
    test_data = DataImporter.normalize_data(test_data)

    multilayer_perceptron = MultilayerPerceptron(train_data, test_data)
    print(multilayer_perceptron)

    multilayer_perceptron.train()


if __name__ == "__main__":
    main()
