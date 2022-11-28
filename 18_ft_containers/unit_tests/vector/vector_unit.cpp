
#include <iostream>
#include "size_tests.hpp"
#include "capacity_tests.hpp"
#include "empy_test.hpp"
#include "max_size_test.hpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << YELLOW << "VECTOR UNIT TESTS" << NOCOL << std::endl;

    /*
     * MEMBER FUNCTIONS
     */
    sizeUnitTests(IS_DEBUG);
    capacityUnitTests(IS_DEBUG);
    emptyUnitTests(IS_DEBUG);
    maxSizeUnitTests(IS_DEBUG);

    return (0);
}