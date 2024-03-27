import pandas as pd
from sklearn import tree
import matplotlib.pyplot as plt
from sklearn.metrics import f1_score


def main():
    train_knight = pd.read_csv('../Train_knight.csv')
    test_knight = pd.read_csv('../Test_knight.csv')

    X_train = train_knight.drop('knight', axis=1)
    y_train = train_knight['knight']

    # The testing dataset is used for making predictions, so it doesn't have a target column
    X_test = test_knight

    # Create a Decision Tree Classifier
    clf = tree.DecisionTreeClassifier()

    # Fit the classifier to the training data
    clf = clf.fit(X_train, y_train)

    # Predict the target for the testing data
    y_pred = clf.predict(X_test)

    with open('Tree.txt', 'w') as file:
        for pred in y_pred:
            file.write(str(pred) + '\n')

    plt.figure(figsize=(15, 10))
    tree.plot_tree(clf, filled=True, rounded=True,
                   feature_names=X_train.columns)
    plt.show()
    plt.savefig("tree.jpg", bbox_inches='tight', pad_inches=0, dpi=500)

    with open('../truth.txt', 'r') as file:
        y_true = [line.strip() for line in file]

        f1 = f1_score(y_true, y_pred[:100], average='binary', pos_label='Jedi')

        print("F1 score is:", f1 * 100)


if __name__ == "__main__":
    main()
