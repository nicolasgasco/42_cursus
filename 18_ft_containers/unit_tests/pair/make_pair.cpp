#include <vector>

#include "../utils.hpp"
#include "../../vector.hpp"
#include "../../pair.hpp"

void makePairUnitTests(bool isDebug)
{
    outputSuiteTitle("FT::MAKE_PAIR");
    {
        std::cout
            << "Has same values as std::pair:" << std::endl;
        {
            ft::pair<std::string, int> myPair = ft::make_pair<std::string, int>("foo", 1);

            std::pair<std::string, int> originalPair = std::make_pair<std::string, int>("foo", 1);

            outputAssertion("returns true when making a <std::string, int> pair:", isStrictEqual<std::string, int>(myPair, originalPair, isDebug));
        }
        {
            ft::pair<char, bool> myPair = ft::make_pair<char, bool>('a', false);

            std::pair<char, bool> originalPair = std::make_pair<char, bool>('a', false);

            outputAssertion("returns true when making a <char, bool> pair:", isStrictEqual<char, bool>(myPair, originalPair, isDebug));
        }
        {
            ft::pair<std::string, std::string> myPair = ft::make_pair<std::string, std::string>("foo", "bar");

            std::pair<std::string, std::string> originalPair = std::make_pair<std::string, std::string>("foo", "bar");

            outputAssertion("returns true when making a <std::string, std::string> pair:", isStrictEqual<std::string, std::string>(myPair, originalPair, isDebug));
        }
    }
}