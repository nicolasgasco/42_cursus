#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void resizeUnitTests(bool isDebug)
{
    outputSuiteTitle("RESIZE");
    std::cout << "Throws same exceptions as STL vector:" << std::endl;
    {
        std::string ownWhat;
        ft::vector<int> own;
        try
        {
            own.resize(own.max_size() + 1);
        }
        catch (const std::length_error &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original;
        try
        {
            original.resize(own.max_size() + 1);
        }
        catch (std::length_error &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with resize(max_size() + 1):", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }
    {
        std::string ownWhat;
        ft::vector<int> own;
        try
        {
            own.resize(0);
        }
        catch (const std::length_error &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original;
        try
        {
            original.resize(0);
        }
        catch (std::length_error &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with resize(0) + size = 0:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }
    {
        std::string ownWhat;
        ft::vector<int> own(1, 10);
        try
        {
            own.resize(0);
        }
        catch (const std::length_error &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original(1, 10);
        try
        {
            original.resize(0);
        }
        catch (std::length_error &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with resize(0) + size = 1:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }
    {
        std::string ownWhat;
        ft::vector<int> own;
        try
        {
            own.resize(-1);
        }
        catch (const std::length_error &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original;
        try
        {
            original.resize(-1);
        }
        catch (std::length_error &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with resize(-1):", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }

    std::cout << std::endl
              << "Has the same values as STL vector:" << std::endl;
    {
        ft::vector<int> own(10, 5);
        own.resize(9);
        std::vector<int> original(10, 5);
        original.resize(9);
        outputAssertion("with resize = 9 and size = 10:", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
    }
    {
        ft::vector<int> own(10, 5);
        own.resize(1);
        std::vector<int> original(10, 5);
        original.resize(1);
        outputAssertion("with resize = 1 and size = 10:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        own.reserve(10);
        own.resize(9);
        std::vector<int> original(5, 10);
        original.reserve(10);
        original.resize(9);
        outputAssertion("with capacity = 10, size = 5 and resize = 9:", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
    }
    {
        ft::vector<int> own;
        own.reserve(10);
        own.resize(5);
        std::vector<int> original;
        original.reserve(10);
        original.resize(5);
        outputAssertion("with capacity = 10, size = 0 and resize = 5:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        own.resize(9);
        std::vector<int> original(5, 10);
        original.resize(9);
        outputAssertion("with capacity = 5, size = 5 and resize = 9:", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
    }
    {
        ft::vector<int> own;
        own.resize(1);
        std::vector<int> original;
        original.resize(1);
        outputAssertion("with capacity = 0, size = 0 and resize = 1:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
    }
    {
        ft::vector<int> own;
        own.resize(9);
        std::vector<int> original;
        original.resize(9);
        outputAssertion("with capacity = 0, size = 0 and resize = 9:", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
    }
}