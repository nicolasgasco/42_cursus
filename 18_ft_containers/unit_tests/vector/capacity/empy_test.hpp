#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void emptyUnitTests(bool isDebug)
{
    outputSuiteTitle("EMPTY");
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(9);
        std::vector<int> original(9);
        outputAssertion("with fill constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
}
