#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void capacityUnitTests(bool isDebug)
{
    outputSuiteTitle("CAPACITY");
    std::cout << "Is initialized equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(alloc);
        std::vector<int> original(alloc);
        outputAssertion("with empty constructor (custom allocator):", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(9);
        std::vector<int> original(9);
        outputAssertion("with fill constructor:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(9, 5);
        std::vector<int> original(9, 5);
        outputAssertion("with fill constructor + value:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(9, 5, alloc);
        std::vector<int> original(9, 5, alloc);
        outputAssertion("with fill constructor + value + custom allocator:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }

    std::cout << std::endl
              << "Is incremented like STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        own.reserve(1);
        own.push_back(1);
        std::vector<int> original;
        original.reserve(1);
        original.push_back(1);
        outputAssertion("after a push_back inside reserved memory:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(1);
        std::vector<int> original;
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 0:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(1, 5);
        own.push_back(1);
        std::vector<int> original(1, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 1:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(2, 5);
        own.push_back(1);
        std::vector<int> original(2, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 2:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(3, 5);
        own.push_back(1);
        std::vector<int> original(3, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 3:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(4, 5);
        own.push_back(1);
        std::vector<int> original(4, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 4:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(5, 5);
        own.push_back(1);
        std::vector<int> original(5, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 5:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(6, 5);
        own.push_back(1);
        std::vector<int> original(6, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 6:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(7, 5);
        own.push_back(1);
        std::vector<int> original(7, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 7:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(8, 5);
        own.push_back(1);
        std::vector<int> original(8, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 8:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(9, 5);
        own.push_back(1);
        std::vector<int> original(9, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 9:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(10, 5);
        own.push_back(1);
        std::vector<int> original(10, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 10:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(20, 5);
        own.push_back(1);
        std::vector<int> original(20, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 20:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(50, 5);
        own.push_back(1);
        std::vector<int> original(50, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 50:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(76, 5);
        own.push_back(1);
        std::vector<int> original(76, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 76:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(100, 5);
        own.push_back(1);
        std::vector<int> original(100, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 100:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(1000, 5);
        own.push_back(1);
        std::vector<int> original(1000, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 1000:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(1992, 5);
        own.push_back(1);
        std::vector<int> original(1992, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 1992:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(2023, 5);
        own.push_back(1);
        std::vector<int> original(2023, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 2023:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
}
