from DataImporter import DataImporter
from DataPlotter import DataPlotter


def main():
    data_importer = DataImporter()
    data_importer.import_data()

    normalized_data = data_importer.normalize_data()

    plotter = DataPlotter(normalized_data)

    print("Which plot do you want to create?\n")
    print("a) Histograms\nb) Pair plot\nc) Correlation matrix\n")

    user_choice = input("Enter your choice: ")

    print("\n")

    if user_choice == "a":
        plotter.histograms()
    elif user_choice == "b":
        plotter.pair_plot()
    elif user_choice == "c":
        plotter.correlation_matrix()


if __name__ == "__main__":
    main()
