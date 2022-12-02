#include <vector>

#include "../utils.hpp"
#include "../vector.hpp"

#include "../algorithms.hpp"

void ftSwapUnitTests(bool isDebug)
{
    outputSuiteTitle("FT::SWAP");

    std::cout
        << "Acts exactly as std::swap:" << std::endl;
    {
        int oneOwn = 1;
        int twoOwn = 2;
        ft::swap(oneOwn, twoOwn);
        int resultsOwn[2] = {oneOwn, twoOwn};

        int oneOriginal = 1;
        int twoOriginal = 2;
        std::swap(oneOriginal, twoOriginal);
        int resultsOriginal[2] = {oneOriginal, twoOriginal};
        outputAssertion("with primitive data types (int):", isStrictEqual<int>(resultsOwn, resultsOriginal, 2, isDebug));
    }
    {
        char oneOwn = 'a';
        char twoOwn = 'b';
        ft::swap(oneOwn, twoOwn);
        char resultsOwn[2] = {oneOwn, twoOwn};

        char oneOriginal = 'a';
        char twoOriginal = 'b';
        std::swap(oneOriginal, twoOriginal);
        char resultsOriginal[2] = {oneOriginal, twoOriginal};
        outputAssertion("with primitive data types (char):", isStrictEqual<char>(resultsOwn, resultsOriginal, 2, isDebug));
    }
    {
        std::string oneOwn = "str1";
        std::string twoOwn = "str2";
        ft::swap(oneOwn, twoOwn);
        std::string resultsOwn[2] = {oneOwn, twoOwn};

        std::string oneOriginal = "str1";
        std::string twoOriginal = "str2";
        std::swap(oneOriginal, twoOriginal);
        std::string resultsOriginal[2] = {oneOriginal, twoOriginal};
        outputAssertion("with classes (std::string):", isStrictEqual<std::string>(resultsOwn, resultsOriginal, 2, isDebug));
    }
    {
        std::vector<int> oneOwn(2, 1);
        std::vector<int> twoOwn(2, 2);
        ft::swap(oneOwn, twoOwn);

        std::vector<int> oneOriginal(2, 1);
        std::vector<int> twoOriginal(2, 2);
        std::swap(oneOriginal, twoOriginal);

        outputAssertion("with std::vector:", isStrictEqual<int>(oneOwn.data(), oneOriginal.data(), 2, isDebug));
    }
    {
        ft::vector<int> oneOwn(2, 1);
        ft::vector<int> twoOwn(2, 2);
        ft::swap(oneOwn, twoOwn);

        ft::vector<int> oneOriginal(2, 1);
        ft::vector<int> twoOriginal(2, 2);
        std::swap(oneOriginal, twoOriginal);

        outputAssertion("with ft::vector:", isStrictEqual<int>(oneOwn.data(), oneOriginal.data(), 2, isDebug));
    }
}