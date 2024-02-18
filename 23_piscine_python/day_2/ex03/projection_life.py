from load_csv import load
import pandas as pandas
import matplotlib.pyplot as plt


def _get_data_by_year(year: str, file_name: str) -> list[int] | None:
    """
    Retrieves life data for a specific year from a given file.

    Args:
        year (str): The year for which to retrieve the life data.
        file_name (str): The name of the file containing the life data.

    Returns:
        list[int] | None: The life data for the specified year, or None if the data is not available.
    """

    life_data = load(file_name)

    if life_data is None:
        return None

    life_list = life_data[year].tolist()

    return life_list


def projection_life() -> None:
    """
    Generates a scatter plot of gross domestic product vs life expectancy for a given year.
    Saves the plot as 'projection_life.png'.

    Raises:
        KeyError: If the year is not found in the dataset.
    """

    YEAR = "1900"

    try:
        income_list = _get_data_by_year(
            YEAR, "income_per_person_gdppercapita_ppp_inflation_adjusted.csv")
        life_list = _get_data_by_year(YEAR, "life_expectancy_years.csv")
    except KeyError:
        print(f"Year {YEAR} not found in dataset")
        return

    data_frame = pandas.DataFrame({
        'Gross domestic product': income_list,
        'Life expectancy': life_list
    })

    data_frame.plot.scatter(x='Gross domestic product', y='Life expectancy',
                            title=YEAR)

    plt.savefig('projection_life.png')
