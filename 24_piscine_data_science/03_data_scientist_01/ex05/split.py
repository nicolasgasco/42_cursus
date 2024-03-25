import pandas as pd
from sklearn.model_selection import train_test_split


def main():
    data = pd.read_csv("../Train_knight.csv")

    train_data, validation_data = train_test_split(
        data, test_size=0.2, random_state=42)

    train_data.to_csv("Training_knight.csv", index=False)
    validation_data.to_csv("Validation_knight.csv", index=False)


if __name__ == "__main__":
    main()
