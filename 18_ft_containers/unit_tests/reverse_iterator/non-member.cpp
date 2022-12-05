#include <vector>

#include "../utils.hpp"
#include "../vector.hpp"

#include "../reverse_iterator.hpp"

void nonMemberUnitTests(bool isDebug)
{
    outputSuiteTitle("NON-MEMBER");
    {
        std::cout
            << "Has same value as std::reverse_iterator:" << std::endl;
        {

            std::cout << std::endl
                      << "  ADDITION:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);

                outputAssertion("returns same value of (end() - 1) with int:", isStrictEqual<int>(*(1 + ownRit), *(1 + originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 2);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 2);

                outputAssertion("returns same value of (begin() + 2) with std::string:", isStrictEqual<std::string>(*(1 + ownRit), *(1 + originalRit), isDebug));
            }
        }
        {

            std::cout << std::endl
                      << "  SUBTRACTION:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit2(own.begin() + 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit2(original.begin() + 1);

                outputAssertion("returns same distance with int:", isStrictEqual<int>((ownRit2 - ownRit), (originalRit2 - originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 2);
                ft::vector<std::string>::reverse_iterator ownRit2(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 2);
                std::vector<std::string>::reverse_iterator originalRit2(original.begin() + 1);

                outputAssertion("returns same distance with std::string:", isStrictEqual<int>((ownRit2 - ownRit), (originalRit2 - originalRit), isDebug));
            }
        }
        {

            std::cout << std::endl
                      << "  EQUAL:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit2(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit2(original.end() - 1);

                outputAssertion("returns true with int:", isStrictEqual<bool>((ownRit2 == ownRit), (originalRit2 == originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 2);
                ft::vector<std::string>::reverse_iterator ownRit2(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 2);
                std::vector<std::string>::reverse_iterator originalRit2(original.begin() + 1);

                outputAssertion("returns false with std::string:", isStrictEqual<bool>((ownRit2 == ownRit), (originalRit2 == originalRit), isDebug));
            }
        }
        {

            std::cout << std::endl
                      << "  NOT EQUAL:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit2(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit2(original.end() - 1);

                outputAssertion("returns false with int:", isStrictEqual<bool>((ownRit2 != ownRit), (originalRit2 != originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 2);
                ft::vector<std::string>::reverse_iterator ownRit2(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 2);
                std::vector<std::string>::reverse_iterator originalRit2(original.begin() + 1);

                outputAssertion("returns true with std::string:", isStrictEqual<bool>((ownRit2 != ownRit), (originalRit2 != originalRit), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  GREATER THAN:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit2(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit2(original.end() - 1);

                outputAssertion("returns false with int:", isStrictEqual<bool>((ownRit2 > ownRit), (originalRit2 > originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 2);
                ft::vector<std::string>::reverse_iterator ownRit2(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 2);
                std::vector<std::string>::reverse_iterator originalRit2(original.begin() + 1);

                outputAssertion("returns true with std::string:", isStrictEqual<bool>((ownRit2 > ownRit), (originalRit2 > originalRit), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  LESS THAN:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit2(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit2(original.end() - 1);

                outputAssertion("returns false with int:", isStrictEqual<bool>((ownRit2 < ownRit), (originalRit2 < originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 1);
                ft::vector<std::string>::reverse_iterator ownRit2(own.begin() + 4);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 1);
                std::vector<std::string>::reverse_iterator originalRit2(original.begin() + 4);

                outputAssertion("returns true with std::string:", isStrictEqual<bool>((ownRit2 < ownRit), (originalRit2 < originalRit), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  GREATER THAN EQUAL:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit2(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit2(original.end() - 1);

                outputAssertion("returns true with int:", isStrictEqual<bool>((ownRit2 >= ownRit), (originalRit2 >= originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 2);
                ft::vector<std::string>::reverse_iterator ownRit2(own.begin() + 3);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 2);
                std::vector<std::string>::reverse_iterator originalRit2(original.begin() + 3);

                outputAssertion("returns false with std::string:", isStrictEqual<bool>((ownRit2 >= ownRit), (originalRit2 >= originalRit), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  LESS THAN EQUAL:" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(values, values + 5);
                ft::vector<int>::reverse_iterator ownRit(own.end() - 1);
                ft::vector<int>::reverse_iterator ownRit2(own.end() - 1);

                std::vector<int> original(values, values + 5);
                std::vector<int>::reverse_iterator originalRit(original.end() - 1);
                std::vector<int>::reverse_iterator originalRit2(original.end() - 1);

                outputAssertion("returns true with int:", isStrictEqual<bool>((ownRit2 <= ownRit), (originalRit2 <= originalRit), isDebug));
            }
            {
                std::string values[5] = {"1", "2", "3", "4", "5"};

                ft::vector<std::string> own(values, values + 5);
                ft::vector<std::string>::reverse_iterator ownRit(own.begin() + 3);
                ft::vector<std::string>::reverse_iterator ownRit2(own.begin() + 1);

                std::vector<std::string> original(values, values + 5);
                std::vector<std::string>::reverse_iterator originalRit(original.begin() + 3);
                std::vector<std::string>::reverse_iterator originalRit2(original.begin() + 1);

                outputAssertion("returns false with std::string:", isStrictEqual<bool>((ownRit2 <= ownRit), (originalRit2 <= originalRit), isDebug));
            }
        }
    }
}
