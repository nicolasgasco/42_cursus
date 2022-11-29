#pragma once

#include <vector>
#include <limits.h>

#include "utils.hpp"
#include "../../vector/Vector.hpp"

void getAllocatorUnitTests(bool isDebug)
{
    outputSuiteTitle("GET_ALLOCATOR");
    std::cout << "Allocator type strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("when initialized with empty constructor:", isStrictEqual<std::allocator<int> >(own.get_allocator(), original.get_allocator()));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(alloc);
        std::vector<int> original(alloc);
        outputAssertion("when initialized with empty constructor (custom allocator):", isStrictEqual<std::allocator<int> >(own.get_allocator(), original.get_allocator()));
    }
    {
        ft::vector<int> own(10);
        std::vector<int> original(10);
        outputAssertion("when initialized with fill constructor:", isStrictEqual<std::allocator<int> >(own.get_allocator(), original.get_allocator()));
    }
    {
        ft::vector<int> own(10, 5);
        std::vector<int> original(10, 5);
        outputAssertion("when initialized with fill constructor + value:", isStrictEqual<std::allocator<int> >(own.get_allocator(), original.get_allocator()));
    }
    std::cout << std::endl
              << "Element type is stictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own(0);
        std::vector<int> original(0);
        outputAssertion("when initialized with fill constructor:", isStrictEqual<std::string>(typeid(own[0]).name(), typeid(original[0]).name(), isDebug));
    }
    {
        ft::vector<int> own(10);
        std::vector<int> original(10);
        outputAssertion("when initialized with fill constructor:", isStrictEqual<std::string>(typeid(own[0]).name(), typeid(original[0]).name(), isDebug));
    }
    {
        ft::vector<int> own(10, 5);
        std::vector<int> original(10, 5);
        outputAssertion("when initialized with fill constructor + value:", isStrictEqual<std::string>(typeid(own[0]).name(), typeid(original[0]).name(), isDebug));
    }
    std::cout << std::endl
              << "Element value is stictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own(10);
        std::vector<int> original(10);
        outputAssertion("when initialized with fill constructor (num: 10, index: start):", isStrictEqual<int>(own[0], original[0], isDebug));
        outputAssertion("when initialized with fill constructor (num: 10, index: end):", isStrictEqual<int>(own[9], original[9], isDebug));
    }
    // With 0 elemnts, it is SEGFAULT for both my implementation and the original one
    std::cout << std::endl;
    {
        ft::vector<int> own(10, 5);
        std::vector<int> original(10, 5);
        outputAssertion("when initialized with fill constructor + value (value: 5, index: start):", isStrictEqual<int>(own[0], original[0], isDebug));
        outputAssertion("when initialized with fill constructor + value (value: 5, index: end):", isStrictEqual<int>(own[9], original[9], isDebug));
    }
    {
        ft::vector<int> own(10, 0);
        std::vector<int> original(10, 0);
        outputAssertion("when initialized with fill constructor + value (value: 0, index: start):", isStrictEqual<int>(own[0], original[0], isDebug));
        outputAssertion("when initialized with fill constructor + value (value: 0, index: end):", isStrictEqual<int>(own[9], original[9], isDebug));
    }
    {
        ft::vector<int> own(10, INT_MAX + 1);
        std::vector<int> original(10, INT_MAX + 1);
        outputAssertion("when initialized with fill constructor + value (value: INT_MAX + 1, index: start):", isStrictEqual<int>(own[0], original[0], isDebug));
        outputAssertion("when initialized with fill constructor + value (value: INT_MAX + 1, index: end):", isStrictEqual<int>(own[9], original[9], isDebug));
    }
}
