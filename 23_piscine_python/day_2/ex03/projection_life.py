from load_csv import load
import pandas as pandas
import matplotlib.pyplot as plt


def _get_income(year: str) -> list[int] | None:
    income_data = load(
        "income_per_person_gdppercapita_ppp_inflation_adjusted.csv")

    if income_data is None:
        return None

    income_list = income_data[year].tolist()
    return income_list


def _get_life(year: str) -> list[int] | None:
    life_data = load("life_expectancy_years.csv")

    if life_data is None:
        return None

    life_list = life_data[year].tolist()

    return life_list


def projection_life() -> None:
    YEAR = "1900"

    try:
        income_list = _get_income(YEAR)
        life_list = _get_life(YEAR)
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
