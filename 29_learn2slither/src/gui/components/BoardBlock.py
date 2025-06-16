import tkinter as tk

from constants import BLACK, GREY, BoardBlockSymbol

SQUARE_SIZE = 60


class BoardBlock(tk.Canvas):
    def __init__(self, args):
        self.__block = args.get("block", BoardBlockSymbol.EMPTY.value)

        super().__init__(
            args["parent"],
            bg=self.__get_bg_color(self.__block),
            height=SQUARE_SIZE,
            highlightthickness=0.5,
            width=SQUARE_SIZE,
        )

        self.__create_text()

    def __create_text(self) -> None:
        self.create_text(
            SQUARE_SIZE // 2,
            SQUARE_SIZE // 2,
            text=self.__get_text(self.__block),
            font=("Arial", SQUARE_SIZE - 30),
        )

    def __get_text(self, block_value: str) -> str:
        blocks_with_text = [
            BoardBlockSymbol.BODY.value,
            BoardBlockSymbol.HEAD.value,
            BoardBlockSymbol.GREEN_APPLE.value,
            BoardBlockSymbol.RED_APPLE.value,
            BoardBlockSymbol.VICTORY.value,
        ]
        if block_value in blocks_with_text:
            return block_value

        blocks_without_text = [
            BoardBlockSymbol.EMPTY.value,
            BoardBlockSymbol.WALL.value,
        ]
        if block_value in blocks_without_text:
            return None

        raise ValueError(f"Unknown block value: {block_value}")

    def __get_bg_color(self, block_value: str) -> str:

        blocks_with_black_bg = [
            BoardBlockSymbol.EMPTY.value,
            BoardBlockSymbol.BODY.value,
            BoardBlockSymbol.HEAD.value,
            BoardBlockSymbol.GREEN_APPLE.value,
            BoardBlockSymbol.RED_APPLE.value,
            BoardBlockSymbol.VICTORY.value,
        ]
        if block_value in blocks_with_black_bg:
            return BLACK

        blocks_with_grey_bg = [BoardBlockSymbol.WALL.value]
        if block_value in blocks_with_grey_bg:
            return GREY

        raise ValueError(f"Unknown block value: {block_value}")
