from DiamondTrap import King


def main():
    Joffrey = King("Joffrey")
    print(Joffrey.__dict__)
    Joffrey.set_eyes("blue")
    Joffrey.set_hair("light")
    print(Joffrey.get_eyes())
    print(Joffrey.get_hair())
    print(Joffrey.__dict__)


if __name__ == "__main__":
    main()
