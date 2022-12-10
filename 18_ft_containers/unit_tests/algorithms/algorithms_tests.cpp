#include <iostream>

#include "swap.cpp"
#include "equal.cpp"
#include "lexicographical_compare.cpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << std::endl
              << YELLOW << "ALGORITHMS UNIT TESTS" << NOCOL << std::endl;

    ftSwapUnitTests(IS_DEBUG);
    ftEqualUnitTests(IS_DEBUG);
    ftLexicoGraphicalCompareUnitTests(IS_DEBUG);
    return (1);
}