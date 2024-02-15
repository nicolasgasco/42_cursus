import sys as sys

NESTED_MORSE = {" ": "/ ", "A": ".- ", "B": "-... ", "C": "-.-. ",
                "D": "-.. ", "E": ". ", "F": "..-. ", "G": "--. ",
                "H": ".... ", "I": ".. ", "J": ".--- ", "K": "-.- ",
                "L": ".-.. ", "M": "-- ", "N": "-. ", "O": "--- ",
                "P": ".--. ", "Q": "--.- ",
                "R": ".-. ", "S": "... ",  "T": "- ", "U": "..- ",
                "V": "...- ", "W": ".-- ", "X": "-..- ", "Y": "-.-- ",
                "Z": "--.. ", "0": "----- ", "1": ".---- ", "2": "..--- ",
                "3": "...-- ", "4": "....- ", "5": "..... ", "6": "-.... ",
                "7": "--... ", "8": "---.. ", "9": "----. "}


def main():
    try:
        assert len(sys.argv) == 2, "provide exactly one argument"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)

    string_value = sys.argv[1].upper()

    for c in string_value:
        if c not in NESTED_MORSE.keys():
            print("AssertionError: argument contains invalid characters")
            sys.exit(1)

    res = [NESTED_MORSE[x]
           for x in string_value if x in NESTED_MORSE.keys()]

    print("".join(res))


if __name__ == "__main__":
    main()
