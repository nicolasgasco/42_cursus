import tkinter as tk
from MapBlock import MapBlock
from constants import MAPS_DIR_PATH
from settings_parser import SettingsParser
from os import path

def main():
    root = tk.Tk()
    root.title("Learn2Slither")
    root.configure(bg="black")
    
    settings = SettingsParser().settings
    map_file_name = settings["file_name"]
    assert map_file_name, "Map file name not found in settings."
    
    # Read file line by line
    map_file_path = path.join("..", "..", MAPS_DIR_PATH, map_file_name)
    print(f"Map file path: {map_file_path}")
    with open(map_file_path, "r") as file:
        map_rows = file.readlines()
        map_rows = [row.strip() for row in map_rows]

    for y, row in enumerate(map_rows):
        for x, block in enumerate(row):
            gui_block = MapBlock({
                "block": block
            })
            gui_block.grid(row=x, column=y)

    root.mainloop()


if __name__ == "__main__":
    main()
