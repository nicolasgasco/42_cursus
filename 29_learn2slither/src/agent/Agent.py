from constants import SnakeDirection


class Agent:
    def __init__(self):
        self.__training_stats = None
        self.__context = {
            "north": None,
            "south": None,
            "east": None,
            "west": None,
        }

    @property
    def training_stats(self) -> dict:
        return self.__training_stats

    @training_stats.setter
    def training_stats(self, value: dict) -> None:
        self.__training_stats = value

    @property
    def context(self) -> dict:
        return self.__context

    def update_context(self, args: dict) -> None:
        map = args["map"]
        head_y, head_x = args["head_pos"]

        self.__context["north"] = [
            {"pos": (y, head_x), "block": map[y][head_x]}
            for y in range(0, head_y)
        ]
        self.__context["south"] = [
            {"pos": (y, head_x), "block": map[y][head_x]}
            for y in range(head_y + 1, len(map))
        ]
        self.__context["east"] = [
            {"pos": (head_y, x), "block": map[head_y][x]}
            for x in range(head_x + 1, len(map[0]))
        ]
        self.__context["west"] = [
            {"pos": (head_y, x), "block": map[head_y][x]}
            for x in range(0, head_x)
        ]
