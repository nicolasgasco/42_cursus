#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

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
    {
        ft::vector<int> ownSeed(10, 5);
        ft::vector<int> own(ownSeed);

        std::vector<int> originalSeed(10, 5);
        std::vector<int> original(originalSeed);
        outputAssertion("with copy constructor:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
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

    std::cout << std::endl
              << "Stays constant after a pop_back like STL vector value:" << std::endl;
    {
        ft::vector<int> own(1, 10);
        own.pop_back();
        std::vector<int> original(1, 10);
        original.pop_back();
        outputAssertion("with capacity = 1:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(2, 10);
        own.pop_back();
        std::vector<int> original(2, 10);
        original.pop_back();
        outputAssertion("with capacity = 2:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(3, 10);
        own.pop_back();
        std::vector<int> original(3, 10);
        original.pop_back();
        outputAssertion("with capacity = 3:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(4, 10);
        own.pop_back();
        std::vector<int> original(4, 10);
        original.pop_back();
        outputAssertion("with capacity = 4:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(4, 10);
        own.pop_back();
        std::vector<int> original(4, 10);
        original.pop_back();
        outputAssertion("with capacity = 4:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }

    std::cout << std::endl
              << "Stays constant after resize like STL vector value:" << std::endl;
    {
        ft::vector<int> own(10, 5);
        own.resize(5);
        std::vector<int> original(10, 5);
        original.resize(5);
        outputAssertion("with capacity = 10 and resize = 5:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(1, 5);
        own.resize(0);
        std::vector<int> original(1, 5);
        original.resize(0);
        outputAssertion("with capacity = 1 and resize = 0:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(1, 5);
        own.resize(1);
        std::vector<int> original(1, 5);
        original.resize(1);
        outputAssertion("with capacity = 1 and resize = 1:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }

    std::cout << std::endl
              << "Increases after resize like STL vector value:" << std::endl;
    {
        ft::vector<int> own(1, 5);
        own.resize(10);
        std::vector<int> original(1, 5);
        original.resize(10);
        outputAssertion("with capacity = 1 and resize = 10:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(1, 5);
        own.resize(2);
        std::vector<int> original(1, 5);
        original.resize(2);
        outputAssertion("with capacity = 1 and resize = 2:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own;
        own.resize(1);
        std::vector<int> original;
        original.resize(1);
        outputAssertion("with capacity = 0 and resize = 1:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own;
        own.resize(100);
        std::vector<int> original;
        original.resize(100);
        outputAssertion("with capacity = 0 and resize = 100:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own;
        own.resize(63);
        std::vector<int> original;
        original.resize(63);
        outputAssertion("with capacity = 0 and resize = 63:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        own.resize(9);
        std::vector<int> original(5, 10);
        original.resize(9);
        outputAssertion("with capacity = 5 and resize = 9:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        own.resize(6);
        std::vector<int> original(5, 10);
        original.resize(6);
        outputAssertion("with capacity = 5 and resize = 9:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        own.resize(11);
        std::vector<int> original(5, 10);
        original.resize(11);
        outputAssertion("with capacity = 5 and resize = 11:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        ft::vector<int> own(50, 10);
        own.resize(77);
        std::vector<int> original(50, 10);
        original.resize(77);
        outputAssertion("with capacity = 50 and resize = 77:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
}
