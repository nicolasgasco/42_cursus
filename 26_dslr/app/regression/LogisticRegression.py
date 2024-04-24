from colorama import Fore, Style
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

HOUSE_COLOR = {
    "Ravenclaw": "BLUE",
    "Gryffindor": "RED",
    "Slytherin": "GREEN",
    "Hufflepuff": "YELLOW"
}


class LogisticRegression:
    def __init__(self, data: pd.DataFrame,
                 feature1: str = "Herbology", feature2: str = "Astronomy"):
        self._validate_inputs(data, feature1, feature2)

        self.houses = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]

        self.feature1: str = feature1
        self.feature2: str = feature2

        data = data.fillna({self.feature1: 0, self.feature2: 0})
        self.data_x: pd.DataFrame = self._normalize_data(
            data[[self.feature1, self.feature2]])
        self.data_y: pd.Series = data["Hogwarts House"]

        self.learning_rate: float = 0.1
        self.iterations: int = 40_000

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

    def _validate_inputs(self, data: pd.DataFrame,
                         feature1: str, feature2: str):
        """
        Validates the inputs for the Trainer class.

        Args:
            data (pd.DataFrame): The input data as a pandas DataFrame.
            feature1 (str): The name of the first feature.
            feature2 (str): The name of the second feature.

        Raises:
            AssertionError: If the data is not a pandas DataFrame
            or if it is empty.
            AssertionError: If 'feature1' is not found in the data.
            AssertionError: If 'feature2' is not found in the data.
        """

        assert isinstance(
            data, pd.DataFrame), "The data must be a pandas DataFrame."
        assert not data.empty, "The data must not be empty."

        assert (
            feature1 in data.columns), f"'{feature1}' not found in the data."
        assert (
            feature2 in data.columns), f"'{feature2}' not found in the data."

    def _sigmoid(self, x):
        """
        Applies the sigmoid function to the input x.

        Parameters:
        x (pd.Series): The input value.

        Returns:
        float: The result of applying the sigmoid function to x.
        """

        return 1 / (1 + np.exp(-x))

    def plot_regression(self, prediction_params_list: list[dict]):
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

        for prediction_params in prediction_params_list:
            house = prediction_params['House']

            w = np.array([prediction_params['Weight_1'],
                         prediction_params['Weight_2']])
            b = prediction_params['Bias']

            x_values = np.linspace(start=min(self.data_x[self.feature1]),
                                   stop=max(self.data_x[self.feature1]),
                                   num=100)
            y_values = (-w[0]*x_values - b) / w[1]

            plt.plot(x_values, y_values, color=HOUSE_COLOR[house].lower())

        plt.scatter(
            self.data_x[self.feature1], self.data_x[self.feature2],
            color='grey', alpha=0.5, s=10)

        plt.xlabel(self.feature1)
        plt.ylabel(self.feature2)

        plt.legend(self.houses)
        plt.title(f"Regression: {self.feature1} vs {self.feature2}")

        filename = f"regression-{self.feature1.lower()}_{self.feature2.lower()}.png"
        plt.savefig(filename, dpi=300)
        plt.close()

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

        print("Training the model...")

        prediction_params_list = []

        m, n = self.data_x.shape

        for house in self.houses:
            print(
                f"{getattr(Fore, HOUSE_COLOR[house])}",
                f"\n{house.upper()}",
                f"{Style.RESET_ALL}")

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
                    "\r"
                    f"\tIteration {(i + 1):,}/{self.iterations:_}:",
                    f"weights: {w}, "
                    f"bias: {b}", end="")

            prediction_params_list.append({
                'House': house,
                'Weight_1': w[0],
                'Weight_2': w[1],
                'Bias': b
            })

        print("\n")

        file_name: str = "prediction_params.csv"
        print(f"Saving prediction parameters to {file_name}...\n")

        file_path: str = "/dslr/data/" + file_name
        prediction_params = pd.DataFrame(prediction_params_list)
        prediction_params.to_csv(file_path, index=False)

        self.plot_regression(prediction_params_list)

    def predict(self, prediction_params: pd.DataFrame):
        """
        Predicts the Hogwarts house for each student based
        on the given prediction parameters.

        Args:
            prediction_params (pd.DataFrame): A DataFrame containing
            the prediction parameters for each house.

        Returns:
            None
        """

        binary_predictions = pd.DataFrame(columns=self.houses)

        print("Predicting the house for each student...\n")
        for house in self.houses:
            print(
                f"{getattr(Fore, HOUSE_COLOR[house])}",
                f"{house.upper()}",
                f"{Style.RESET_ALL}")

            prediction_params_row = prediction_params.loc[
                prediction_params['House'] == house]

            weight_1: float = prediction_params_row['Weight_1'].values[0]
            weight_2: float = prediction_params_row['Weight_2'].values[0]
            weights: list[float] = [weight_1, weight_2]

            bias: float = prediction_params_row['Bias'].values[0]

            print(f"\tweights: {weights}, bias: {bias}")

            linear_pred = np.dot(self.data_x, weights) + bias
            prediction = self._sigmoid(linear_pred)

            binary_predictions[house] = prediction

        print("\n")

        predicted_house = binary_predictions.idxmax(axis=1)

        formatted_predictions = pd.DataFrame(
            predicted_house, columns=['Hogwarts House'])

        file_name = "houses.csv"
        print(f"Saving formatted predictions to {file_name}...\n")

        file_path = "/dslr/data/" + file_name
        formatted_predictions.to_csv(
            file_path, index=True, index_label='Index')
