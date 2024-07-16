from src.DataImporter import DataImporter
from src.DataPlotter import DataPlotter


def main():
    data_importer = DataImporter()
    data_importer.import_data()

    normalized_data = DataImporter.normalize_data(data_importer.data)

    plotter = DataPlotter(normalized_data)

    print("Which plot do you want to create")
    print("\n")

    print("a) Histograms")
    print("b) Pair plot")
    print("c) Correlation matrix")
    print("\n")

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
