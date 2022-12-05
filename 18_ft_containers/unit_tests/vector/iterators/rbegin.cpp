#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

void rBeginUnitTests(bool isDebug)
{
    outputSuiteTitle("RBEGIN");
    {
        std::cout << "Is const/ not const like STL iterator value:" << std::endl;
        {
            ft::vector<int> own(1, 10);
            ft::vector<int>::reverse_iterator ownIt = own.rbegin();

            std::cout << typeid(ownIt).name() << std::endl;
            outputAssertion("is not const with ::iterator:", !strcmp(typeid(ownIt).name(), "N2ft16reverse_iteratorIPiEE"));
        }
        {
            ft::vector<int> own(1, 10);
            ft::vector<int>::const_reverse_iterator ownIt = own.rbegin();

            std::cout << typeid(ownIt).name() << std::endl;
            outputAssertion("is const with ::const_iterator:", !strcmp(typeid(ownIt).name(), "N2ft16reverse_iteratorIPKiEE"));
        }
    }
    {
        std::cout << std::endl
                  << "Has same value of STL iterator value:" << std::endl;
        {
            ft::vector<int> own(1, 10);
            ft::vector<int>::reverse_iterator ownIt = own.rbegin();

            std::vector<int> original(1, 10);
            std::vector<int>::reverse_iterator originalIt = original.rbegin();
            outputAssertion("with fill constructor (1, 10):", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
        {
            ft::vector<int> own;
            own.push_back(10);
            ft::vector<int>::reverse_iterator ownIt = own.rbegin();

            std::vector<int> original;
            original.push_back(10);
            std::vector<int>::reverse_iterator originalIt = original.rbegin();
            outputAssertion("with default constructor + push_back(10):", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
        {
            ft::vector<int> own;
            own.push_back(10);
            own.push_back(5);
            ft::vector<int>::reverse_iterator ownIt = own.rbegin();

            std::vector<int> original;
            original.push_back(10);
            original.push_back(5);
            std::vector<int>::reverse_iterator originalIt = original.rbegin();
            outputAssertion("with default constructor + push_back(10) + push_back(5):", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
    }
}
