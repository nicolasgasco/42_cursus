from DataImporter import DataImporter
from Plot import Plot


def main():
    importer = DataImporter()

    train_set, _ = importer.get_sets()

    plot = Plot(train_set)

    print("Plotting pair plot matrix...")
    plot.plot_pair_matrix()


if __name__ == "__main__":
    main()
