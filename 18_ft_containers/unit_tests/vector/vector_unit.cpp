
#include <iostream>

// Capacity
#include "capacity/size_tests.hpp"
#include "capacity/capacity_tests.hpp"
#include "capacity/empy_test.hpp"
#include "capacity/max_size_test.hpp"

// Allocator
#include "get_allocator_tests.hpp"

// Access
#include "access/random_access_tests.hpp"

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
    getAllocatorUnitTests();

    // Access
    randomAccessUnitTests(IS_DEBUG);

    std::cout
        << std::endl;
    return (0);
}