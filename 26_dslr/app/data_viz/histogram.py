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

    print("Choose a subject to see the score distribution:\n")

    choice: str = get_user_input(subjects, subject_letters)

    chosen_subject: str = subjects[ALPHABET.index(choice)]

    print(f"Plotting score distribution for {chosen_subject}...")
    plot.plot_score_distribution(chosen_subject)

    print("\n")

    print("Plotting score distribution for all subjects...")
    plot.plot_score_distributions()
    print("Bye...")


if __name__ == "__main__":
    main()
