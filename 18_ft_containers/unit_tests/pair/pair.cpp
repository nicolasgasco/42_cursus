#include <vector>

#include "../utils.hpp"
#include "../../vector.hpp"
#include "../../pair.hpp"

void pairUnitTests(bool isDebug)
{
    outputSuiteTitle("FT::PAIR");

    {
        std::cout
            << "CONSTRUCTORS:" << std::endl;
        {
            std::cout
                << "Has same values as std::pair:" << std::endl;
            {
                ft::pair<std::string, int> myPair;

                std::pair<std::string, int> originalPair;

                outputAssertion("returns true with empty constructor:", isStrictEqual<std::string, int>(myPair, originalPair, isDebug));
            }
            {
                std::pair<std::string, int> ref("bar", 42);

                ft::pair<std::string, int> myPair(ref);

                std::pair<std::string, int> originalPair(ref);

                outputAssertion("returns true with copy constructor:", isStrictEqual<std::string, int>(myPair, originalPair, isDebug));
            }
            {
                ft::pair<std::string, int> myPair("foo", 100);

                std::pair<std::string, int> originalPair("foo", 100);

                outputAssertion("returns true with fill constructor:", isStrictEqual<std::string, int>(myPair, originalPair, isDebug));
            }
        }
    }
    {
        std::cout
            << std::endl
            << "OPERATORS:" << std::endl;
        {
            std::cout
                << "Has same values as std::pair:" << std::endl;
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns true with == operator and two identical pairs:", isStrictEqual<bool>(myPair1 == myPair2, originalPair1 == originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("bar", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("bar", 1);

                outputAssertion("returns true with == operator and two different pairs:", isStrictEqual<bool>(myPair1 == myPair2, originalPair1 == originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns false with != operator and two identical pairs:", isStrictEqual<bool>(myPair1 != myPair2, originalPair1 != originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("bar", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("bar", 1);

                outputAssertion("returns true with != operator and two different pairs:", isStrictEqual<bool>(myPair1 != myPair2, originalPair1 != originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns false with < operator and two identical pairs:", isStrictEqual<bool>(myPair1 < myPair2, originalPair1 < originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 2);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 2);

                outputAssertion("returns true with < operator and two different pairs:", isStrictEqual<bool>(myPair1 < myPair2, originalPair1 < originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns true with <= operator and two identical pairs:", isStrictEqual<bool>(myPair1 <= myPair2, originalPair1 <= originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 2);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 2);

                outputAssertion("returns true with <= operator and two different pairs:", isStrictEqual<bool>(myPair1 <= myPair2, originalPair1 <= originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns false with > operator and two identical pairs:", isStrictEqual<bool>(myPair1 > myPair2, originalPair1 > originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("zoo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("zoo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns true with > operator and two different pairs:", isStrictEqual<bool>(myPair1 > myPair2, originalPair1 > originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("foo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("foo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns true with >= operator and two identical pairs:", isStrictEqual<bool>(myPair1 >= myPair2, originalPair1 >= originalPair2, isDebug));
            }
            {
                ft::pair<std::string, int> myPair1("zoo", 1);
                ft::pair<std::string, int> myPair2("foo", 1);

                std::pair<std::string, int> originalPair1("zoo", 1);
                std::pair<std::string, int> originalPair2("foo", 1);

                outputAssertion("returns true with >= operator and two different pairs:", isStrictEqual<bool>(myPair1 >= myPair2, originalPair1 >= originalPair2, isDebug));
            }
        }
    }
}