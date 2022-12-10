#include <vector>

#include "../utils.hpp"
#include "../../vector.hpp"
#include "../../reverse_iterator.hpp"

void modifiersUnitTests(bool isDebug)
{
    outputSuiteTitle("MODIFIERS");
    {
        std::cout
            << "Has same value as std::reverse_iterator:" << std::endl;
        {
            std::cout << "  POST-INCREMENT:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);

                outputAssertion("returns same value of (end() - 1) with int:", isStrictEqual<int>(*(ownRit++), *(originalRit++), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of (begin() + 1) with int:", isStrictEqual<std::string>(*(ownRit++), *(originalRit++), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  POST-DECREMENT:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 2);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 2);

                outputAssertion("returns same value of (end() - 2) with int:", isStrictEqual<int>(*(ownRit--), *(originalRit--), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of (begin() + 1) with int:", isStrictEqual<std::string>(*(ownRit--), *(originalRit--), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  PRE-INCREMENT:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 2);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 2);

                outputAssertion("returns same value of (end() - 2) with int:", isStrictEqual<int>(*(++ownRit), *(++originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 2);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 2);

                outputAssertion("returns same value of (begin() + 2) with int:", isStrictEqual<std::string>(*(++ownRit), *(++originalRit), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  PRE-DECREMENT:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 2);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 2);

                outputAssertion("returns same value of (end() - 2) with int:", isStrictEqual<int>(*(--ownRit), *(--originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of (begin() + 1) with int:", isStrictEqual<std::string>(*(--ownRit), *(--originalRit), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  ADDITION:" << std::endl;
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 5);

                std::vector<int> original(values, values + 10);
                std::vector<int>::reverse_iterator originalRit(original.end() - 5);

                outputAssertion("returns same value of (end() - 5) with int:", isStrictEqual<int>(*(ownRit + 2), *(originalRit + 2), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 4);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 4);

                outputAssertion("returns same value of (begin() + 4) with int:", isStrictEqual<std::string>(*(ownRit + 2), *(originalRit + 2), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  SUBTRACTION:" << std::endl;
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 5);

                std::vector<int> original(values, values + 10);
                std::vector<int>::reverse_iterator originalRit(original.end() - 5);

                outputAssertion("returns same value of (end() - 5) with int:", isStrictEqual<int>(*(ownRit - 2), *(originalRit - 2), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of (begin() + 1) with int:", isStrictEqual<std::string>(*(ownRit - 2), *(originalRit - 2), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  ADDITION ASSIGNATION:" << std::endl;
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 5);

                std::vector<int> original(values, values + 10);
                std::vector<int>::reverse_iterator originalRit(original.end() - 5);

                outputAssertion("returns same value of (end() - 5) with int:", isStrictEqual<int>(*(ownRit += 2), *(originalRit += 2), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 4);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 4);

                outputAssertion("returns same value of (begin() + 4) with int:", isStrictEqual<std::string>(*(ownRit += 2), *(originalRit += 2), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  SUBTRACTION ASSIGNATION:" << std::endl;
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 5);

                std::vector<int> original(values, values + 10);
                std::vector<int>::reverse_iterator originalRit(original.end() - 5);

                outputAssertion("returns same value of (end() - 5) with int:", isStrictEqual<int>(*(ownRit -= 2), *(originalRit -= 2), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);

                outputAssertion("returns same value of (begin() + 1) with int:", isStrictEqual<std::string>(*(ownRit -= 2), *(originalRit -= 2), isDebug));
            }
        }
    }
}