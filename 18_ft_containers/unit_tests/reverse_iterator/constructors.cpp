#include <vector>

#include "../utils.hpp"
#include "../../vector.hpp"
#include "../../reverse_iterator.hpp"

void constructorsUnitTests(bool isDebug)
{
    outputSuiteTitle("CONSTRUCTORS");
    {
        std::cout
            << "Has same values as std::reverse_iterator:" << std::endl;
        {
            std::cout << "  VALUE CONSTRUCTOR" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);

                outputAssertion("returns same value of (end() - 1) with int:", isStrictEqual<int>(*ownRit, *originalRit, isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of (begin() + 1) with int:", isStrictEqual<std::string>(*ownRit, *originalRit, isDebug));
            }
            {
                bool values[2] = {true, false};

                ft::vector<bool> own(values, values + 2);
                ft::vector<bool>::reverse_iterator ownRit(own.begin() + 2);

                std::vector<bool> original(values, values + 2);
                std::vector<bool>::reverse_iterator originalRit(original.begin() + 2);

                outputAssertion("returns same value of (begin() + 2) with int:", isStrictEqual<bool>(*ownRit, *originalRit, isDebug));
            }
        }
        {
            std::cout << "  COPY CONSTRUCTOR" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownCopy(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit = ownCopy;

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalCopy(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit = originalCopy;

                outputAssertion("returns same value of (end() - 1) with int:", isStrictEqual<int>(*ownRit, *originalRit, isDebug));
            }
        }
    }
}