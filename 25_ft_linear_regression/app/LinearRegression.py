import pandas as pd


class LinearRegression:
    def __init__(self):
        self._scale_factor = 1_000

        self._dataset = self._prepare_data()

        self.theta0 = 0.0
        self.theta1 = 0.0

    def _prepare_data(self):
        """
        Preprocesses the data by reading it from a CSV file, \
        sorting it by 'km' column,
        and scaling it by the specified scale factor.

        Returns:
            pd.DataFrame: The preprocessed data.
        """

        data = pd.read_csv("../data.csv")
        data = data.sort_values(by='km')
        data = data / self._scale_factor

        return data

    def fit(self):
        """
        Trains the linear regression model using gradient descent.

        Returns:
            tuple: A tuple containing the computed values of theta0 and theta1.
        """

        print("Training the model...")

        ITERATIONS = 500_000
        LEARNING_RATE = 0.0001

        mileage = self._dataset['km']
        price = self._dataset['price']

        m = len(mileage)
        norm_factor = 1 / m

        for _ in range(ITERATIONS):
            estimate_price = self.theta0 + self.theta1 * mileage
            price_error = estimate_price - price

            temp_theta0 = LEARNING_RATE * norm_factor * sum(price_error)

            temp_theta1 = LEARNING_RATE * norm_factor * \
                sum((price_error) * mileage)

            self.theta0 -= temp_theta0
            self.theta1 -= temp_theta1

        print("Theta0 and Theta1 were computed successfully.")

        return self.theta0, self.theta1
