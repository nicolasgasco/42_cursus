import json as json
import os as os


class MapGenerator:
    def __init__(self) -> None:
        settings = self.__parse_settings()

        self.width = settings["width"]
        self.height = settings["height"]

    def __parse_settings(self) -> dict:
        settings_dir_path = os.environ.get('SETTINGS_DIR_PATH')
        map_settings_path = os.path.join(settings_dir_path, "map.json")
        with open(map_settings_path, "r") as file:
            settings = json.load(file)

        return settings

    def __str__(self) -> str:
        return f"MapGenerator(width={self.width}, height={self.height})"