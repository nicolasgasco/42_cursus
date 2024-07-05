import pandas as pd

from src.DataImporter import DataImporter
from src.DataSplitter import DataSplitter


def main():

    data_importer = DataImporter()
    data: pd.DataFrame = data_importer.import_data()

    data_prepper = DataSplitter(data)
    print(data_prepper)

    data_prepper.split()
    data_prepper.save_to_csv()

    print(data_prepper)


if __name__ == "__main__":
    main()
