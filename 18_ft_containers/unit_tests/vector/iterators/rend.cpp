#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void rEndUnitTests(bool isDebug)
{
    outputSuiteTitle("REND:");
    {
        {
            std::cout << "Is const/ not const like STL iterator value:" << std::endl;
            {
                ft::vector<int> own(1, 10);
                ft::vector<int>::reverse_iterator ownIt = own.rend();

                std::cout << typeid(ownIt).name() << std::endl;
                outputAssertion("is not const with ::iterator:", !strcmp(typeid(ownIt).name(), "N2ft16reverse_iteratorINS_8iteratorIiEEEE"));
            }
            {
                ft::vector<int> own(1, 10);
                ft::vector<int>::const_reverse_iterator ownIt = own.rend();

                std::cout << typeid(ownIt).name() << std::endl;
                outputAssertion("is const with ::const_iterator:", !strcmp(typeid(ownIt).name(), "N2ft16reverse_iteratorINS_8iteratorIKiEEEE"));
            }
        }
        {
            std::cout << std::endl
                      << "Has same value of STL iterator value:" << std::endl;
            {
                ft::vector<int> own(1, 10);
                ft::vector<int>::reverse_iterator ownIt = own.rend();

                std::vector<int> original(1, 10);
                std::vector<int>::reverse_iterator originalIt = original.rend();
                outputAssertion("with fill constructor (1, 10):", isStrictEqual<int>(*(ownIt - 1), *(originalIt - 1), isDebug));
            }
            {
                ft::vector<int> own;
                own.push_back(10);
                ft::vector<int>::reverse_iterator ownIt = own.rend();

                std::vector<int> original;
                original.push_back(10);
                std::vector<int>::reverse_iterator originalIt = original.rend();
                outputAssertion("with default constructor + push_back(10):", isStrictEqual<int>(*(ownIt - 1), *(originalIt - 1), isDebug));
            }
            {
                ft::vector<int> own;
                own.push_back(10);
                own.push_back(5);
                ft::vector<int>::reverse_iterator ownIt = own.rend();

                std::vector<int> original;
                original.push_back(10);
                original.push_back(5);
                std::vector<int>::reverse_iterator originalIt = original.rend();
                outputAssertion("with default constructor + push_back(10) + push_back(5):", isStrictEqual<int>(*(ownIt - 1), *(originalIt - 1), isDebug));
            }
        }
    }
}
