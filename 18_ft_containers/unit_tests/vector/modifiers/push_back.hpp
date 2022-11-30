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

    std::cout << std::endl
              << "Array content is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        srand(time(0));
        for (int i = 0; i < 100; ++i)
        {
            int randInt = rand();
            own.push_back(randInt);
            original.push_back(randInt);
        }
        outputAssertion("after 100 random push_back() calls:", isStrictEqual<int>(own.data(), original.data(), 100, isDebug));
    }
}
