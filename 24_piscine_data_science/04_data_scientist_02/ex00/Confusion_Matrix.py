import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix
import numpy as np


def read_file_content(file_name):
    with open(f"../{file_name}", "r") as file:
        return [line.strip() for line in file.readlines()]


def calc_confusion_matrix(truth, predictions):
    true_positive = 0
    true_negative = 0
    false_positive = 0
    false_negative = 0

    for i in range(len(truth)):
        if (predictions[i] == "Jedi" and truth[i] == "Jedi"):
            true_positive += 1
        elif (predictions[i] == "Sith" and truth[i] == "Sith"):
            true_negative += 1
        elif (predictions[i] == "Jedi" and truth[i] == "Sith"):
            false_positive += 1
        elif (predictions[i] == "Sith" and truth[i] == "Jedi"):
            false_negative += 1

    row1 = np.array([true_positive, false_negative])
    row2 = np.array([false_positive, true_negative])
    return np.array([row1, row2])


def main():
    truth = read_file_content("truth.txt")

    predictions = read_file_content("predictions.txt")

    conf_mat = confusion_matrix(truth, predictions, labels=["Jedi", "Sith"])
    print("Original:",
          f"{conf_mat[0][0]} {conf_mat[0][1]}, {conf_mat[1][0]} {conf_mat[1][1]}")

    own_conf_mat = calc_confusion_matrix(truth, predictions)

    print("Own is:",
          f"{own_conf_mat[0][0]} {own_conf_mat[0][1]}, {own_conf_mat[1][0]} {own_conf_mat[1][1]}")

    plt.figure(figsize=(10, 7))
    sns.heatmap(own_conf_mat, annot=True, fmt='d', cmap='Blues',
                xticklabels=["0", "1"], yticklabels=["1", "0"])
    plt.show()
    plt.savefig("confusion_matrix.jpg", bbox_inches='tight', pad_inches=0, dpi=500)


if __name__ == "__main__":
    main()
