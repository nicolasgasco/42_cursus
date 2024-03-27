import pandas as pd

import matplotlib.pyplot as plt
import matplotlib.ticker as ticker


def generate_plot(data, labels):
    """
    Generate a plot with the given data and labels.

    Args:
        data (dict): A dictionary containing the x-axis and y-axis data.
                     The keys should be 'x' and 'y'.
        labels (dict): A dictionary containing the labels for the x-axis,
                       y-axis, and title. The keys should be 'x_label',
                       'y_label', and 'title'.

    Returns:
        None
    """

    plt.clf()  # Reset plot options
    plt.title(labels['title'])
    plt.plot(data['x'], data['y'], 'o-')
    plt.xlabel(labels['x_label'])
    plt.ylabel(labels['y_label'])

    # Format number on both axes
    formatter = ticker.FuncFormatter(lambda x, pos: f'{x/1000:.0f}k')
    plt.gca().xaxis.set_major_formatter(formatter)
    plt.gca().yaxis.set_major_formatter(formatter)

    plt.grid(True, which='both', linestyle='--', linewidth=0.5)

    plot_name = labels['title'].lower().replace(' ', '_') + '.jpg'
    plt.savefig(plot_name, bbox_inches='tight', pad_inches=0, dpi=500)


def main():
    data = pd.read_csv("../data.csv")

    sorted_by_mileage = data.sort_values(by='km')
    by_mileage_data = {
        'x': sorted_by_mileage['km'],
        'y': sorted_by_mileage['price']
    }
    by_mileage_labels = {
        'x_label': 'Mileage',
        'y_label': 'Price',
        'title': 'Mileage vs Price'
    }
    generate_plot(by_mileage_data, by_mileage_labels)

    sorted_by_price = data.sort_values(by='price')
    by_price_data = {
        'x': sorted_by_price['price'],
        'y': sorted_by_price['km']
    }
    by_price_labels = {
        'x_label': 'Price',
        'y_label': 'Mileage',
        'title': 'Price vs Mileage'
    }
    generate_plot(by_price_data, by_price_labels)


if __name__ == "__main__":
    main()
