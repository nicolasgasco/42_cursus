#include "utils.hpp"
#include <vector>
#include "../../vector/vector.hpp"

void emptyUnitTests(bool isDebug)
{
    outputSuiteTitle("EMPTY");
    std::cout << "Is initialized equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("with empty constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(alloc);
        std::vector<int> original(alloc);
        outputAssertion("with empty constructor (custom allocator):", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(9);
        std::vector<int> original(9);
        outputAssertion("with fill constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(9, 5);
        std::vector<int> original(9, 5);
        outputAssertion("with fill constructor + value:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        std::allocator<int> alloc = std::allocator<int>();
        ft::vector<int> own(9, 5, alloc);
        std::vector<int> original(9, 5, alloc);
        outputAssertion("with fill constructor + value + custom allocator:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> ownSeed(10, 5);
        ft::vector<int> own(ownSeed);

        std::vector<int> originalSeed(10, 5);
        std::vector<int> original(originalSeed);
        outputAssertion("with copy constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }

    std::cout << std::endl
              << "Is equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        own.push_back(10);
        std::vector<int> original;
        original.push_back(10);
        outputAssertion("after push_back with size = 0:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(1, 10);
        own.push_back(10);
        std::vector<int> original(1, 10);
        original.push_back(10);
        outputAssertion("after push_back with size = 2:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(1, 10);
        own.pop_back();
        std::vector<int> original(1, 10);
        original.pop_back();
        outputAssertion("after pop_back with size = 1:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
    {
        ft::vector<int> own(2, 10);
        own.pop_back();
        std::vector<int> original(2, 10);
        original.pop_back();
        outputAssertion("after pop_back with size = 2:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
    }
}
