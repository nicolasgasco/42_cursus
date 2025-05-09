class Agent:
    def __init__(self):
        self.__training_stats = None

    @property
    def training_stats(self) -> dict:
        return self.__training_stats

    @training_stats.setter
    def training_stats(self, value: dict) -> None:
        self.__training_stats = value
