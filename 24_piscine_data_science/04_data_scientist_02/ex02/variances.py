import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def main():
    df = pd.read_csv('../Train_knight.csv')
    df.drop('knight', axis=1, inplace=True)

    variances = df.var()

    sorted_variances = variances.sort_values(ascending=False)

    total_variance = sorted_variances.sum()

    variance_percentage = (sorted_variances / total_variance) * 100

    cumulative_variance_percentage = np.cumsum(variance_percentage)

    print("Variances (Percentage):\n", variance_percentage.values)
    print("Cumulative Variances (Percentage):\n",
          cumulative_variance_percentage.values)

    plt.figure(figsize=(10, 7))
    plt.plot(range(0, len(cumulative_variance_percentage)),
             cumulative_variance_percentage, '-')
    plt.xlabel('Number of Components')
    plt.ylabel('Cumulative Variance (%)')
    plt.grid(True)
    plt.show()
    plt.savefig("variances.jpg", bbox_inches='tight', pad_inches=0, dpi=500)


if __name__ == "__main__":
    main()
