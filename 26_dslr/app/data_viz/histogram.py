from DataImporter import DataImporter
from Plot import Plot


def main():
    importer = DataImporter()

    train_set, _ = importer.get_sets()

    plot = Plot(train_set)

    print("Plotting score distribution...")
    plot.plot_score_distribution()


if __name__ == "__main__":
    main()
