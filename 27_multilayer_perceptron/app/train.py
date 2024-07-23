from src.DataImporter import DataImporter
from src.MultilayerPerceptron.MultilayerPerceptron import MultilayerPerceptron
from src.utils import print_output


def main():
    train_data = DataImporter.import_train_data()
    train_data = DataImporter.normalize_data(train_data)

    # pass down only first row of data set for now
    multilayer_perceptron = MultilayerPerceptron(train_data.iloc[0:6])
    print_output(multilayer_perceptron)

    # Full features ["24", "29", "4", "8", "9"],
    multilayer_perceptron.train()


if __name__ == "__main__":
    main()
