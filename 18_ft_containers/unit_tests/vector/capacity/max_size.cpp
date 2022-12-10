#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void maxSizeUnitTests(bool isDebug)
{
    outputSuiteTitle("MAX SIZE");
    {
        std::cout << "Is initialized equal to STL vector value:" << std::endl;
        {
            ft::vector<int> own;
            std::vector<int> original;
            outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            std::allocator<int> alloc = std::allocator<int>();
            ft::vector<int> own(alloc);
            std::vector<int> original(alloc);
            outputAssertion("with empty constructor (custom allocator):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            ft::vector<int> own(9);
            std::vector<int> original(9);
            outputAssertion("with fill constructor:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            ft::vector<int> own(9, 5);
            std::vector<int> original(9, 5);
            outputAssertion("with fill constructor + value:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            std::allocator<int> alloc = std::allocator<int>();
            ft::vector<int> own(9, 5, alloc);
            std::vector<int> original(9, 5, alloc);
            outputAssertion("with fill constructor + value + allocator:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            ft::vector<int> ownRef(10, 5);
            ft::vector<int> own(ownRef.begin(), ownRef.end());

            std::vector<int> originalRef(10, 5);
            std::vector<int> original(originalRef.begin(), originalRef.end());
            outputAssertion("with range constructor + fill constructor (10, 5):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            ft::vector<int> ownRef;
            ft::vector<int> own(ownRef.begin(), ownRef.end());

            std::vector<int> originalRef;
            std::vector<int> original(originalRef.begin(), originalRef.end());
            outputAssertion("with range constructor + default constructor:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            std::allocator<int> alloc = std::allocator<int>();

            ft::vector<int> ownRef(10, 5, alloc);
            ft::vector<int> own(ownRef.begin(), ownRef.end());

            std::vector<int> originalRef(10, 5, alloc);
            std::vector<int> original(originalRef.begin(), originalRef.end());
            outputAssertion("with range constructor + fill constructor (10, 5) + custom allocator:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
        {
            ft::vector<int> ownSeed(10, 5);
            ft::vector<int> own(ownSeed);

            std::vector<int> originalSeed(10, 5);
            std::vector<int> original(originalSeed);
            outputAssertion("with copy constructor:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
    }

    {
        std::cout << std::endl
                  << "Is swapped after a ft::swap like STL vector value:" << std::endl;
        {
            ft::vector<int> oneOwn;
            ft::vector<int> twoOwn(5, 2);
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal;
            std::vector<int> twoOriginal(5, 2);
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (0, 5):", isStrictEqual<std::size_t>(oneOwn.max_size(), oneOriginal.max_size(), isDebug));
        }
        {
            ft::vector<int> oneOwn(5, 2);
            ft::vector<int> twoOwn;
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal(5, 2);
            std::vector<int> twoOriginal;
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (5, 0):", isStrictEqual<std::size_t>(oneOwn.max_size(), oneOriginal.max_size(), isDebug));
        }
        {
            ft::vector<int> oneOwn(1, 2);
            ft::vector<int> twoOwn(100, 2);
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal(1, 2);
            std::vector<int> twoOriginal(100, 2);
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (1, 100):", isStrictEqual<std::size_t>(oneOwn.max_size(), oneOriginal.max_size(), isDebug));
        }
        {
            ft::vector<int> oneOwn(1, 2);
            ft::vector<int> twoOwn(1, 2);
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal(1, 2);
            std::vector<int> twoOriginal(1, 2);
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (100, 1):", isStrictEqual<std::size_t>(oneOwn.max_size(), oneOriginal.max_size(), isDebug));
        }
    }
}
