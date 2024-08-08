from src.DataImporter import DataImporter
from src.MultilayerPerceptron.MultilayerPerceptron import MultilayerPerceptron


def main():
    test_data = DataImporter.import_test_data()
    test_data = DataImporter.normalize_data(test_data)

    multilayer_perceptron = MultilayerPerceptron()
    print(multilayer_perceptron)

    parameters = DataImporter.import_parameters()
    multilayer_perceptron.import_parameters(parameters)

    multilayer_perceptron.test(test_data)


if __name__ == "__main__":
    main()
