#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

void endUnitTests(bool isDebug)
{
    outputSuiteTitle("END");
    std::cout << "Is const/ not const like STL iterator value:" << std::endl;
    {
        ft::vector<int> own(1, 10);
        ft::vector<int>::iterator ownIt = own.begin();

        std::cout << typeid(ownIt).name() << std::endl;
        outputAssertion("is not const with ::iterator:", !strcmp(typeid(ownIt).name(), "Pi"));
    }
    {
        ft::vector<int> own(1, 10);
        ft::vector<int>::const_iterator ownIt = own.begin();

        std::cout << typeid(ownIt).name() << std::endl;
        outputAssertion("is const with ::const_iterator:", !strcmp(typeid(ownIt).name(), "PKi"));
    }

    std::cout << std::endl
              << "Has same value of STL iterator value:" << std::endl;
    {
        ft::vector<int> own;
        int ownLast = 0;
        for (ft::vector<int>::iterator it = own.begin(); it != own.end(); it++)
            ownLast = *it;

        std::vector<int> original;
        int originalLast = 0;
        for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
            originalLast = *it;

        outputAssertion("with default constructor:", isStrictEqual<int>(ownLast, originalLast, isDebug));
    }
    {
        ft::vector<int> own(1, 10);
        int ownLast = 0;
        for (ft::vector<int>::iterator it = own.begin(); it != own.end(); it++)
            ownLast = *it;

        std::vector<int> original(1, 10);
        int originalLast = 0;
        for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
            originalLast = *it;

        outputAssertion("with fill constructor (1, 10):", isStrictEqual<int>(ownLast, originalLast, isDebug));
    }
    {
        ft::vector<int> own(5, 10);
        int ownLast = 0;
        for (ft::vector<int>::iterator it = own.begin(); it != own.end(); it++)
            ownLast = *it;

        std::vector<int> original(5, 10);
        int originalLast = 0;
        for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
            originalLast = *it;

        outputAssertion("with fill constructor (5, 10):", isStrictEqual<int>(ownLast, originalLast, isDebug));
    }
    std::cout << "Has same type of STL iterator value:" << std::endl;
    {
        ft::vector<int> own;
        own.push_back(10);
        int ownLast = 0;
        for (ft::vector<int>::iterator it = own.begin(); it != own.end(); it++)
            ownLast = *it;

        std::vector<int> original(5, 10);
        original.push_back(10);
        int originalLast = 0;
        for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
            originalLast = *it;

        outputAssertion("with default constructor + push_back(10):", isStrictEqual<int>(ownLast, originalLast, isDebug));
    }
    {
        ft::vector<int> own;
        own.push_back(5);
        own.push_back(10);
        int ownLast = 0;
        for (ft::vector<int>::iterator it = own.begin(); it != own.end(); it++)
            ownLast = *it;

        std::vector<int> original(5, 10);
        original.push_back(10);
        own.push_back(5);
        int originalLast = 0;
        for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
            originalLast = *it;

        outputAssertion("with default constructor + push_back(10) + push_back(5):", isStrictEqual<int>(ownLast, originalLast, isDebug));
    }
}
