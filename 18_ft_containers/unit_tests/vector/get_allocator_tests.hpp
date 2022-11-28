#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void getAllocatorUnitTests(bool isDebug)
{
    outputSuiteTitle("GET_ALLOCATOR");
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("when initialized with empty constructor:", isStrictEqual<std::string>(typeid(own.get_allocator()).name(), typeid(original.get_allocator()).name(), isDebug));
    }
}
