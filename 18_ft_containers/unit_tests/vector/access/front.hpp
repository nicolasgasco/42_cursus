#pragma once

#include <vector>

#include "utils.hpp"
#include "../../vector/Vector.hpp"

void frontUnitTests(bool isDebug)
{
    outputSuiteTitle("FRONT");
    std::cout << "Value is equal to STL vector value:" << std::endl;
    std::cout << "  NOT CONST" << std::endl;
    // Undefined behaviour with empty constructor
    {
        ft::vector<int> own(1, 10);
        std::vector<int> original(1, 10);
        outputAssertion("with fill costructor (num: 1, value:10):", isStrictEqual<int &>(own.front(), original.front(), isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("with fill costructor (num: 5, value:10):", isStrictEqual<int &>(own.front(), original.front(), isDebug));
    }
    std::cout << "  CONST" << std::endl;
    // Undefined behaviour with empty constructor
    {
        ft::vector<int> const own(1, 10);
        std::vector<int> const original(1, 10);
        outputAssertion("with fill costructor (num: 1, value:10):", isStrictEqual<int const &>(own.front(), original.front(), isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("with fill costructor (num: 5, value:10):", isStrictEqual<int const &>(own.front(), original.front(), isDebug));
    }

    std::cout << std::endl
              << "Const check compared to STL vector value:" << std::endl;
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("is not const with fill costructor (num: 5, value:10):", isStrictEqual<bool>(isConst(own.front()), isConst(original.front()), isDebug));
    }
    {
        ft::vector<int> const own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("is const with fill costructor (num: 5, value:10):", isStrictEqual<bool>(isConst(own.front()), isConst(original.front()), isDebug));
    }
}