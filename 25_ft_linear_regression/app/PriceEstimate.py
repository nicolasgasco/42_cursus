class PriceEstimate:
    def __init__(self, mileage):
        self.mileage = mileage

        self.__theta_0 = 0
        self.__theta_1 = 0

        self.value = self.__theta_0 + self.__theta_1 * self.mileage

    def __repr__(self):
        return f"[mileage={self.mileage}] [value={self.value}]"
