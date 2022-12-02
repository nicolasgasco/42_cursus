#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

void sizeUnitTests(bool isDebug)
{
    outputSuiteTitle("SIZE");
    std::cout << "Is initialized equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(alloc);
        std::vector<int> original(alloc);
        outputAssertion("with empty constructor (custom allocator):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(9);
        std::vector<int> original(9);
        outputAssertion("with fill constructor:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(9, 5);
        std::vector<int> original(9, 5);
        outputAssertion("with fill constructor + value:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(9, 5, alloc);
        std::vector<int> original(9, 5, alloc);
        outputAssertion("with fill constructor + value + custom allocator:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> ownSeed(10, 5);
        ft::vector<int> own(ownSeed);

        std::vector<int> originalSeed(10, 5);
        std::vector<int> original(originalSeed);
        outputAssertion("with copy constructor:", isStrictEqual<bool>(own.size(), original.size(), isDebug));
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
        outputAssertion("after a push_back inside reserved memory:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(1);
        std::vector<int> original;
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(1, 5);
        own.push_back(1);
        std::vector<int> original(1, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(2, 5);
        own.push_back(1);
        std::vector<int> original(2, 5);
        original.push_back(1);
        outputAssertion("after a push_back without memory preservation and capacity = 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }

    std::cout << std::endl
              << "Is decremented after a pop_back like STL vector value:" << std::endl;
    {
        ft::vector<int> own(1, 10);
        own.pop_back();
        std::vector<int> original(1, 10);
        original.pop_back();
        outputAssertion("with size = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(2, 10);
        own.pop_back();
        std::vector<int> original(2, 10);
        original.pop_back();
        outputAssertion("with size = 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(3, 10);
        own.pop_back();
        std::vector<int> original(3, 10);
        original.pop_back();
        outputAssertion("with size = 3:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(4, 10);
        own.pop_back();
        std::vector<int> original(4, 10);
        original.pop_back();
        outputAssertion("with size = 4:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }

    std::cout << std::endl
              << "Is decremented after a resize like STL vector value:" << std::endl;
    {
        ft::vector<int> own(10, 5);
        own.resize(1);
        std::vector<int> original(10, 5);
        original.resize(1);
        outputAssertion("with size = 10 and resize = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(10, 5);
        own.resize(9);
        std::vector<int> original(10, 5);
        original.resize(9);
        outputAssertion("with size = 10 and resize = 9:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(1, 5);
        own.resize(0);
        std::vector<int> original(1, 5);
        original.resize(0);
        outputAssertion("with size = 1 and resize = 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }

    std::cout << std::endl
              << "Stays constant after a resize like STL vector value:" << std::endl;
    {
        ft::vector<int> own(10, 5);
        own.resize(10);
        std::vector<int> original(10, 5);
        original.resize(10);
        outputAssertion("with size = 10 and resize = 10:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own;
        own.resize(0);
        std::vector<int> original;
        original.resize(0);
        outputAssertion("with size = 0 and resize = 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        ft::vector<int> own(1, 5);
        own.resize(1);
        std::vector<int> original(1, 5);
        original.resize(1);
        outputAssertion("with size = 1 and resize = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }

    std::cout << std::endl
              << "Is swapped after a ft::swap like STL vector value:" << std::endl;
    {
        ft::vector<int> oneOwn;
        ft::vector<int> twoOwn(5, 2);
        oneOwn.swap(twoOwn);

        std::vector<int> oneOriginal;
        std::vector<int> twoOriginal(5, 2);
        oneOriginal.swap(twoOriginal);
        outputAssertion("with two vectors of different size (0, 5):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
    }
    {
        ft::vector<int> oneOwn(5, 2);
        ft::vector<int> twoOwn;
        oneOwn.swap(twoOwn);

        std::vector<int> oneOriginal(5, 2);
        std::vector<int> twoOriginal;
        oneOriginal.swap(twoOriginal);
        outputAssertion("with two vectors of different size (5, 0):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
    }
    {
        ft::vector<int> oneOwn(1, 2);
        ft::vector<int> twoOwn(100, 2);
        oneOwn.swap(twoOwn);

        std::vector<int> oneOriginal(1, 2);
        std::vector<int> twoOriginal(100, 2);
        oneOriginal.swap(twoOriginal);
        outputAssertion("with two vectors of different size (1, 100):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
    }
    {
        ft::vector<int> oneOwn(1, 2);
        ft::vector<int> twoOwn(1, 2);
        oneOwn.swap(twoOwn);

        std::vector<int> oneOriginal(1, 2);
        std::vector<int> twoOriginal(1, 2);
        oneOriginal.swap(twoOriginal);
        outputAssertion("with two vectors of different size (100, 1):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
    }
}
