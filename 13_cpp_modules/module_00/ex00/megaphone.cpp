#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < argc; ++i) {
            for (int y = 0; y < strlen(argv[i]); ++y) {
                std::cout << (char)toupper(argv[i][y]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}