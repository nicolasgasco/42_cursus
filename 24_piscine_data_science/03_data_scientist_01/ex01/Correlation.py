import pandas as pd


def main():
    """
    Calculate the correlation between the 'knight' column and other columns in \
    the knight_data DataFrame.
    Print the correlation values for each column.
    """

    knight_data = pd.read_csv("../Train_knight.csv")

    # Convert the 'knight' column to numerical values
    knight_data['knight'] = knight_data['knight'].map({'Jedi': 1, 'Sith': -1})

    for header in knight_data.columns:
        if header != "knight":
            correlation = knight_data["knight"].corr(knight_data[header])
            print(f"{header}: {correlation:.6f}")


if __name__ == "__main__":
    main()
