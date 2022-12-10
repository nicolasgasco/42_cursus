#include <vector>

#include "../utils.hpp"
#include "../../vector.hpp"
#include "../../pair.hpp"

#include "pair.cpp"
#include "make_pair.cpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << std::endl
              << YELLOW << "PAIR UNIT TESTS" << NOCOL << std::endl;
    pairUnitTests(IS_DEBUG);
    makePairUnitTests(IS_DEBUG);
}