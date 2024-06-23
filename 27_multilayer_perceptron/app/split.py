import json as json
import pandas as pd
import sys as sys

from colorama import Fore, Style
from src.DataImporter import DataImporter
from src.DataPrepper import DataPrepper


def main():

    data_importer = DataImporter()
    data: pd.DataFrame = data_importer.import_data()

    data_prepper = DataPrepper(data)

    validation_percentage: int | None = data_prepper.get_validation_percentage()
    print(f"{Fore.YELLOW}{validation_percentage}%{Style.RESET_ALL} of the data will be used for validation.\n")

    data_prepper.split()
    data_prepper.save_to_csv()


if __name__ == "__main__":
    main()
