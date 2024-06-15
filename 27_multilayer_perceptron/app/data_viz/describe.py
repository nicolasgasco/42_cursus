from DataImporter import DataImporter


def main():
    data_importer = DataImporter()

    data = data_importer.import_data()

    print(data.describe())


if __name__ == "__main__":
    main()
