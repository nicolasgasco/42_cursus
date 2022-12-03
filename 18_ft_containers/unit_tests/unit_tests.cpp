
#include <iostream>

// ===========================================
// VECTOR
// ===========================================
// Capacity
#include "vector/capacity/size.cpp"
#include "vector/capacity/capacity.cpp"
#include "vector/capacity/empy.cpp"
#include "vector/capacity/max_size.cpp"
#include "vector/capacity/reserve.cpp"

// Other
#include "vector/other/get_allocator.cpp"
#include "vector/other/assign.cpp"

// Access
#include "vector/access/random_access.cpp"
#include "vector/access/data.cpp"
#include "vector/access/front.cpp"
#include "vector/access/back.cpp"
#include "vector/access/at.cpp"

// Modifiers
#include "vector/modifiers/push_back.cpp"
#include "vector/modifiers/pop_back.cpp"
#include "vector/modifiers/resize.cpp"
#include "vector/modifiers/clear.cpp"
#include "vector/modifiers/swap.cpp"

// Iterator
#include "vector/iterators/begin.cpp"

// Operators
#include "vector/operators/equal.cpp"
#include "vector/operators/not_equal.cpp"

// ===========================================
// ALGORITHM
// ===========================================
#include "algorithms/swap.cpp"

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

    // Other
    getAllocatorUnitTests(IS_DEBUG);
    assignUnitTests(IS_DEBUG);

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

    // Iterator
    beginUnitTests(IS_DEBUG);

    // Operators
    equalUnitTests(IS_DEBUG);
    notEqualUnitTests(IS_DEBUG);

    std::cout << std::endl
              << YELLOW << "ALGORITHMS UNIT TESTS" << NOCOL << std::endl;
    ftSwapUnitTests(IS_DEBUG);

    std::cout
        << std::endl;
    return (0);
}