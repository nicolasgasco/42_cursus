#include <vector>

#include "../utils.hpp"
#include "../vector.hpp"

#include "../algorithms.hpp"

bool intPred(int &a, int &b)
{
    return (a == b);
}

bool charArrayPred(const char *s1, const char *s2)
{

    for (int i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

void ftEqualUnitTests(bool isDebug)
{
    outputSuiteTitle("FT::EQUAL");
    {
        std::cout
            << "Acts exactly as std::swap:" << std::endl;
        std::cout << "  WITHOUT PREDICATE" << std::endl;

        {
            ft::vector<int> oneOwn(5, 2);
            ft::vector<int> twoOwn(5, 2);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<int> oneOriginal(5, 2);
            std::vector<int> twoOriginal(5, 2);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns true with two equal vector<int>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<int> oneOwn(5, 2);
            ft::vector<int> twoOwn(6, 1);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<int> oneOriginal(5, 2);
            std::vector<int> twoOriginal(6, 1);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns false with two different vector<int>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<std::string> oneOwn(5, "ciao");
            ft::vector<std::string> twoOwn(5, "ciao");
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<std::string> oneOriginal(5, "ciao");
            std::vector<std::string> twoOriginal(5, "ciao");
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns true with two equal vector<std::string>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<std::string> oneOwn(5, "ciao");
            ft::vector<std::string> twoOwn(5, "ciap");
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<std::string> oneOriginal(5, "ciao");
            std::vector<std::string> twoOriginal(5, "ciap");
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns false with two different vector<std::string>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<float> oneOwn(5, 1.0f);
            ft::vector<float> twoOwn(5, 1.0f);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<float> oneOriginal(5, 1.0f);
            std::vector<float> twoOriginal(5, 1.0f);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns true with two equal vector<float>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<float> oneOwn(5, 1.0f);
            ft::vector<float> twoOwn(1, 2.0f);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<float> oneOriginal(5, 1.0f);
            std::vector<float> twoOriginal(1, 2.0f);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns false with two different vector<float>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<bool> oneOwn(5, true);
            ft::vector<bool> twoOwn(5, true);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<bool> oneOriginal(5, true);
            std::vector<bool> twoOriginal(5, true);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns true with two equal vector<bool>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<bool> oneOwn(5, true);
            ft::vector<bool> twoOwn(5, false);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<bool> oneOriginal(5, true);
            std::vector<bool> twoOriginal(5, false);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns false with two different vector<bool>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<long> oneOwn(5, 2147483647);
            ft::vector<long> twoOwn(5, 2147483647);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<long> oneOriginal(5, 2147483647);
            std::vector<long> twoOriginal(5, 2147483647);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns true with two equal vector<long>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<long> oneOwn(5, 2147483647);
            ft::vector<long> twoOwn(100, 0);
            bool ownEqual = ft::equal(oneOwn.begin(), oneOwn.end(), twoOwn.begin());

            std::vector<long> oneOriginal(5, 2147483647);
            std::vector<long> twoOriginal(100, 0);
            bool originalEqual = std::equal(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin());

            outputAssertion("returns false with two different vector<long>:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {1, 2, 3};
            bool ownEqual = ft::equal(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn));

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {1, 2, 3};
            bool originalEqual = std::equal(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal));

            outputAssertion("returns true with two equal arrays (int[]):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {4, 5, 6};
            bool ownEqual = ft::equal(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn));

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {4, 5, 6};
            bool originalEqual = std::equal(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal));

            outputAssertion("returns false with two different arrays (int[]):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            char oneOwn[5] = "ciao";
            char twoOwn[5] = "ciao";
            bool ownEqual = ft::equal(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn));

            char oneOriginal[5] = "ciao";
            char twoOriginal[5] = "ciao";
            bool originalEqual = std::equal(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal));

            outputAssertion("returns true with two equal arrays (char *):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            char oneOwn[5] = "ciao";
            char twoOwn[5] = "ciap";
            bool ownEqual = ft::equal(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn));

            char oneOriginal[5] = "ciao";
            char twoOriginal[5] = "ciap";
            bool originalEqual = std::equal(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal));

            outputAssertion("returns false with two different arrays (char *):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        std::cout << std::endl
                  << "  WITH PREDICATE" << std::endl;
        {

            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {1, 2, 3};
            bool ownEqual = ft::equal(oneOwn, oneOwn + 3, twoOwn, intPred);

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {1, 2, 3};
            bool originalEqual = std::equal(oneOriginal, oneOriginal + 3, twoOriginal, intPred);

            outputAssertion("returns true with two equal int[]:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {3, 4, 5};
            bool ownEqual = ft::equal(oneOwn, oneOwn + 3, twoOwn, intPred);

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {3, 4, 5};
            bool originalEqual = std::equal(oneOriginal, oneOriginal + 3, twoOriginal, intPred);

            outputAssertion("returns true with two equal int[]:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            char oneOwn[2][5] = {"ciao", "miao"};
            char twoOwn[2][5] = {"ciao", "miao"};
            bool ownEqual = ft::equal(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), charArrayPred);

            char oneOriginal[2][5] = {"ciao", "miao"};
            char twoOriginal[2][5] = {"ciao", "miao"};
            bool originalEqual = std::equal(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), charArrayPred);

            outputAssertion("returns true with two equal char[][]:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            char oneOwn[2][5] = {"ciao", "miao"};
            char twoOwn[2][5] = {"ciao", "miap"};
            bool ownEqual = ft::equal(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), charArrayPred);

            char oneOriginal[2][5] = {"ciao", "miao"};
            char twoOriginal[2][5] = {"ciao", "miap"};
            bool originalEqual = std::equal(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), charArrayPred);

            outputAssertion("returns true with two equal char[][]:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
    }
}