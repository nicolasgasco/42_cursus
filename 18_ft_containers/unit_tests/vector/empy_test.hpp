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
        outputAssertion("when empty:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    // Should be 3
    // Should be 100
    // Should be 99
    // for (int i=0; i<100; i++) myvector.push_back(i);
}
