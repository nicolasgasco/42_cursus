from colorama import Fore, Style
import json as json
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from prettytable import PrettyTable

HOUSE_COLOR = {
    "Ravenclaw": "BLUE",
    "Gryffindor": "RED",
    "Slytherin": "GREEN",
    "Hufflepuff": "YELLOW"
}

PREDICTION_PARAMS_FILE_PATH = "/dslr/data/prediction_params.csv"


class LogisticRegression:
    def __init__(self, data: pd.DataFrame,
                 features: list[str] = [
                     "Astronomy",
                     "Ancient Runes",
                     "Defense Against the Dark Arts",
                     "Herbology",],
                 should_fill_na: bool = True):
        self._validate_inputs(data, features)

        self.houses = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]

        self.features = sorted(features)

        if should_fill_na:
            # Fill NaN values allows to predict all values in test set
            data = data.fillna(data[self.features].mean())
        else:
            # For training set, it's better to drop NaN values completely
            data = data.dropna(subset=self.features)
        self.data_x: pd.DataFrame = self._normalize_data(data[self.features])
        self.data_y: pd.Series = data["Hogwarts House"]

        self.learning_rate: int = 1 if len(self.features) == 2 else 10
        self.iterations: int = 100_000

        try:
            self.prediction_params: pd.DataFrame | None = pd.read_csv(
                PREDICTION_PARAMS_FILE_PATH)
        except FileNotFoundError:
            self.prediction_params: pd.DataFrame | None = None

    def _normalize_data(self, data: pd.DataFrame) -> pd.DataFrame:
        """
        Normalize the given data using min-max scaling.

        Parameters:
        data (pd.DataFrame): The input data to be normalized.

        Returns:
        pd.DataFrame: The normalized data.
        """

        normalized_data = (data - data.min()) / (data.max() - data.min())
        return normalized_data

    def _validate_inputs(self, data: pd.DataFrame, features: list[str]):
        """
        Validates the inputs for the LogisticRegression model.

        Args:
            data (pd.DataFrame): The input data as a pandas DataFrame.
            features (list[str]): The list of features to be used for training.

        Raises:
            AssertionError: If the data is not a pandas DataFrame
            or if it is empty.
            AssertionError: If the features list does not contain
            at least 2 features.
            AssertionError: If any feature in the features list
            is not found in the data.

        Returns:
            None
        """

        assert isinstance(
            data, pd.DataFrame), "The data must be a pandas DataFrame."
        assert not data.empty, "The data must not be empty."

        assert len(
            features) > 1, "Features list must contain at least 2 features."

        for feature in features:
            error_message = f"'{feature}' not found in the data."
            assert feature in data.columns, error_message

    def _sigmoid(self, x):
        """
        Applies the sigmoid function to the input x.

        Parameters:
        x (pd.Series): The input value.

        Returns:
        float: The result of applying the sigmoid function to x.
        """

        return 1 / (1 + np.exp(-x))

    def _serialize_title(self, title: str) -> str:
        """
        Serialize the given title by replacing spaces with underscores
        and converting it to lowercase.

        Args:
            title (str): The title to be serialized.

        Returns:
            str: The serialized title.
        """

        return title.lower().replace(" ", "_")

    def plot_regression_2d(self, prediction_params_list: list[dict]):
        """
        Plot the regression line for each set of prediction parameters
        in the given list.
        Args:
            prediction_params_list (list[dict]): A list of dictionaries
            containing prediction parameters.
                Each dictionary should have the following keys:
                - 'House': The house name.
                - 'Weight_1': The weight parameter 1.
                - 'Weight_2': The weight parameter 2.
                - 'Bias': The bias parameter.
        Returns:
            None
        """

        print("Plotting regression line for each house...\n")

        feature1 = self.features[0]
        feature2 = self.features[1]

        for prediction_params in prediction_params_list:
            house = prediction_params['House']

            weights = json.loads(prediction_params['Weights'])
            w = np.array(weights)
            b = prediction_params['Bias']

            x_values = np.linspace(start=min(self.data_x[feature1]),
                                   stop=max(self.data_x[feature1]),
                                   num=100)
            y_values = (-w[0]*x_values - b) / w[1]

            plt.plot(x_values, y_values, color=HOUSE_COLOR[house].lower())

        plt.scatter(
            self.data_x[feature1], self.data_x[feature2],
            color='grey', alpha=0.5, s=10)

        plt.xlabel(feature1)
        plt.ylabel(feature2)

        plt.legend(self.houses)
        plt.title(f"Regression: {feature1} vs {feature2}")

        filename = "/dslr/app/regression/plots/logistic_regression_2d.png"
        plt.savefig(filename, dpi=300)
        plt.close()

        print("2D plot saved to", filename, "\n")

    def plot_regression_3d(self, prediction_params_list: list[dict]):
        """
        Plot the regression line for each set of prediction parameters
        in the given list.

        Args:
            prediction_params_list (list[dict]): A list of dictionaries
            containing prediction parameters.
                Each dictionary should have the following keys:
                - 'House': The house name.
                - 'Weight_1': The weight parameter 1.
                - 'Weight_2': The weight parameter 2.
                - 'Bias': The bias parameter.

        Returns:
            None
        """

        print("Plotting regression planes for each house...\n")

        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')

        x_range = np.linspace(self.data_x[self.features[0]].min(
        ), self.data_x[self.features[0]].max(), num=10)
        y_range = np.linspace(self.data_x[self.features[1]].min(
        ), self.data_x[self.features[1]].max(), num=10)
        x_values, y_values = np.meshgrid(x_range, y_range)

        for prediction_params in prediction_params_list:
            house = prediction_params['House']

            weights = json.loads(prediction_params['Weights'])
            w = np.array(weights)
            b = prediction_params['Bias']

            z_values = (-w[0] * x_values - w[1] * y_values - b) / w[2]

            ax.plot_surface(x_values, y_values, z_values,
                            color=HOUSE_COLOR[house].lower(),
                            alpha=0.5)

        ax.set_xlabel(self.features[0])
        ax.set_ylabel(self.features[1])
        ax.set_zlabel(self.features[2])

        plt.legend(self.houses)

        plt.title(" vs ".join(self.features))

        file_name = "logistic_regression_3d.png"
        file_path = "/dslr/app/regression/plots/" + file_name
        plt.savefig(file_path, dpi=300)
        plt.close()

        print("3D plot saved to", file_path, "\n")

    def train(self):
        """
        Trains the model using logistic regression.

        This method performs logistic regression on the given data
        to train the model.
        It iterates over each house, calculates the weights and bias,
        and saves the prediction parameters to a CSV file.

        Returns:
            None
        """

        formatted_features = [
            f"{Fore.YELLOW}{feature}{Style.RESET_ALL}"
            for feature in self.features]
        joined_features = ", ".join(formatted_features)
        print(f"Training the model with features: {joined_features}...\n")

        prediction_params_list = []

        m, n = self.data_x.shape

        for house in self.houses:
            print(
                getattr(Fore, HOUSE_COLOR[house]),
                f"{house.upper()}",
                Style.RESET_ALL,
            )

            y = self.data_y.apply(lambda x: 1 if x == house else 0).values

            w = np.zeros(n)
            b = 0.0

            prev_w, prev_b = w, b
            for i in range(self.iterations):
                linear_prediction = np.dot(self.data_x, w) + b
                prediction = self._sigmoid(linear_prediction)

                dw = (1 / m) * np.dot(self.data_x.T, (prediction - y))
                db = (1 / m) * np.sum(prediction - y)

                w = w - self.learning_rate * dw
                b = b - self.learning_rate * db

                if np.allclose(w, prev_w) and np.isclose(b, prev_b):
                    break

                prev_w, prev_b = w, b

                print(
                    "\r\t",
                    f"Iteration {(i + 1):,}/{self.iterations:_}: ",
                    f"weights: {w[:4]} (...)," if len(
                        w) > 4 else f"weights: {w}",
                    f"bias: {b}",
                    end="")

            prediction_params_list.append({
                'House': house,
                'Weights': json.dumps(w.tolist()),
                "Bias": b,
                "Features": json.dumps(self.features)
            })

            print("\n")

        print(
            "Saving prediction parameters to",
            f"{PREDICTION_PARAMS_FILE_PATH}...\n")

        self.prediction_params = pd.DataFrame(prediction_params_list)
        self.prediction_params.to_csv(PREDICTION_PARAMS_FILE_PATH, index=False)

        features_num = len(self.features)
        if features_num == 2:
            self.plot_regression_2d(prediction_params_list)
        elif features_num == 3:
            self.plot_regression_3d(prediction_params_list)

    def _get_binary_predictions(self, prediction_params: pd.DataFrame,
                                output: bool = True) -> pd.DataFrame:

        binary_predictions = pd.DataFrame(columns=self.houses)

        table = PrettyTable(["House", "Weights", "Bias"])
        for house in self.houses:
            prediction_params_row = prediction_params.loc[
                prediction_params['House'] == house]

            weights: list[float] = json.loads(
                prediction_params_row['Weights'].values[0])

            bias: float = prediction_params_row['Bias'].values[0]

            formatted_house = getattr(
                Fore, HOUSE_COLOR[house]) + house + Style.RESET_ALL

            formatted_weights = f"{weights[:4]} (...)" if len(
                weights) > 4 else f"{weights}"

            table.add_row([formatted_house, formatted_weights, bias])

            linear_pred = np.dot(self.data_x, weights) + bias
            prediction = self._sigmoid(linear_pred)

            binary_predictions[house] = prediction

        predicted_house = binary_predictions.idxmax(axis=1)

        formatted_predictions = pd.DataFrame(
            predicted_house, columns=['Hogwarts House'])

        if output is True:
            print(table)

        return formatted_predictions

    def predict(self, prediction_params: pd.DataFrame):
        """
        Predicts the house for each student based on the given features.

        Args:
            prediction_params (pd.DataFrame): A DataFrame containing
            the prediction parameters.

        Raises:
            AssertionError: If the features in the prediction_params
            do not match the features used for training.

        Returns:
            None
        """

        features = json.loads(prediction_params['Features'].values[0])

        error_message = Fore.RED + "Invalid features." + Style.RESET_ALL
        assert features == self.features, error_message

        formatted_features = [
            f"{Fore.YELLOW}{feature}{Style.RESET_ALL}"
            for feature in self.features]
        joined_features = ", ".join(formatted_features)
        print(
            "Predicting house for each student with features: ",
            f"{joined_features}...\n")

        formatted_predictions = self._get_binary_predictions(prediction_params)

        file_name = "houses.csv"
        print(f"Saving formatted predictions to {file_name}...\n")

        file_path = "/dslr/data/" + file_name
        formatted_predictions.to_csv(
            file_path, index=True, index_label='Index')

    def accuracy(self) -> None:
        """
        Calculate the accuracy of the trained model.

        This method calculates the accuracy of the trained model
        by comparing the predicted Hogwarts House values
        with the actual data labels.
        It prints the accuracy percentage on the console.

        Returns:
            None
        """

        if (self.prediction_params is None):
            print(Fore.RED,
                  "Prediction parameters not found. Train the model first.",
                  Style.RESET_ALL)
            return

        print("Calculating accuracy of trained model...\n")

        predictions = self._get_binary_predictions(
            self.prediction_params, output=False)
        house_predictions = predictions["Hogwarts House"]

        if (house_predictions.shape[0] != self.data_y.shape[0]):
            print(Fore.RED,
                  "Prediction and data sizes do not match.",
                  Style.RESET_ALL)
            return

        n = house_predictions.shape[0]

        correct_predictions = 0
        for i in range(n):
            if house_predictions.values[i] == self.data_y.values[i]:
                correct_predictions += 1

        accuracy = correct_predictions / n

        print("Model trained with an accuracy of",
              f"{Fore.YELLOW}{accuracy:.2%}{Style.RESET_ALL}.\n")
