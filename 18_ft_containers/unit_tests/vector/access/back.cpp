#include <vector>

#include "utils.hpp"
#include "../vector.hpp"

void backUnitTests(bool isDebug)
{
    outputSuiteTitle("BACK");
    std::cout << "Value is equal to STL vector value:" << std::endl;
    std::cout << "  NOT CONST" << std::endl;
    // Undefined behaviour with empty constructor
    {
        ft::vector<int> own(1, 10);
        std::vector<int> original(1, 10);
        outputAssertion("with fill costructor (num: 1, value:10):", isStrictEqual<int &>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("with fill costructor (num: 5, value:10):", isStrictEqual<int &>(own.back(), original.back(), isDebug));
    }
    std::cout << "  CONST" << std::endl;
    // Undefined behaviour with empty constructor
    {
        ft::vector<int> const own(1, 10);
        std::vector<int> const original(1, 10);
        outputAssertion("with fill costructor (num: 1, value:10):", isStrictEqual<int const &>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("with fill costructor (num: 5, value:10):", isStrictEqual<int const &>(own.back(), original.back(), isDebug));
    }

    std::cout << std::endl
              << "Const check compared to STL vector value:" << std::endl;
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("is not const with fill costructor (num: 5, value:10):", isStrictEqual<bool>(isConst(own.back()), isConst(original.back()), isDebug));
    }
    {
        ft::vector<int> const own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("is const with fill costructor (num: 5, value:10):", isStrictEqual<bool>(isConst(own.back()), isConst(original.back()), isDebug));
    }

    std::cout << std::endl
              << "Value is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        own.reserve(1);
        own.push_back(5);
        std::vector<int> original;
        original.reserve(1);
        original.push_back(5);
        outputAssertion("after push_back without reallocation:", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(5);
        std::vector<int> original;
        original.push_back(5);
        outputAssertion("after push_back with allocation (size = 0):", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own(1, 10);
        own.push_back(5);
        std::vector<int> original(1, 10);
        original.push_back(5);
        outputAssertion("after push_back with allocation (size = 1):", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
    {
        ft::vector<int> own(10, 10);
        own.push_back(5);
        std::vector<int> original(10, 10);
        original.push_back(5);
        outputAssertion("after push_back with allocation (size = 10):", isStrictEqual<int>(own.back(), original.back(), isDebug));
    }
}