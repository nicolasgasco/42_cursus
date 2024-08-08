from src.Data.DataImporter import DataImporter
from src.Data.DataPlotter import DataPlotter
from src.TaskTimer import TaskTimer


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

    timer = TaskTimer("Plotting")

    if user_choice == "a":
        plotter.histograms()
    elif user_choice == "b":
        plotter.pair_plot()
    elif user_choice == "c":
        plotter.correlation_matrix()

    print("\n")
    timer.stop()


if __name__ == "__main__":
    main()
