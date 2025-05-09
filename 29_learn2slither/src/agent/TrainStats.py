class TrainStats:
    def __init__(self):
        self.__games_lost = 0
        self.__games_won = 0

    @property
    def games_won(self) -> int:
        return self.__games_won

    @games_won.setter
    def games_won(self, value: int) -> None:
        self.__games_won = value

    @property
    def games_lost(self) -> int:
        return self.__games_lost

    @games_lost.setter
    def games_lost(self, value: int) -> None:
        self.__games_lost = value
