#include <vector>

#include "utils.hpp"
#include "../../vector.hpp"

void dataUnitTests(bool isDebug)
{
    outputSuiteTitle("DATA");
    std::cout << "Is initialized equal to STL vector value:" << std::endl;
    std::cout << "  NOT CONST" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<int>(own.data(), original.data(), 0, isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(alloc);
        std::vector<int> original(alloc);
        outputAssertion("with empty constructor (custom allocator):", isStrictEqual<int>(own.data(), original.data(), 0, isDebug));
    }
    {
        ft::vector<int> own(3);
        std::vector<int> original(3);
        outputAssertion("with fill constructor:", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
    {
        ft::vector<int> own(3, 5);
        std::vector<int> original(3, 5);
        outputAssertion("with fill constructor + value (5):", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(3, 5, alloc);
        std::vector<int> original(3, 5, alloc);
        outputAssertion("with fill constructor + value (5) + custom allocator:", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
    std::cout << std::endl
              << "  CONST" << std::endl;
    {
        ft::vector<int> const own;
        std::vector<int> const original;
        outputAssertion("with empty constructor:", isStrictEqual<int>(own.data(), original.data(), 0, isDebug));
    }
    {
        std::allocator<int> const alloc = std::allocator<int>();
        ft::vector<int> const own(alloc);
        std::vector<int> const original(alloc);
        outputAssertion("with empty constructor (custom allocator):", isStrictEqual<int>(own.data(), original.data(), 0, isDebug));
    }
    {
        ft::vector<int> const own(3);
        std::vector<int> const original(3);
        outputAssertion("with fill constructor:", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
    {
        ft::vector<int> const own(3, 5);
        std::vector<int> const original(3, 5);
        outputAssertion("with fill constructor + value (5):", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }
    {
        std::allocator<int> const alloc = std::allocator<int>();
        ft::vector<int> const own(3, 5, alloc);
        std::vector<int> const original(3, 5, alloc);
        outputAssertion("with fill constructor + value (5) + custom allocator:", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
    }

    std::cout << std::endl
              << "Const check compared to STL vector value:" << std::endl;
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("is const with fill costructor (num: 5, value:10):", isStrictEqual<bool>(isConst(*(own.data())), isConst(*(original.data())), isDebug));
    }
    {
        ft::vector<int> const own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("is const with fill costructor (num: 5, value:10):", isStrictEqual<bool>(isConst(*(own.data())), isConst(*(original.data())), isDebug));
    }

    std::cout << std::endl
              << "Is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own(5, 10);
        own.reserve(100);
        std::vector<int> original(5, 10);
        original.reserve(100);
        outputAssertion("after reserve() with reallocation:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(100);
        std::vector<int> original;
        original.push_back(100);
        outputAssertion("after push_back() with reallocation:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(100);
        std::vector<int> original;
        original.push_back(100);
        outputAssertion("after push_back() with size = 0:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
    }
    {
        ft::vector<int> own(1, 10);
        own.push_back(100);
        std::vector<int> original(1, 10);
        original.push_back(100);
        outputAssertion("after push_back() with size = 1:", isStrictEqual<int>(own.data(), original.data(), 2, isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        own.push_back(100);
        std::vector<int> original(5, 10);
        original.push_back(100);
        outputAssertion("after push_back() with size = 5:", isStrictEqual<int>(own.data(), original.data(), 6, isDebug));
    }
    {
        ft::vector<int> own;
        std::vector<int> original;
        srand(time(0));
        for (int i = 0; i < 50; ++i)
        {
            int randInt = rand();
            own.push_back(randInt);
            original.push_back(randInt);
        }
        outputAssertion("after 50 random push_back() calls:", isStrictEqual<int>(own.data(), original.data(), 50, isDebug));
    }
}