#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void capacityUnitTests(bool isDebug)
{
    std::cout << YELLOW << "CAPACITY" << NOCOL << std::endl;
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("when empty:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    // Should be 3
    // Should be 100
    // Should be 99
    // for (int i=0; i<100; i++) myvector.push_back(i);
}
