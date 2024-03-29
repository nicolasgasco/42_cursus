class PriceEstimator:
    def __init__(self, mileage, theta_0=0.0, theta_1=0.0):
        self._mileage = mileage / 1_000

        self.__theta_0 = theta_0
        self.__theta_1 = theta_1

        self.value = self._calc_value() * 1_000

    def __repr__(self):
        return f"[mileage={self._mileage}] [value={self.value}] \
            [theta_0={self.__theta_0}] [theta_1={self.__theta_1}]"

    def _calc_value(self):
        return self.__theta_0 + self.__theta_1 * self._mileage

    def estimate_price(self):
        return self.value
