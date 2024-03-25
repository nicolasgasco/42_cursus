import pandas as pd
import matplotlib.pyplot as plt


def main():
    files = ["Train_knight.csv", "Test_knight.csv"]

    for file in files:
        raw_data = pd.read_csv(f"../{file}")
        data = raw_data

        has_knight = False
        if "knight" in data.columns.values:
            has_knight = True
            data = data.drop(columns=["knight"])

        normalized_data = (data - data.min()) / (data.max() - data.min())

        plt.clf()
        if has_knight:
            normalized_data = normalized_data.join(raw_data["knight"])

            jedi_knight_data = normalized_data[normalized_data["knight"] == "Jedi"]
            sith_knight_data = normalized_data[normalized_data["knight"] == "Sith"]

            plt.scatter(jedi_knight_data["Push"],
                        jedi_knight_data["Deflection"], alpha=0.4, color='blue', label="Jedi")
            plt.scatter(sith_knight_data["Push"],
                        sith_knight_data["Deflection"], alpha=0.4, color='red', label="Sith")
            plt.xlabel("Push")
            plt.ylabel("Deflection")
            plt.legend()

            plt.show()
            plt.savefig("knight_push_deflection-normalized.jpg",
                        bbox_inches='tight', pad_inches=0, dpi=500)
        else:
            plt.scatter(normalized_data["Empowered"],
                        normalized_data["Stims"], alpha=0.4,
                        color='green')

            plt.show()
            plt.savefig("jedi_stims_empowered-normalized.jpg",
                        bbox_inches='tight', pad_inches=0, dpi=500)

        print(normalized_data)


if __name__ == "__main__":
    main()
