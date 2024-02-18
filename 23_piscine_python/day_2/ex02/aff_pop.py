from load_csv import load
import matplotlib.pyplot as plt
import pandas as pandas


def aff_pop() -> None:
    """
    Plot population projections for Spain and Italy.

    This function loads population data from a CSV file and plots
    the population projections
    for Spain and Italy from the year 1800 to 2050. The plot is saved as
    'population_projections.png'.

    Parameters:
    None

    Returns:
    None
    """

    SPAIN = 'Spain'
    ITALY = 'Italy'

    data = load("population_total.csv")

    if data is None:
        return

    for country in [SPAIN, ITALY]:
        country_data = data.loc[data['country'] == country]

        country_x = [int(x) for x in country_data.columns[1:]
                     if int(x) >= 1800 and int(x) <= 2050]

        country_x_len = len(country_x)
        country_y = [float(x[0:-1])
                     for x in country_data.values[0][1:country_x_len + 1]]

        data_frame = pandas.DataFrame({
            'Year': country_x,
            'Population': country_y
        })

        color = 'orange' if country == SPAIN else 'blue'

        data_frame.plot(x='Year', y='Population',
                        title="Population projections", ax=plt.gca(),
                        color=color, legend=True, label=country)

    plt.savefig('population_projections.png')
