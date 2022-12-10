#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void eraseUnitTests(bool isDebug)
{
    outputSuiteTitle("ERASE:");
    {
        std::cout << "Return value is equal to STL vector:" << std::endl;
        {
            std::cout << "  ITERATOR" << std::endl;
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownValue = own.erase(own.begin());

                std::vector<int> original(2, 5);
                std::vector<int>::iterator originalValue = original.erase(original.begin());

                outputAssertion("after erasing index 0 in a vector with size 2:", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 1);

                std::vector<int> original(2, 5);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 1);

                outputAssertion("after erasing index 1 in a vector with size 2 (is equal to end()):", isStrictEqual<bool>(ownValue == own.end(), originalValue == original.end(), isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 9);

                std::vector<int> original(values, values + 10);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 9);

                outputAssertion("after erasing index 9 in a vector with size 10 (varied values):", isStrictEqual<bool>(ownValue == own.end(), originalValue == original.end(), isDebug));
            }
            {
                ft::vector<int> own(10, 5);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 5);

                std::vector<int> original(10, 5);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 5);

                outputAssertion("after erasing index 5 in a vector with size 10:", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 5);

                std::vector<int> original(values, values + 10);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 5);

                outputAssertion("after erasing index 5 in a vector with size 10 (varied values):", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  RANGE" << std::endl;
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownValue = own.erase(own.begin(), own.begin());

                std::vector<int> original(2, 5);
                std::vector<int>::iterator originalValue = original.erase(original.begin(), original.begin());

                outputAssertion("after erasing 1 value at index 0 in a vector with size 2:", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 1, own.begin() + 1);

                std::vector<int> original(2, 5);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 1, original.begin() + 1);

                outputAssertion("after erasing 1 value at index 1 in a vector with size 2 (is equal to end()):", isStrictEqual<bool>(ownValue == own.end(), originalValue == original.end(), isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 7, own.begin() + 9);

                std::vector<int> original(values, values + 10);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 7, original.begin() + 9);

                outputAssertion("after erasing 2 values at index 7 in a vector with size 10 (varied values):", isStrictEqual<bool>(ownValue == own.end(), originalValue == original.end(), isDebug));
            }
            {
                ft::vector<int> own(10, 5);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 4, own.begin() + 9);

                std::vector<int> original(10, 5);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 4, original.begin() + 9);

                outputAssertion("after erasing 5 values at index 4 in a vector with size 10:", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 5, own.begin() + 7);

                std::vector<int> original(values, values + 10);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 5, original.begin() + 7);

                outputAssertion("after erasing 2 values at index 5 in a vector with size 10 (varied values):", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::iterator ownValue = own.erase(own.begin(), own.begin() + 5);

                std::vector<int> original(values, values + 10);
                std::vector<int>::iterator originalValue = original.erase(original.begin(), original.begin() + 5);

                outputAssertion("after erasing 5 values at index 0 in a vector with size 10 (varied values):", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                ft::vector<int>::iterator ownValue = own.erase(own.begin() + 1, own.begin() + 9);

                std::vector<int> original(values, values + 10);
                std::vector<int>::iterator originalValue = original.erase(original.begin() + 1, original.begin() + 9);

                outputAssertion("after erasing 8 values at index 1 in a vector with size 10 (varied values):", isStrictEqual<int>(*ownValue, *originalValue, isDebug));
            }
        }
    }
    {
        std::cout << std::endl
                  << "Values are equal to STL vector:" << std::endl;
        {
            std::cout << "  ITERATOR" << std::endl;
            {
                ft::vector<int> own(2, 5);
                own.erase(own.begin());

                std::vector<int> original(2, 5);
                original.erase(original.begin());

                outputAssertion("after erasing index 0 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                own.erase(own.begin() + 1);

                std::vector<int> original(2, 5);
                original.erase(original.begin() + 1);

                outputAssertion("after erasing index 1 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
            }
            {
                ft::vector<int> own(10, 5);
                own.erase(own.begin() + 5);

                std::vector<int> original(10, 5);
                original.erase(original.begin() + 5);

                outputAssertion("after erasing index 5 in a vector with size 10:", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                own.erase(own.begin() + 5);

                std::vector<int> original(values, values + 10);
                original.erase(original.begin() + 5);

                outputAssertion("after erasing index 5 in a vector with size 10 (varied values):", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                own.erase(own.begin() + 9);

                std::vector<int> original(values, values + 10);
                original.erase(original.begin() + 9);

                outputAssertion("after erasing index 9 in a vector with size 10 (varied values):", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                own.erase(own.begin());

                std::vector<int> original(values, values + 10);
                original.erase(original.begin());

                outputAssertion("after erasing index 0 in a vector with size 10 (varied values):", isStrictEqual<int>(own.data(), original.data(), 9, isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  RANGE" << std::endl;
            {
                ft::vector<int> own(2, 5);
                own.erase(own.begin(), own.begin());

                std::vector<int> original(2, 5);
                original.erase(original.begin(), original.begin());

                outputAssertion("after erasing 1 value at index 0 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                own.erase(own.begin() + 1, own.begin() + 1);

                std::vector<int> original(2, 5);
                original.erase(original.begin() + 1, original.begin() + 1);

                outputAssertion("after erasing 1 value at index 1 in a vector with size 2 (is equal to end()):", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                own.erase(own.begin() + 7, own.begin() + 9);

                std::vector<int> original(values, values + 10);
                original.erase(original.begin() + 7, original.begin() + 9);

                outputAssertion("after erasing 2 values at index 7 in a vector with size 10 (varied values):", isStrictEqual<int>(own.data(), original.data(), 8, isDebug));
            }
            {
                ft::vector<int> own(10, 5);
                own.erase(own.begin() + 4, own.begin() + 9);

                std::vector<int> original(10, 5);
                original.erase(original.begin() + 4, original.begin() + 9);

                outputAssertion("after erasing 5 values at index 4 in a vector with size 10:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                own.erase(own.begin() + 5, own.begin() + 7);

                std::vector<int> original(values, values + 10);
                original.erase(original.begin() + 5, original.begin() + 7);

                outputAssertion("after erasing 2 values at index 5 in a vector with size 10 (varied values):", isStrictEqual<int>(own.data(), original.data(), 8, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                own.erase(own.begin(), own.begin() + 5);

                std::vector<int> original(values, values + 10);
                original.erase(original.begin(), original.begin() + 5);

                outputAssertion("after erasing 5 values at index 0 in a vector with size 10 (varied values):", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

                ft::vector<int> own(values, values + 10);
                own.erase(own.begin() + 1, own.begin() + 9);

                std::vector<int> original(values, values + 10);
                original.erase(original.begin() + 1, original.begin() + 9);

                outputAssertion("after erasing 8 values at index 1 in a vector with size 10 (varied values):", isStrictEqual<int>(own.data(), original.data(), 2, isDebug));
            }
        }
    }
}