#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void emptyUnitTests(bool isDebug)
{
    outputSuiteTitle("EMPTY");
    std::cout << "Is initialized equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(alloc);
        std::vector<int> original(alloc);
        outputAssertion("with empty constructor (custom allocator):", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(9);
        std::vector<int> original(9);
        outputAssertion("with fill constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(9, 5);
        std::vector<int> original(9, 5);
        outputAssertion("with fill constructor + value:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
}
