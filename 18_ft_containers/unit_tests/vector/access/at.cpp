#include <vector>

#include "utils.hpp"
#include "../../vector/vector.hpp"

void atUnitTests(bool isDebug)
{
    outputSuiteTitle("AT");
    std::cout << "Exception is equal to STL vector value:" << std::endl;
    std::cout << "  NOT CONST" << std::endl;
    // Undefined behaviour with empty constructor
    {
        std::string ownWhat;
        ft::vector<int> own(1, 10);
        try
        {
            own.at(-1);
        }
        catch (const std::out_of_range &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original(1, 10);
        try
        {
            original.at(-1);
        }
        catch (std::out_of_range &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with fill costructor (num: 1, value: 10) at index [start - 1]:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }
    {
        std::string ownWhat;
        ft::vector<int> own(1, 10);
        try
        {
            own.at(1);
        }
        catch (const std::out_of_range &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> original(1, 10);
        try
        {
            original.at(1);
        }
        catch (std::out_of_range &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with fill costructor (num: 1, value: 10) at index [end + 1]:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }
    std::cout << "  NOT CONST" << std::endl;
    // Undefined behaviour with empty constructor
    {
        std::string ownWhat;
        ft::vector<int> const own(1, 10);
        try
        {
            own.at(-1);
        }
        catch (const std::out_of_range &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> const original(1, 10);
        try
        {
            original.at(-1);
        }
        catch (std::out_of_range &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with fill costructor (num: 1, value: 10) at index [start - 1]:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }
    {
        std::string ownWhat;
        ft::vector<int> const own(1, 10);
        try
        {
            own.at(1);
        }
        catch (const std::out_of_range &e)
        {
            ownWhat = e.what();
        }
        std::string originalWhat;
        std::vector<int> const original(1, 10);
        try
        {
            original.at(1);
        }
        catch (std::out_of_range &e)
        {
            originalWhat = e.what();
        }
        outputAssertion("with fill costructor (num: 1, value: 10) at index [end + 1]:", isStrictEqual<std::string>(ownWhat, originalWhat, isDebug));
    }

    std::cout << std::endl
              << "Const check compared to STL vector value:" << std::endl;
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("is not const with fill costructor (num: 5, value: 10) at [start]:", isStrictEqual<bool>(isConst(own.at(0)), isConst(original.at(0)), isDebug));
    }
    {
        ft::vector<int> const own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("is const with fill costructor (num: 5, value: 10) at [start]:", isStrictEqual<bool>(isConst(own.at(0)), isConst(original.at(0)), isDebug));
    }

    std::cout << std::endl
              << "Value is equal to STL vector value:" << std::endl;
    std::cout << "  NOT CONST" << std::endl;
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("with fill costructor (num: 5, value: 10) at [start]:", isStrictEqual<int &>(own.at(0), original.at(0), isDebug));
        outputAssertion("with fill costructor (num: 5, value: 10) at [end]:", isStrictEqual<int &>(own.at(4), original.at(4), isDebug));
    }
    std::cout << "  CONST" << std::endl;
    {
        ft::vector<int> const own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("with fill costructor (num: 5, value: 10) at [start]:", isStrictEqual<int const &>(own.at(0), original.at(0), isDebug));
        outputAssertion("with fill costructor (num: 5, value: 10) at [end]:", isStrictEqual<int const &>(own.at(4), original.at(4), isDebug));
    }
}