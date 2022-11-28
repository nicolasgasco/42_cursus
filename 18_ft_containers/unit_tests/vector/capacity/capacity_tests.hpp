#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void capacityUnitTests(bool isDebug)
{
    outputSuiteTitle("CAPACITY");
    std::cout << "Is initialized equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(9);
        std::vector<int> original(9);
        outputAssertion("with fill constructor:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(9, 5);
        std::vector<int> original(9, 5);
        outputAssertion("with fill constructor + value:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
}
