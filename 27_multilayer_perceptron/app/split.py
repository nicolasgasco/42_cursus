import pandas as pd

from src.Data.DataImporter import DataImporter
from src.Data.DataSplitter import DataSplitter


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
