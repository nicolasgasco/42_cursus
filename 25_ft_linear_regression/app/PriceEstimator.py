class PriceEstimator:
    def __init__(self, theta_0=0.0, theta_1=0.0):

        self.__theta_0 = theta_0
        self.__theta_1 = theta_1

    def __repr__(self):
        return f"[theta_0={self.__theta_0}] [theta_1={self.__theta_1}]"

    def estimate(self, mileage):
        scaled_mileage = mileage / 1_000

        scaled_estimate = self.__theta_0 + self.__theta_1 * scaled_mileage

        return scaled_estimate * 1_000
