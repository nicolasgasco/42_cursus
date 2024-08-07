import numpy as np

from src.DataImporter import DataImporter
from src.MultilayerPerceptron.MultilayerPerceptron import MultilayerPerceptron
from src.utils import print_output


def main():
    np.random.seed(0)  # TODO remove before deployment

    train_data = DataImporter.import_train_data()
    train_data = DataImporter.normalize_data(train_data)

    test_data = DataImporter.import_test_data()
    test_data = DataImporter.normalize_data(test_data)

    # pass down only first row of data set for now
    multilayer_perceptron = MultilayerPerceptron(train_data, test_data)
    print_output(multilayer_perceptron)

    # Full features ["24", "29", "4", "8", "9"],
    multilayer_perceptron.train()

    multilayer_perceptron.test()


if __name__ == "__main__":
    main()
