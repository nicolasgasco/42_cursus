import pandas as pd
import matplotlib.pyplot as plt


def main():
    jedi_data = pd.read_csv("../Train_knight.csv")

    jedi_data_without_column = jedi_data.drop(columns=["knight"])
    mean = jedi_data_without_column.mean()
    std = jedi_data_without_column.std()
    standardized_data = (jedi_data_without_column - mean) / std

    standardized_data = standardized_data.join(jedi_data["knight"])

    plt.clf()
    jedi_knight_data = standardized_data[standardized_data["knight"] == "Jedi"]
    sith_knight_data = standardized_data[standardized_data["knight"] == "Sith"]
    plt.scatter(jedi_knight_data["Empowered"],
                jedi_knight_data["Stims"], alpha=0.4,
                color='blue', label="Jedi")
    plt.scatter(sith_knight_data["Empowered"],
                sith_knight_data["Stims"], alpha=0.4,
                color='red', label="Sith")
    plt.xlabel("Empowered")
    plt.ylabel("Stims")
    plt.legend(loc='upper left')

    plt.ylim(-1.99, 4.8)
    plt.xlim(-1.99, 2.99)

    plt.show()
    plt.savefig('knight_stims_empowered.jpg',
                bbox_inches='tight', pad_inches=0, dpi=500)


if __name__ == "__main__":
    main()
