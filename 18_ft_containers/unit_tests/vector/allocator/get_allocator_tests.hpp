#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void getAllocatorUnitTests()
{
    outputSuiteTitle("GET_ALLOCATOR");
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("when initialized with empty constructor:", isStrictEqual<std::allocator<int> >(own.get_allocator(), original.get_allocator()));
    }
    {
        ft::vector<int> own(10);
        std::vector<int> original(10);
        outputAssertion("when initialized with fill constructor:", isStrictEqual<std::allocator<int> >(own.get_allocator(), original.get_allocator()));
    }
}
