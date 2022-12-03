#include <iostream>

#include "algorithms/swap.cpp"

void algorithmsUnitTests(bool IS_DEBUG)
{
    std::cout << std::endl
              << YELLOW << "ALGORITHMS UNIT TESTS" << NOCOL << std::endl;

    ftSwapUnitTests(IS_DEBUG);
}