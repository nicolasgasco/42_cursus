import pandas as pd

import matplotlib.pyplot as plt


def output_jedi_histogram(data):
    """
    Generate a histogram for each column in the given data and save the plot \
    as 'knights.jpg'.

    Parameters:
    data (pandas.DataFrame): The input data containing columns to generate \
    histograms for.

    Returns:
    None
    """
    fig, axs = plt.subplots(6, 5, figsize=(20, 15))

    headers = data.columns
    for i, header in enumerate(headers):
        row = i // 5  # Calculate the row index
        col = i % 5  # Calculate the column index

        axs[row, col].hist(data[header], bins=40, color="green")
        axs[row, col].set_title(header)
        axs[row, col].legend(["Knight"], loc="upper right")

    plt.tight_layout()
    plt.savefig('knights.jpg', bbox_inches='tight', pad_inches=0, dpi=500)


def output_jedi_sith_histogram(knight_data):
    jedi_data = knight_data[knight_data['knight'] == 'Jedi'].drop(columns=[
                                                                  'knight'])
    sith_data = knight_data[knight_data['knight'] == 'Sith'].drop(columns=[
                                                                  'knight'])

    fig, axs = plt.subplots(6, 5, figsize=(20, 15))

    for i, header in enumerate(jedi_data[:-1]):
        row = i // 5  # Calculate the row index
        col = i % 5  # Calculate the column index
        axs[row, col].hist(jedi_data[header], bins=40, color="blue", alpha=0.5)
        axs[row, col].hist(sith_data[header], bins=40, color="red", alpha=0.5)
        axs[row, col].set_title(header)
        axs[row, col].legend(["Jedi", "Sith"], loc="upper right")

    plt.tight_layout()
    plt.savefig('siths_and_jedis.jpg',
                bbox_inches='tight', pad_inches=0, dpi=500)


def main():
    jedi_data = pd.read_csv("../Test_knight.csv")
    output_jedi_histogram(jedi_data)

    knight_data = pd.read_csv("../Train_knight.csv")
    output_jedi_sith_histogram(knight_data)


if __name__ == "__main__":
    main()
