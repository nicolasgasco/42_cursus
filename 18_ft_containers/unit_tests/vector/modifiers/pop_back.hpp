#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void popBackUnitTests(bool isDebug)
{
    outputSuiteTitle("POP_BACK");
    std::cout << "Back value after pop() is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        own.push_back(5);
        own.push_back(10);
        own.pop_back();
        std::vector<int> original;
        original.push_back(5);
        original.push_back(10);
        original.pop_back();
        outputAssertion("with size = 2:", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(5);
        own.push_back(10);
        own.push_back(3);
        own.pop_back();
        std::vector<int> original;
        original.push_back(5);
        original.push_back(10);
        original.push_back(3);
        original.pop_back();
        outputAssertion("with size = 3:", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(5);
        own.push_back(10);
        own.push_back(3);
        own.push_back(25);
        own.push_back(13);
        own.pop_back();
        std::vector<int> original;
        original.push_back(5);
        original.push_back(10);
        original.push_back(3);
        original.push_back(25);
        original.push_back(13);
        original.pop_back();
        outputAssertion("with size = 5:", isStrictEqual<int>(own.back(), original.back(), isDebug));
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
        for (int i = 0; i < 50; ++i)
        {
            own.pop_back();
            original.pop_back();
        }
        outputAssertion("after 100 random push_back() followed by 50 pop_back() calls:", isStrictEqual<int>(own.data(), original.data(), 50, isDebug));
    }
}