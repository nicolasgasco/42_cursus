#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void maxSizeUnitTests(bool isDebug)
{
    outputSuiteTitle("MAX SIZE");
    std::cout << "Is initialized equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(alloc);
        std::vector<int> original(alloc);
        outputAssertion("with empty constructor (custom allocator):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
    {
        ft::vector<int> own(9);
        std::vector<int> original(9);
        outputAssertion("with fill constructor:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
    {
        ft::vector<int> own(9, 5);
        std::vector<int> original(9, 5);
        outputAssertion("with fill constructor + value:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
}
