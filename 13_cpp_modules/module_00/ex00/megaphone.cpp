#include <cstring>
#include <iostream>

void outputStringUpper(char *str) {
    for (int y = 0; y < (int)strlen(str); ++y) {
        std::cout << (char)toupper(str[y]);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; ++i) {
        outputStringUpper(argv[i]);
    }
    std::cout << std::endl;
    return 0;
}
