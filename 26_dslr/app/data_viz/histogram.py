from DataImporter import DataImporter
from Plot import Plot

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

    while True:
        output_options(subjects)
        choice: str = input()

        if is_valid_input(choice, subject_letters):
            return choice


def output_options(subjects: list[str]):
    """
    Prints the options for subjects.

    Args:
        subjects (list[str]): A list of subjects.

    Returns:
        None
    """

    for i, subject in enumerate(subjects):
        print(f"{ALPHABET[i]}) {subject}")


def is_valid_input(choice: str, subject_letters: str) -> bool:
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


def main():
    importer = DataImporter()

    train_set, _ = importer.get_sets()

    plot = Plot(train_set)

    subjects: list[str] = train_set.columns.values[6:].tolist()
    subjects: list[str] = sorted(subjects)

    subject_letters: str = ALPHABET[:len(subjects)]

    print("Choose a subject to see the score distribution:\n")

    try:
        while True:
            choice: str = get_user_input(subjects, subject_letters)

            chosen_subject: str = subjects[ALPHABET.index(choice)]

            print(f"Plotting score distribution for {chosen_subject}...")
            plot.plot_score_distribution(chosen_subject)

            print("\n")
    except KeyboardInterrupt:
        print("\nPlotting score distribution for all subjects...")
        plot.plot_score_distributions()
        print("Bye...")


if __name__ == "__main__":
    main()
