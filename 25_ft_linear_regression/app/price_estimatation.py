def get_mileage_input():
    """
    Get the mileage input from the user.

    Returns:
        int: The mileage value entered by the user.
    """
    while True:
        user_input = input("Enter the mileage (integer value, no separator): ")

        try:
            mileage = int(user_input)
            break
        except ValueError:
            print("Please enter a valid value.")

    return mileage


def main():
    mileage = get_mileage_input()

    print(mileage)


if __name__ == "__main__":
    main()
