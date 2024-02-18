from load_csv import load
import matplotlib.pyplot as plt
import pandas as pandas


def aff_life() -> None:
    """
    Plot and save a graph of life expectancy projections
    for a specific country.
    """

    COUNTRY = 'Spain'

    data = load("life_expectancy_years.csv")

    if data is None:
        return

    desidered_row = data.loc[data['country'] == COUNTRY]

    years = [int(x) for x in desidered_row.columns[1:]]
    life_expectancy = [float(x) for x in desidered_row.values[0][1:]]

    data_frame = pandas.DataFrame({
        'Year': years,
        'Life expectancy': life_expectancy
    })

    title = f'{COUNTRY} life expectancy projections'
    x_column = 'Year'
    y_column = 'Life expectancy'

    data_frame.plot(x=x_column, y=y_column, title=title)

    plt.savefig('life_expectancy_years.png')
