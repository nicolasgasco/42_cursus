import tkinter as tk
from constants import BoardBlockSymbol, BLACK, GREY

SQUARE_SIZE = 80


class BoardBlock(tk.Canvas):
    def __init__(self, args):
        self.__block = (
            args["block"] if "block" in args else BoardBlockSymbol.EMPTY.name
        )

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
        """
        Returns the text for the given color.
        Args:
            color (str): The color to get the text for.
        Returns:
            str: The text for the given color.
        """
        if block_value == BoardBlockSymbol.EMPTY.value:
            return None
        elif block_value == BoardBlockSymbol.BODY.value:
            return BoardBlockSymbol.BODY.value
        elif block_value == BoardBlockSymbol.HEAD.value:
            return BoardBlockSymbol.HEAD.value
        elif block_value == BoardBlockSymbol.GREEN_APPLE.value:
            return BoardBlockSymbol.GREEN_APPLE.value
        elif block_value == BoardBlockSymbol.RED_APPLE.value:
            return BoardBlockSymbol.RED_APPLE.value
        elif block_value == BoardBlockSymbol.WALL.value:
            return None
        else:
            raise ValueError(f"Unknown block value: {block_value}")

    def __get_bg_color(self, block_value: str) -> str:
        """
        Returns the background color for the given color.
        Args:
            color (str): The color to get the background color for.
        Returns:
            str: The background color for the given color.
        """

        if block_value == BoardBlockSymbol.EMPTY.value:
            return BLACK
        elif block_value == BoardBlockSymbol.BODY.value:
            return BLACK
        elif block_value == BoardBlockSymbol.HEAD.value:
            return BLACK
        elif block_value == BoardBlockSymbol.GREEN_APPLE.value:
            return BLACK
        elif block_value == BoardBlockSymbol.RED_APPLE.value:
            return BLACK
        elif block_value == BoardBlockSymbol.WALL.value:
            return GREY
        else:
            raise ValueError(f"Unknown block value: {block_value}")
