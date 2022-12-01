
#include <iostream>

// Capacity
#include "capacity/size_tests.hpp"
#include "capacity/capacity_tests.hpp"
#include "capacity/empy_test.hpp"
#include "capacity/max_size_test.hpp"
#include "capacity/reserve.hpp"

// Allocator
#include "allocator/get_allocator_tests.hpp"

// Access
#include "access/random_access_tests.hpp"
#include "access/data.hpp"
#include "access/front.hpp"
#include "access/back.hpp"
#include "access/at.hpp"

// Modifiers
#include "modifiers/push_back.hpp"
#include "modifiers/pop_back.hpp"
#include "modifiers/resize.hpp"
#include "modifiers/clear.hpp"

// Operators
#include "operators/equal.hpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << YELLOW << "VECTOR UNIT TESTS" << NOCOL << std::endl;

    // Capacity
    sizeUnitTests(IS_DEBUG);
    capacityUnitTests(IS_DEBUG);
    emptyUnitTests(IS_DEBUG);
    maxSizeUnitTests(IS_DEBUG);
    reserveUnitTests(IS_DEBUG);

    // Allocator
    getAllocatorUnitTests(IS_DEBUG);

    // Access
    randomAccessUnitTests(IS_DEBUG);
    dataUnitTests(IS_DEBUG);
    frontUnitTests(IS_DEBUG);
    backUnitTests(IS_DEBUG);
    atUnitTests(IS_DEBUG);

    // Modifiers
    pushBackUnitTests(IS_DEBUG);
    popBackUnitTests(IS_DEBUG);
    resizeUnitTests(IS_DEBUG);
    clearUnitTests(IS_DEBUG);

    // Operators
    equalUnitTests(IS_DEBUG);

    std::cout
        << std::endl;
    return (0);
}