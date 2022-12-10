#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void swapUnitTests(bool isDebug)
{
    outputSuiteTitle("SWAP");
    std::cout << "Acts exactly as STL vector:" << std::endl;
    {
        ft::vector<int> oneOwn(2, 1);
        ft::vector<int> twoOwn(2, 2);
        oneOwn.swap(twoOwn);

        std::vector<int> oneOriginal(2, 1);
        std::vector<int> twoOriginal(2, 2);
        oneOriginal.swap(twoOriginal);
        outputAssertion("with two vectors of size 2:", isStrictEqual<int>(oneOwn.data(), oneOriginal.data(), 2, isDebug));
    }
    {
        ft::vector<int> oneOwn(2, 1);
        ft::vector<int> twoOwn(5, 2);
        oneOwn.swap(twoOwn);

        std::vector<int> oneOriginal(2, 1);
        std::vector<int> twoOriginal(5, 2);
        oneOriginal.swap(twoOriginal);
        outputAssertion("with two vectors of different size (2, 5):", isStrictEqual<int>(oneOwn.data(), oneOriginal.data(), 5, isDebug));
    }
    {
        ft::vector<int> oneOwn;
        ft::vector<int> twoOwn(5, 2);
        oneOwn.swap(twoOwn);

        std::vector<int> oneOriginal;
        std::vector<int> twoOriginal(5, 2);
        oneOriginal.swap(twoOriginal);
        outputAssertion("with two vectors of different size (0, 5):", isStrictEqual<int>(oneOwn.data(), oneOriginal.data(), 5, isDebug));
    }
}