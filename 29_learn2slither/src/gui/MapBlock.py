import tkinter as tk
from constants.board import BoardBlock

SQUARE_SIZE = 30

class MapBlock(tk.Canvas):
  def __init__(self, args):
    self.__block = args["block"] if "block" in args else BoardBlock.EMPTY.name

    super().__init__(
      bg=self.__get_bg_color(self.__block),
      height=SQUARE_SIZE,
      highlightthickness=0.5,
      width=SQUARE_SIZE,
    )
            
  def __get_bg_color(self, block_name: str) -> str:
    """
    Returns the background color for the given color.
    Args:
        color (str): The color to get the background color for.
    Returns:
        str: The background color for the given color.
    """
    if block_name == BoardBlock.EMPTY.name:
      return "black"
    elif block_name == BoardBlock.BODY.name:
      return "green"
    elif block_name == BoardBlock.HEAD.name:
      return "green"
    elif block_name == BoardBlock.GREEN_APPLE.name:
      return "green"
    elif block_name == BoardBlock.RED_APPLE.name:
      return "red"
    elif block_name == BoardBlock.WALL.name:
      return "white"
    else:
      raise ValueError(f"Unknown block name: {block_name}")
      