class PriceEstimator:
    def __init__(self, theta_0=0.0, theta_1=0.0):

        self.__theta_0 = theta_0
        self.__theta_1 = theta_1

    def estimate(self, mileage):
        """
        Estimates the price of a car based on its mileage.

        Args:
            mileage (float): The mileage of the car.

        Returns:
            float: The estimated price of the car.
        """

        scaled_mileage = mileage

        scaled_estimate = self.__theta_0 + self.__theta_1 * scaled_mileage

        return scaled_estimate
