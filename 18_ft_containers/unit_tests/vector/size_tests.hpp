#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void sizeUnitTests(bool isDebug)
{
    std::cout << YELLOW << "SIZE" << NOCOL << std::endl;
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("when empty:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        std::vector<int> original = returnPopulatedVector<std::vector<int>, int>(1, 1);
        outputAssertion("when populated with 1 int:", isStrictEqual<std::size_t>(0, original.size(), isDebug));
    }
    {
        std::vector<int> original = returnPopulatedVector<std::vector<int>, int>(3, 1);
        outputAssertion("when populated with 3 int:", isStrictEqual<std::size_t>(0, original.size(), isDebug));
    }
    // Should be 3
    // Should be 100
    // Should be 99
}
