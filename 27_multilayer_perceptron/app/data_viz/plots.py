from DataImporter import DataImporter
from DataPlotter import DataPlotter


def main():
    data_importer = DataImporter()
    data_importer.import_data()

    normalized_data = data_importer.normalize_data()

    plotter = DataPlotter(normalized_data)
    plotter.pair_plot()
    plotter.histograms()


if __name__ == "__main__":
    main()
