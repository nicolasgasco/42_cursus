import pandas as pd
import matplotlib.pyplot as plt


def main():
    files = ["Train_knight.csv", "Test_knight.csv"]

    for file in files:

        raw_data = pd.read_csv(f"../{file}")
        data = raw_data

        has_knight = False
        if "knight" in data.columns:
            has_knight = True
            data = data.drop(columns=["knight"])

        mean = data.mean()
        std = data.std()
        standardized_data = (data - mean) / std

        plt.clf()
        if has_knight:
            standardized_data = standardized_data.join(raw_data["knight"])

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
            plt.savefig("knight_stims_empowered-standardized.jpg",
                        bbox_inches='tight', pad_inches=0, dpi=500)
        else:
            plt.scatter(standardized_data["Empowered"],
                        standardized_data["Stims"], alpha=0.4,
                        color='green')

            plt.show()
            plt.savefig("jedi_stims_empowered-standardized.jpg",
                        bbox_inches='tight', pad_inches=0, dpi=500)
            
        print(standardized_data)


if __name__ == "__main__":
    main()
