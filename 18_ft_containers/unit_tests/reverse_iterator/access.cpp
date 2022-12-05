#include <vector>

#include "../utils.hpp"
#include "../vector.hpp"

#include "../reverse_iterator.hpp"

void accessUnitTests(bool isDebug)
{
    outputSuiteTitle("ACCESS");
    {
        std::cout
            << "Has same value as std::reverse_iterator:" << std::endl;
        {
            std::cout << "  BASE" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);

                outputAssertion("returns same value of (end() - 1) with int:", isStrictEqual<int>(*(ownRit.base()), *(originalRit.base()), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of (begin() + 1) with int:", isStrictEqual<std::string>(*(ownRit.base()), *(originalRit.base()), isDebug));
            }
        }
        {
            std::cout << "  DEREFERENCE" << std::endl;
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
        }
        {
            std::cout << "  RANDOM ACCESS" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);

                outputAssertion("returns same value of [1] with int:", isStrictEqual<int>(ownRit[1], originalRit[1], isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of [-1] with int:", isStrictEqual<std::string>(ownRit[-1], originalRit[-1], isDebug));
            }
        }
    }
}