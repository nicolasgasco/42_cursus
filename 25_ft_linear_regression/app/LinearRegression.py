class LinearRegression:
    def __init__(self, data):
        self._scale_factor = 1_000

        self._dataset = data / self._scale_factor

        self.theta0 = 0.0
        self.theta1 = 0.0

    def fit(self):
        """
        Trains the linear regression model using gradient descent.

        Returns:
            tuple: A tuple containing the computed values of theta0 and theta1.
        """

        ITERATIONS = 300_000
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

        return self.theta0, self.theta1

    def _compute_mean_absolute_error(self, price, estimated_price,
                                     normalization_factor):
        scaled_mean_absolute_error = normalization_factor * \
            sum(abs(price - estimated_price))

        return scaled_mean_absolute_error * self._scale_factor

    def _compute_root_mean_squared_error(self, price, estimated_price,
                                         normalization_factor):
        scaled_root_mean_squared_error = normalization_factor * \
            sum((price - estimated_price) ** 2) ** 0.5

        return scaled_root_mean_squared_error * self._scale_factor

    def _compute_mean_squared_error(self, price, estimated_price,
                                    normalization_factor):
        scaled_mean_squared_error = normalization_factor * \
            sum((price - estimated_price) ** 2)

        return scaled_mean_squared_error * self._scale_factor

    def _compute_r_squared(self, estimated_price):
        price = self._dataset['price']

        mean_price = sum(price) / len(price)

        ssr = sum((price - estimated_price) ** 2)
        sst = sum((price - mean_price) ** 2)

        r_squared = 1 - (ssr / sst)

        return r_squared * 100

    def accuracy(self):
        mileage = self._dataset['km']
        price = self._dataset['price']

        estimated_price = self.theta0 + self.theta1 * mileage
        normalization_factor = 1 / len(mileage)

        mean_absolute_error = self._compute_mean_absolute_error(
            price, estimated_price, normalization_factor)
        root_mean_squared_error = self._compute_root_mean_squared_error(
            price, estimated_price, normalization_factor)
        mean_squared_error = self._compute_mean_squared_error(
            price, estimated_price, normalization_factor)
        r_squared = self._compute_r_squared(estimated_price)

        print("\nModel accuracy:")
        print(f"\tMean absolute error: {mean_absolute_error:.2f}")
        print(f"\tRoot mean squared error: {root_mean_squared_error:.2f}")
        print(f"\tMean squared error: {mean_squared_error:.2f}")
        print(f"\tR-squared: {r_squared:.2f}%")
