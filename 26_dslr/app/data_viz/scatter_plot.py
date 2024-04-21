from DataImporter import DataImporter
from Plot import Plot

from utils import get_user_input

ALPHABET: str = "abcdefghijklmnopqrstuvwxyz"


def main():
    importer = DataImporter()

    train_set, _ = importer.get_sets()

    plot = Plot(train_set)

    subjects: list[str] = train_set.columns.values[6:].tolist()
    subjects: list[str] = sorted(subjects)

    subject_letters: str = ALPHABET[:len(subjects)]

    try:
        while True:
            print("Choose a first subject to compare:\n")
            first_choice: str = get_user_input(subjects, subject_letters)
            first_chosen_subject: str = subjects[ALPHABET.index(first_choice)]

            print("Choose a second subject to compare:\n")
            second_choice: str = get_user_input(subjects, subject_letters)
            second_chosen_subject: str = subjects[ALPHABET.index(
                second_choice)]

            print(
                "Plotting comparison between",
                f"{first_chosen_subject} and {second_chosen_subject}...")
            plot.plot_similarity(first_chosen_subject, second_chosen_subject)

            print("\n")
    except KeyboardInterrupt:
        print("\nPlotting comparison for all subject pairs...")
        plot.plot_similarities()
        print("Bye...")


if __name__ == "__main__":
    main()
