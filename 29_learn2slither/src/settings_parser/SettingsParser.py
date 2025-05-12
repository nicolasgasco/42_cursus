import json as json
import os as os

from constants import SETTINGS_DIR_PATH


class SettingsParser:
    def __init__(self, type: str):
        self.__type = type
        self.__settings = self.__parse_settings()

    @property
    def settings(self) -> dict:
        return self.__settings

    def __parse_settings(self):
        file_name = self.__get_file_name()
        # TODO improve this
        map_settings_path = os.path.join("..", SETTINGS_DIR_PATH, file_name)

        with open(map_settings_path, "r") as file:
            settings = json.load(file)

        return settings

    def __get_file_name(self) -> str:
        if self.__type == "map":
            return "map.json"
        elif self.__type == "train":
            return "train.json"
        else:
            raise ValueError("Invalid settings type. Use 'map' or 'train'.")
