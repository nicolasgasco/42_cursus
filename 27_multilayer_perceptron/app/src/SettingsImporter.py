import json as json
import os as os

from colorama import Fore, Style


class SettingsImporter:
    def __init__(self, settings_filename: str):
        settings_dir_path: str | None = os.environ.get(
            "SETTINGS_DIR_PATH")
        assert settings_dir_path is not None, "SettingsImporter: invalid SETTINGS_DIR_PATH env var."
        self._settings_dir_path: str = settings_dir_path

        assert settings_filename is not None, "SettingsImporter: invalid settings_filename."
        self._settings_file_path: str = os.path.join(
            self._settings_dir_path, settings_filename)

    def import_settings(self) -> dict:
        print(
            f"Importing settings from {Fore.YELLOW}{self._settings_file_path}{Style.RESET_ALL}...\n")

        try:
            with open(self._settings_file_path) as file:
                settings_data = json.load(file)

                return settings_data
        except FileNotFoundError:
            raise FileNotFoundError(
                "SettingsImporter: Settings file not found.")
