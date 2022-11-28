#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void maxSizeUnitTests(bool isDebug)
{
    std::cout << YELLOW << "MAX SIZE" << NOCOL << std::endl;
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("when empty:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
}
