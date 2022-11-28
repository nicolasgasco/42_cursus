#pragma once

#include "utils.hpp"
#include "../../vector/Vector.hpp"

void maxSizeUnitTests(bool isDebug)
{
    std::cout << YELLOW << "MAX SIZE" << NOCOL << std::endl;
    std::cout << "Is strictly equal to 42-provided value:" << std::endl;
    {
        ft::vector<int> own;
        // Mock max_size is provided by 42
        outputAssertion("when empty:", isStrictEqual<int>(own.max_size(), 1047552, isDebug));
    }
    // with more elements
}
