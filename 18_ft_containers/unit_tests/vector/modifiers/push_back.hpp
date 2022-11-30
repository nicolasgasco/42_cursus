#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void pushBackUnitTests(bool isDebug)
{
    outputSuiteTitle("PUSH_BACK");
    std::cout << "Pushed value is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        own.reserve(1);
        own.push_back(5);
        std::vector<int> original;
        original.reserve(1);
        original.push_back(5);
        outputAssertion("without reallocation:", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(5);
        std::vector<int> original;
        original.push_back(5);
        outputAssertion("with allocation (size = 0):", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own(1, 10);
        own.push_back(5);
        std::vector<int> original(1, 10);
        original.push_back(5);
        outputAssertion("with allocation (size = 1):", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own(10, 10);
        own.push_back(5);
        std::vector<int> original(10, 10);
        original.push_back(5);
        outputAssertion("with allocation (size = 10):", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
}
