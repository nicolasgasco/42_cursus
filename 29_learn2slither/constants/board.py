from enum import Enum


class BoardBlockSymbol(Enum):
    BODY = "🟢"
    EMPTY = "⬛"
    GREEN_APPLE = "🍏"
    HEAD = "🐸"
    RED_APPLE = "🍎"
    WALL = "⬜"
    VICTORY = "🏆"


BLANK_CHARACTER = "❔"
