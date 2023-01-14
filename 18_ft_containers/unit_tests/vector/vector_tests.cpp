#include <iostream>

// Capacity
#include "capacity/size.cpp"
#include "capacity/capacity.cpp"
#include "capacity/empy.cpp"
#include "capacity/max_size.cpp"
#include "capacity/reserve.cpp"

// Other
#include "other/get_allocator.cpp"
#include "other/assign_operator.cpp"

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
#include "modifiers/swap.cpp"
#include "modifiers/insert.cpp"
#include "modifiers/assign.cpp"
#include "modifiers/erase.cpp"

// Iterator
#include "iterators/begin.cpp"
#include "iterators/end.cpp"
#include "iterators/rbegin.cpp"
#include "iterators/rend.cpp"

// Operators
#include "operators/equal.cpp"
#include "operators/not_equal.cpp"
#include "operators/less_than.cpp"
#include "operators/less_than_equal.cpp"
#include "operators/greater_than.cpp"
#include "operators/greater_than_equal.cpp"

// SPEED
#include "speed/vector_speed_tests.cpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << TITLE << "VECTOR UNIT TESTS" << NOCOL_H1 << std::endl;

    // Capacity
    sizeUnitTests(IS_DEBUG);
    capacityUnitTests(IS_DEBUG);
    emptyUnitTests(IS_DEBUG);
    maxSizeUnitTests(IS_DEBUG);
    reserveUnitTests(IS_DEBUG);

    // Other
    getAllocatorUnitTests(IS_DEBUG);
    assignOperatorUnitTests(IS_DEBUG);

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
    swapUnitTests(IS_DEBUG);
    insertUnitTests(IS_DEBUG);
    assignUnitTests(IS_DEBUG);
    eraseUnitTests(IS_DEBUG);

    // Iterator
    beginUnitTests(IS_DEBUG);
    endUnitTests(IS_DEBUG);
    rBeginUnitTests(IS_DEBUG);
    rEndUnitTests(IS_DEBUG);

    // Operators
    equalUnitTests(IS_DEBUG);
    notEqualUnitTests(IS_DEBUG);
    lessThanUnitTests(IS_DEBUG);
    lessThanEqualUnitTests(IS_DEBUG);
    greaterThanUnitTests(IS_DEBUG);
    greaterThanEqualUnitTests(IS_DEBUG);

    // SPEED
    speedUnitTests(IS_DEBUG);

    return (0);
}