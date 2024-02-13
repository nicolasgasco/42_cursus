import sys as sys


def main():
    """
    This function takes user input or command line argument and counts
    the number of uppercase letters, lowercase letters,
    punctuation marks, spaces, and digits in the given text.
    It then prints the counts along with the total number of characters.
    """

    argc = len(sys.argv)

    assert (argc <= 2), "more than one argument is provided"

    arg_value = None

    if (argc == 1):
        while (arg_value is None):
            try:
                arg_value = input("What is the text to count?\n")
            except EOFError:
                print("Error: EOF detected")
                continue

    if (argc == 2):
        arg_value = sys.argv[1]

    arg_value = str(arg_value)

    count_uppercase = 0
    count_lowercase = 0
    count_digit = 0
    count_punctuation = 0
    count_space = 0

    for c in arg_value:
        if c.isupper():
            count_uppercase += 1
        elif c.islower():
            count_lowercase += 1
        elif c.isdigit():
            count_digit += 1
        elif c.isspace() or c == "\r" or c == "¶":
            count_space += 1
        else:
            count_punctuation += 1

    print(f"The text contains {len(arg_value)} characters:")
    print(f"{count_uppercase} upper letters")
    print(f"{count_lowercase} lower letters")
    print(f"{count_punctuation} punctuation marks")
    print(f"{count_space} spaces")
    print(f"{count_digit} digits")


if __name__ == "__main__":
    main()
