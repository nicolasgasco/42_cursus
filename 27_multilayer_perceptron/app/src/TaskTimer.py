import time as time

from colorama import Fore, Style


class TaskTimer:
    def __init__(self, task_name: str):
        self.task_name = task_name
        self.start_time = time.time()
        self.end_time = None

    def stop(self):
        self.end_time = time.time()
        print(f"{self.task_name} completed in ", end="")
        print(f"{Fore.YELLOW}", end="")
        print(round(self.elapsed_time(), 2), end="")
        print(f"{Style.RESET_ALL}", end="")
        print(" seconds\n")

    def elapsed_time(self):
        if self.end_time is None:
            return time.time() - self.start_time
        return self.end_time - self.start_time
