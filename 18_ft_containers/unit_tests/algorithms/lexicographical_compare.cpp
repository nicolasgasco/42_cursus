#include <vector>

#include "../utils.hpp"
#include "../vector.hpp"

#include "../algorithms.hpp"

bool intPredLex(int &a, int &b)
{
    return (a < b);
}

bool charArrayPredLex(const char *s1, const char *s2)
{

    for (int i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] != s2[i])
        {
            if (s1[i] < s2[i])
                return true;
            return false;
        }
    }
    return false;
}

void ftLexicoGraphicalCompareUnitTests(bool isDebug)
{
    outputSuiteTitle("FT::LEXICOGRAPHICAL_COMPARE");
    {
        std::cout
            << "Acts exactly as std::lexicographical_compare:" << std::endl;
        std::cout << "  WITHOUT PREDICATE" << std::endl;
        {
            ft::vector<int> oneOwn(5, 1);
            ft::vector<int> twoOwn(5, 2);
            bool ownEqual = ft::lexicographical_compare(oneOwn.begin(), oneOwn.end(), twoOwn.begin(), twoOwn.end());

            std::vector<int> oneOriginal(5, 1);
            std::vector<int> twoOriginal(5, 2);
            bool originalEqual = std::lexicographical_compare(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin(), twoOriginal.end());

            outputAssertion("returns true with two vector<int> (v1 < v2):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<int> oneOwn(5, 2);
            ft::vector<int> twoOwn(5, 1);
            bool ownEqual = ft::lexicographical_compare(oneOwn.begin(), oneOwn.end(), twoOwn.begin(), twoOwn.end());

            std::vector<int> oneOriginal(5, 2);
            std::vector<int> twoOriginal(5, 1);
            bool originalEqual = std::lexicographical_compare(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin(), twoOriginal.end());

            outputAssertion("returns false with two vector<int> (v1 > v2):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<int> oneOwn(5, 1);
            ft::vector<int> twoOwn(5, 1);
            bool ownEqual = ft::lexicographical_compare(oneOwn.begin(), oneOwn.end(), twoOwn.begin(), twoOwn.end());

            std::vector<int> oneOriginal(5, 1);
            std::vector<int> twoOriginal(5, 1);
            bool originalEqual = std::lexicographical_compare(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin(), twoOriginal.end());

            outputAssertion("returns false with two vector<int> (v1 == v2):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<std::string> oneOwn(5, "aaa");
            ft::vector<std::string> twoOwn(5, "zzzzzzz");
            bool ownEqual = ft::lexicographical_compare(oneOwn.begin(), oneOwn.end(), twoOwn.begin(), twoOwn.end());

            std::vector<std::string> oneOriginal(5, "aaa");
            std::vector<std::string> twoOriginal(5, "zzzzzzz");
            bool originalEqual = std::lexicographical_compare(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin(), twoOriginal.end());

            outputAssertion("returns true with two vector<std::string> (v1 < v2):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<std::string> oneOwn(5, "zzzz");
            ft::vector<std::string> twoOwn(5, "aaa");
            bool ownEqual = ft::lexicographical_compare(oneOwn.begin(), oneOwn.end(), twoOwn.begin(), twoOwn.end());

            std::vector<std::string> oneOriginal(5, "zzzz");
            std::vector<std::string> twoOriginal(5, "aaa");
            bool originalEqual = std::lexicographical_compare(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin(), twoOriginal.end());

            outputAssertion("returns true with two vector<std::string> (v1 > v2):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            ft::vector<std::string> oneOwn(5, "aaa");
            ft::vector<std::string> twoOwn(5, "aaa");
            bool ownEqual = ft::lexicographical_compare(oneOwn.begin(), oneOwn.end(), twoOwn.begin(), twoOwn.end());

            std::vector<std::string> oneOriginal(5, "aaa");
            std::vector<std::string> twoOriginal(5, "aaa");
            bool originalEqual = std::lexicographical_compare(oneOriginal.begin(), oneOriginal.end(), twoOriginal.begin(), twoOriginal.end());

            outputAssertion("returns true with two vector<std::string> (v1 == v2):", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {4, 5, 6};
            bool ownEqual = ft::lexicographical_compare(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), std::end(twoOwn));

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {4, 5, 6};
            bool originalEqual = std::lexicographical_compare(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), std::end(twoOriginal));

            outputAssertion("returns true with two arrays (int[]) with a1 < a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            int oneOwn[3] = {4, 5, 6};
            int twoOwn[3] = {1, 2, 3};
            bool ownEqual = ft::lexicographical_compare(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), std::end(twoOwn));

            int oneOriginal[3] = {4, 5, 6};
            int twoOriginal[3] = {1, 2, 3};
            bool originalEqual = std::lexicographical_compare(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), std::end(twoOriginal));

            outputAssertion("returns false with two arrays (int[]) with a1 > a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {
            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {1, 2, 3};
            bool ownEqual = ft::lexicographical_compare(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), std::end(twoOwn));

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {1, 2, 3};
            bool originalEqual = std::lexicographical_compare(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), std::end(twoOriginal));

            outputAssertion("returns false with two arrays (int[]) with a1 == a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        std::cout << "  WITH PREDICATE" << std::endl;
        {

            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {1, 2, 4};
            bool ownEqual = ft::lexicographical_compare(oneOwn, oneOwn + 3, twoOwn, twoOwn + 3, intPredLex);

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {1, 2, 4};
            bool originalEqual = std::lexicographical_compare(oneOriginal, oneOriginal + 3, twoOriginal, twoOriginal + 3, intPredLex);

            outputAssertion("returns true with two arrays (int[]) where a1 < a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            int oneOwn[3] = {1, 4, 3};
            int twoOwn[3] = {1, 2, 4};
            bool ownEqual = ft::lexicographical_compare(oneOwn, oneOwn + 3, twoOwn, twoOwn + 3, intPredLex);

            int oneOriginal[3] = {1, 4, 3};
            int twoOriginal[3] = {1, 2, 4};
            bool originalEqual = std::lexicographical_compare(oneOriginal, oneOriginal + 3, twoOriginal, twoOriginal + 3, intPredLex);

            outputAssertion("returns false with two arrays (int[]) where a1 > a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            int oneOwn[3] = {1, 2, 3};
            int twoOwn[3] = {1, 2, 3};
            bool ownEqual = ft::lexicographical_compare(oneOwn, oneOwn + 3, twoOwn, twoOwn + 3, intPredLex);

            int oneOriginal[3] = {1, 2, 3};
            int twoOriginal[3] = {1, 2, 3};
            bool originalEqual = std::lexicographical_compare(oneOriginal, oneOriginal + 3, twoOriginal, twoOriginal + 3, intPredLex);

            outputAssertion("returns false with two arrays (int[]) where a1 == a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            char oneOwn[2][5] = {"ciao", "miao"};
            char twoOwn[2][5] = {"ciao", "miap"};
            bool ownEqual = ft::lexicographical_compare(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), std::end(twoOwn), charArrayPredLex);

            char oneOriginal[2][5] = {"ciao", "miao"};
            char twoOriginal[2][5] = {"ciao", "miap"};
            bool originalEqual = std::lexicographical_compare(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), std::end(twoOriginal), charArrayPredLex);

            outputAssertion("returns true with two char[][] where a1 < a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            char oneOwn[2][5] = {"ciao", "mzao"};
            char twoOwn[2][5] = {"ciao", "miao"};
            bool ownEqual = ft::lexicographical_compare(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), std::end(twoOwn), charArrayPredLex);

            char oneOriginal[2][5] = {"ciao", "mzao"};
            char twoOriginal[2][5] = {"ciao", "miao"};
            bool originalEqual = std::lexicographical_compare(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), std::end(twoOriginal), charArrayPredLex);

            outputAssertion("returns false with two char[][] where a1 > a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
        {

            char oneOwn[2][5] = {"ciao", "miao"};
            char twoOwn[2][5] = {"ciao", "miao"};
            bool ownEqual = ft::lexicographical_compare(std::begin(oneOwn), std::end(oneOwn), std::begin(twoOwn), std::end(twoOwn), charArrayPredLex);

            char oneOriginal[2][5] = {"ciao", "miao"};
            char twoOriginal[2][5] = {"ciao", "miao"};
            bool originalEqual = std::lexicographical_compare(std::begin(oneOriginal), std::end(oneOriginal), std::begin(twoOriginal), std::end(twoOriginal), charArrayPredLex);

            outputAssertion("returns false with two char[][] where a1 == a2:", isStrictEqual<bool>(ownEqual, originalEqual, isDebug));
        }
    }
}