#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

void beginUnitTests(bool isDebug)
{
    outputSuiteTitle("BEGIN");
    std::cout << "Is const/ not const like STL iterator value:" << std::endl;
    {
        ft::vector<int> own(1, 10);
        ft::vector<int>::iterator ownIt = own.begin();

        std::cout << typeid(ownIt).name() << std::endl;
        outputAssertion("is not const with ::iterator:", !strcmp(typeid(ownIt).name(), "N2ft8iteratorIiEE"));
    }
    {
        ft::vector<int> const own(1, 10);
        ft::vector<int>::const_iterator ownIt = own.begin();

        std::cout << typeid(ownIt).name() << std::endl;
        outputAssertion("is const with ::const_iterator:", !strcmp(typeid(ownIt).name(), "N2ft8iteratorIKiEE"));
    }

    std::cout << std::endl
              << "Has same value of STL iterator value:" << std::endl;
    {
        ft::vector<int> own(1, 10);
        ft::vector<int>::iterator ownIt = own.begin();

        std::vector<int> original(1, 10);
        std::vector<int>::iterator originalIt = original.begin();
        outputAssertion("with fill constructor (1, 10):", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(10);
        ft::vector<int>::iterator ownIt = own.begin();

        std::vector<int> original;
        original.push_back(10);
        std::vector<int>::iterator originalIt = original.begin();
        outputAssertion("with default constructor + push_back(10):", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(10);
        own.push_back(5);
        ft::vector<int>::iterator ownIt = own.begin();

        std::vector<int> original;
        original.push_back(10);
        original.push_back(5);
        std::vector<int>::iterator originalIt = original.begin();
        outputAssertion("with default constructor + push_back(10) + push_back(5):", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
    }
}
