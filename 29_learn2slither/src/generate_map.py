from map import MapGenerator


def main():
    map_generator = MapGenerator()
    print(map_generator)

    print("Generating map...\n")
    map_generator.generate_map()

    print(map_generator.map, "\n")

    print("Saving map to file...\n")
    path = map_generator.save_map_to_file()
    print(f"Map saved to: {path}")


if __name__ == "__main__":
    main()
