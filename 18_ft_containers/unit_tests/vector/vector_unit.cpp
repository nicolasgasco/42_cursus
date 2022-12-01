
#include <iostream>

// Capacity
#include "capacity/size.cpp"
#include "capacity/capacity.cpp"
#include "capacity/empy.cpp"
#include "capacity/max_size.cpp"
#include "capacity/reserve.cpp"

// Allocator
#include "allocator/get_allocator.cpp"

// Access
#include "access/random_access.cpp"
#include "access/data.cpp"
#include "access/front.cpp"
#include "access/back.cpp"
#include "access/at.cpp"

// Modifiers
#include "modifiers/push_back.cpp"
#include "modifiers/pop_back.cpp"
#include "modifiers/resize.cpp"
#include "modifiers/clear.cpp"

// Operators
#include "operators/equal.cpp"

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