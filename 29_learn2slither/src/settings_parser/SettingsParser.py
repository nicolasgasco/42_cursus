import json as json
import os as os

from constants import (
    MAP_SETTINGS_FILE_NAME,
    SETTINGS_DIR_PATH,
    TRAIN_SETTINGS_FILE_NAME,
)


class SettingsParser:
    def __init__(self, type: str):
        self.__settings = self.__parse_settings(type)

    @property
    def settings(self) -> dict:
        return self.__settings

    def __parse_settings(self, type: str) -> dict:
        file_name = self.__get_file_name(type)
        # TODO improve this
        map_settings_path = os.path.join("..", SETTINGS_DIR_PATH, file_name)

        with open(map_settings_path, "r") as file:
            settings = json.load(file)

        return settings

    def __get_file_name(self, type: str) -> str:
        if type == "map":
            return MAP_SETTINGS_FILE_NAME
        elif type == "train":
            return TRAIN_SETTINGS_FILE_NAME
        else:
            raise ValueError("Invalid settings type. Use 'map' or 'train'.")
