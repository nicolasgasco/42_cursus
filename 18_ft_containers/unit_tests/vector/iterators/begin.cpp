#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

void beginUnitTests(bool isDebug)
{
    outputSuiteTitle("BEGIN");
    std::cout << "Has same type of STL iterator value:" << std::endl;
    {
        ft::vector<int> own(1, 10);
        ft::vector<int>::iterator ownIt = own.begin();

        std::vector<int> original(1, 10);
        std::vector<int>::iterator originalIt = original.begin();
        outputAssertion("with fill constructor (1, 10):", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
    }
    std::cout << "Has same type of STL iterator value:" << std::endl;
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
