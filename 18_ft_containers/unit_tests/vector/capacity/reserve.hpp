#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void reserveUnitTests(bool isDebug)
{
    outputSuiteTitle("RESERVE");
    std::cout << "Exception is equal to STL vector value:" << std::endl;
    {
        std::string ownWhat;
        ft::vector<int> own;
        try
        {
            own.reserve(own.max_size() + 1);
        }
        catch (const std::length_error &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original;
        try
        {
            original.reserve(own.max_size() + 1);
        }
        catch (std::length_error &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with default constructor and max_size() + 1:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }
    {
        std::string ownWhat;
        ft::vector<int> own;
        try
        {
            own.reserve(-1);
        }
        catch (const std::length_error &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original;
        try
        {
            original.reserve(-1);
        }
        catch (std::length_error &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with default constructor and negative new_cap:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }

    std::cout << std::endl
              << "Capacity is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own(1, 5);
        own.reserve(1);
        std::vector<int> original(1, 5);
        original.reserve(1);
        outputAssertion("with new_cap equal to capacity():", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(10, 5);
        own.reserve(5);
        std::vector<int> original(10, 5);
        original.reserve(5);
        outputAssertion("with new_cap less than capacity():", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own;
        own.reserve(5);
        std::vector<int> original;
        original.reserve(5);
        outputAssertion("with new_cap greater than capacity():", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    std::cout << std::endl
              << "Data is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own(3, 5);
        own.reserve(3);
        std::vector<int> original(3, 5);
        original.reserve(3);
        outputAssertion("with new_cap equal to capacity():", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
    {
        ft::vector<int> own(3, 5);
        own.reserve(1);
        std::vector<int> original(3, 5);
        original.reserve(1);
        outputAssertion("with new_cap equal less than capacity():", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
    {
        ft::vector<int> own(3, 5);
        own.reserve(1);
        std::vector<int> original(3, 5);
        original.reserve(1);
        outputAssertion("with new_cap equal greater than capacity():", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
}
