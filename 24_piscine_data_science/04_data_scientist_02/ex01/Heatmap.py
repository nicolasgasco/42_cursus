import seaborn as sns
import pandas as pd

import matplotlib.pyplot as plt


def main():
    df = pd.read_csv('../Train_knight.csv')
    df['knight'] = df['knight'].map({'Jedi': 1.0, 'Sith': -1.0}).astype(float)

    corr = df.corr()

    plt.figure(figsize=(10, 7))
    sns.heatmap(corr, annot=False, cmap='Reds_r')
    plt.show()
    plt.savefig("heatmap.jpg", bbox_inches='tight', pad_inches=0, dpi=500)


if __name__ == "__main__":
    main()
