from MapGenerator import MapGenerator


def main():
    generator = MapGenerator()
    print(generator)

    print("Generating map...\n")
    generator.generate_map()

    print(generator.map, "\n")

    print("Saving map to file...\n")
    path = generator.save_map_to_file()
    print(f"Map saved to: {path}")


if __name__ == "__main__":
    main()
