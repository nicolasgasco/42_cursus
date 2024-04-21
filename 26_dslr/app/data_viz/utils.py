ALPHABET: str = "abcdefghijklmnopqrstuvwxyz"


def get_user_input(subjects: list[str], subject_letters: str):
    """
    Prompts the user to enter a choice from the available subjects
    and validates the input.

    Args:
        subjects (list[str]): A list of available subjects.
        subject_letters (str): A string containing the valid letters
        for subject selection.

    Returns:
        str: The user's choice of subject.

    """

    def _output_options(subjects: list[str]):
        """
        Prints the options for subjects.

        Args:
            subjects (list[str]): A list of subjects.

        Returns:
            None
        """

        for i, subject in enumerate(subjects):
            print(f"{ALPHABET[i]}) {subject}")

    def _is_valid_input(choice: str, subject_letters: str) -> bool:
        """
        Check if the input choice is valid.

        Parameters:
        - choice (str): The input choice to be validated.
        - subject_letters (str): The valid letters for the choice.

        Returns:
        - bool: True if the choice is valid, False otherwise.
        """

        if len(choice) != 1 or choice not in subject_letters:
            print("\nInvalid input. Please choose a valid option.")
            return False
        return True

    while True:
        _output_options(subjects)
        choice: str = input()

        if _is_valid_input(choice, subject_letters):
            return choice
