from new_student import Student


def main():
    student = Student(name="Edward", surname="agle")
    print(student)

    try:
        student = Student(name="Edward", surname="agle", id="toto")
        print(student)
    except TypeError as e:
        print(e)


if __name__ == "__main__":
    main()
