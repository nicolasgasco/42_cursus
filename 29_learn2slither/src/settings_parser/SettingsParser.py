from constants import SETTINGS_DIR_PATH
import json as json
import os as os


class SettingsParser:
    def __init__(self):
        self.settings = self.__parse_settings()

    def __parse_settings(self):
        file_name = "map.json"
        # TODO improve this
        map_settings_path = os.path.join("..", SETTINGS_DIR_PATH, file_name)

        with open(map_settings_path, "r") as file:
            settings = json.load(file)

        return settings
