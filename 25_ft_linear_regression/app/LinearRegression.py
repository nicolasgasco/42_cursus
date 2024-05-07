from colorama import Fore, Style
import pandas as pd
import numpy as np


class LinearRegression:
    def __init__(self, data: pd.DataFrame):
        def _normalize_data(data: pd.DataFrame) -> pd.DataFrame:
            """
            Normalize the given data using min-max scaling.

            Parameters:
            data (pd.DataFrame): The input data to be normalized.

            Returns:
            pd.DataFrame: The normalized data.
            """

            normalized_data = (data - data.min()) / (data.max() - data.min())

            return normalized_data

        self._dataset: pd.DataFrame = _normalize_data(data)
        self._dataset_unnormal: pd.DataFrame = data

        self.theta0, self.theta1 = 0.0, 0.0
        self.theta0_unnorm, self.theta1_unnorm = 0.0, 0.0

        self.max_iterations = 25_000
        self.learn_rate = 0.1

    def _estimate_price(self, theta0: float, theta1: float,
                        mileage: pd.Series) -> pd.Series:
        """
        Estimates the price of a car based
        on the given theta0, theta1, and mileage.

        Parameters:
        theta0 (float): The intercept of the linear regression model.
        theta1 (float): The slope of the linear regression model.
        mileage (pd.Series): The mileage of the car.

        Returns:
        pd.Series: The estimated price of the car.
        """

        estimated_price = theta0 + theta1 * mileage

        return estimated_price

    def fit(self) -> tuple[float, float]:
        """
        Trains the linear regression model using gradient descent.

        Returns:
            tuple: A tuple containing the computed values of theta0 and theta1.
        """

        def _calc_thetas(norm_factor: float, mileage: pd.Series,
                         price: pd.Series) -> tuple[float, float]:
            """
            Calculate the updated values of theta0 and theta1 based
            on the given normalization factor, mileage, and price.

            Parameters:
            norm_factor (float): The normalization factor.
            mileage (pd.Series): The mileage values.
            price (pd.Series): The corresponding price values.

            Returns:
            tuple[float, float]: The updated values of theta0 and theta1.
            """

            estimated_price = self._estimate_price(
                self.theta0, self.theta1, mileage)

            price_error = estimated_price - price

            temp_theta0 = self.learn_rate * norm_factor * sum(price_error)
            temp_theta1 = self.learn_rate * \
                norm_factor * sum((price_error) * mileage)

            return temp_theta0, temp_theta1

        def _unnormalize_thetas() -> tuple[float, float]:
            """
            Unnormalizes the theta values based on the original dataset.

            Returns:
                tuple: A tuple containing the unnormalized theta0 and theta1.
            """

            x: pd.Series = self._dataset_unnormal.iloc[:, 0]
            y: pd.Series = self._dataset_unnormal.iloc[:, 1]

            range_y: pd.Series = y.max() - y.min()

            theta1_unnorm: float = self.theta1 * range_y / (x.max() - x.min())
            theta0_unnorm: float = self.theta0 * range_y + y.min() \
                - theta1_unnorm * x.min()

            return theta0_unnorm, theta1_unnorm

        def _save_thetas_to_csv():
            """
            Save the theta values to a CSV file.

            This method creates a DataFrame with the theta values
            and saves it to a CSV file.
            The CSV file is saved in the 'data/thetas.csv' directory.

            Parameters:
                None

            Returns:
                None
            """
            thetas_df = pd.DataFrame(
                {'theta0': [self.theta0_unnorm], 'theta1': [self.theta1_unnorm]})

            file_path = '/ft_linear_regression/data/thetas.csv'
            thetas_df.to_csv(file_path, index=False)

            print("Thetas saved to",
                  f"{Fore.YELLOW}{file_path}{Style.RESET_ALL}.\n")

        mileage: pd.Series = self._dataset['km']
        price: pd.Series = self._dataset['price']

        m = mileage.size
        norm_factor = 1 / m

        prev_theta0, prev_theta1 = self.theta0_unnorm, self.theta1_unnorm
        for i in range(self.max_iterations):

            temp_theta0, temp_theta1 = _calc_thetas(
                norm_factor, mileage, price)

            self.theta0 -= temp_theta0
            self.theta1 -= temp_theta1

            self.theta0_unnorm, self.theta1_unnorm = _unnormalize_thetas()
            print(
                "\r"
                f"Iteration: {i + 1:,}/{self.max_iterations:,}:",
                "theta0:",
                f"{Fore.GREEN}{self.theta0_unnorm:.2f}{Style.RESET_ALL},",
                "theta1:"
                f"{Fore.GREEN}{self.theta1_unnorm:.2f}{Style.RESET_ALL}",
                end=""
            )

            is_theta0_converged = np.isclose(prev_theta0, self.theta0_unnorm)
            is_theta1_converged = np.isclose(prev_theta1, self.theta1_unnorm)
            if is_theta0_converged and is_theta1_converged:
                break

            prev_theta0, prev_theta1 = self.theta0_unnorm, self.theta1_unnorm

        print("\n")

        _save_thetas_to_csv()

        return self.theta0_unnorm, self.theta1_unnorm

    def accuracy(self):
        """
        Calculate and print the accuracy metrics
        of the linear regression model.

        The accuracy metrics include:
        - Mean absolute error
        - Root mean squared error
        - Mean squared error
        - R-squared

        The accuracy metrics are calculated based on the predicted prices
        and the actual prices
        from the dataset.

        Returns:
            None
        """

        def _mean_absolute_error(price: pd.Series,
                                 estimated_price: pd.Series,
                                 normalization_factor: float) -> float:
            """
            Compute the mean absolute error between the actual price
            and the estimated price.

            Args:
                price (float): The actual price.
                estimated_price (float): The estimated price.
                normalization_factor (float): The normalization factor.

            Returns:
                float: The scaled mean absolute error.
            """

            mean_absolute_error: float = normalization_factor * \
                sum(abs(price - estimated_price))

            return mean_absolute_error

        def _root_mean_squared_error(price: pd.Series,
                                     estimated_price: pd.Series,
                                     normalization_factor: float) -> float:
            """
            Compute the root mean squared error (RMSE)
            for the linear regression model.

            Args:
                price (float): The actual price.
                estimated_price (float): The estimated price.
                normalization_factor (float): The normalization factor.

            Returns:
                float: The scaled root mean squared error.

            """

            root_mean_squared_error: float = normalization_factor * \
                sum((price - estimated_price) ** 2) ** 0.5

            return root_mean_squared_error

        def _mean_squared_error(price: pd.Series, estimated_price: pd.Series,
                                normalization_factor: float) -> float:
            """
            Computes the mean squared error between the actual price
            and the estimated price.

            Args:
                price (float): The actual price.
                estimated_price (float): The estimated price.
                normalization_factor (float): The normalization factor.

            Returns:
                float: The scaled mean squared error.
            """

            mean_squared_error: float = normalization_factor * \
                sum((price - estimated_price) ** 2)

            return mean_squared_error

        def _r_squared(price: pd.Series, estimated_price: pd.Series) -> float:
            """
            Compute the coefficient of determination (R-squared)
            for the linear regression model.

            Parameters:
                price (pd.Series): The actual prices.
                estimated_price (pd.Series): The estimated prices.

            Returns:
                float: The coefficient of determination (R-squared) value.
            """
            mean_price: float = sum(price) / len(price)

            ssr: float = sum((price - estimated_price) ** 2)
            sst: float = sum((price - mean_price) ** 2)

            r_squared: float = 1 - (ssr / sst)

            return r_squared

        mileage: pd.Series = self._dataset_unnormal['km']
        price: pd.Series = self._dataset_unnormal['price']

        estimated_price: pd.Series = self._estimate_price(
            self.theta0_unnorm, self.theta1_unnorm, mileage)
        normalization_factor = 1 / len(mileage)

        mean_absolute_error = _mean_absolute_error(
            price, estimated_price, normalization_factor)
        root_mean_squared_error = _root_mean_squared_error(
            price, estimated_price, normalization_factor)
        mean_squared_error = _mean_squared_error(
            price, estimated_price, normalization_factor)
        r_squared = _r_squared(price, estimated_price)

        print("Model accuracy:")
        print(
            "\tMean absolute error: ",
            f"{Fore.GREEN}{mean_absolute_error:.2f}{Style.RESET_ALL}")
        print(
            "\tRoot mean squared error: ",
            f"{Fore.GREEN}{root_mean_squared_error:.2f}{Style.RESET_ALL}")
        print(
            "\tMean squared error: ",
            f"{Fore.GREEN}{mean_squared_error:.2f}{Style.RESET_ALL}")
        print("\tR-squared: ",
              f"{Fore.GREEN}{r_squared:.2f}{Style.RESET_ALL}")
