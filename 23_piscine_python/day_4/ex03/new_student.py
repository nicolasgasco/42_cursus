import random
import string
from dataclasses import dataclass, field


def generate_id() -> str:
    """
    Generate a random ID consisting of 15 lowercase letters.

    Returns:
        str: A random ID.
    """
    return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
    """
    Represents a student with a name, surname, active status, login, and ID.
    """

    name: str
    surname: str
    active: bool = field(init=False, default=True)
    login: str = field(init=False)
    id: str = field(init=False, default_factory=generate_id)

    def __post_init__(self):
        self.login = f"{self.name[0]}{self.surname}"
