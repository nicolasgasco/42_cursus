import pandas as pd

from src.DataImporter import DataImporter
from src.DataPrepper import DataPrepper


def main():

    data_importer = DataImporter()
    data: pd.DataFrame = data_importer.import_data()

    data_prepper = DataPrepper(data)
    print(data_prepper)

    data_prepper.split()
    data_prepper.save_to_csv()

    print(data_prepper)


if __name__ == "__main__":
    main()
