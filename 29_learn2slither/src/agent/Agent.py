from training import Training


class Agent:
    def __init__(self):
        self.__training_stats = None
        self.__context = {
            "north": None,
            "east": None,
            "south": None,
            "west": None,
        }

        self.__training = Training()

    @property
    def training_stats(self) -> dict:
        return self.__training_stats

    @training_stats.setter
    def training_stats(self, value: dict) -> None:
        self.__training_stats = value

    @property
    def context(self) -> dict:
        return self.__context

    def update_context(
        self, map: list[list[str]], head_pos: tuple[int, int]
    ) -> None:
        head_y, head_x = head_pos

        self.__context["north"] = [
            {"pos": (y, head_x), "block": map[y][head_x]}
            for y in range(0, head_y)[::-1]  # so that wall is last
        ]
        self.__context["east"] = [
            {"pos": (head_y, x), "block": map[head_y][x]}
            for x in range(head_x + 1, len(map[0]))
        ]
        self.__context["south"] = [
            {"pos": (y, head_x), "block": map[y][head_x]}
            for y in range(head_y + 1, len(map))
        ]
        self.__context["west"] = [
            {"pos": (head_y, x), "block": map[head_y][x]}
            for x in range(0, head_x)[::-1]  # so that wall is last
        ]

    def pick_next_move(self) -> str:
        pick_next_move = self.__training.pick_next_move(self.__context)

        return pick_next_move

    def train(
        self,
        new_block: str,
        prev_context: dict,
        move: str,
    ) -> None:
        if new_block is None:
            return

        self.__training.train(new_block, prev_context, self.__context, move)

    def save_training_data_to_file(self) -> None:
        self.__training.save_training_data_to_file()
