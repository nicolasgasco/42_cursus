#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

void insertUnitTests(bool isDebug)
{
    outputSuiteTitle("INSERT");
    std::cout << "Deferenced return value is equal to STL vector:" << std::endl;
    {
        {
            ft::vector<int> own;
            own.push_back(1);
            own.push_back(2);
            ft::vector<int>::iterator ownIt = own.insert(own.begin(), 10);

            std::vector<int> original;
            original.push_back(1);
            original.push_back(2);
            std::vector<int>::iterator originalIt = original.insert(original.begin(), 10);

            outputAssertion("after inserting 1 value at index 0 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
        {
            ft::vector<int> own;
            ft::vector<int>::iterator ownIt = own.insert(own.begin(), 10);

            std::vector<int> original;
            std::vector<int>::iterator originalIt = original.insert(original.begin(), 10);

            outputAssertion("after inserting 1 value at index 0 in a vector with size 0:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            ft::vector<int>::iterator ownIt = own.insert(own.begin() + 1, 10);

            std::vector<int> original(2, 5);
            std::vector<int>::iterator originalIt = original.insert(original.begin() + 1, 10);

            outputAssertion("after inserting 1 value at index 1 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            ft::vector<int>::iterator ownIt = own.insert(own.begin() + 2, 10);

            std::vector<int> original(2, 5);
            std::vector<int>::iterator originalIt = original.insert(original.begin() + 2, 10);

            outputAssertion("after inserting 1 value at index 2 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
        {
            ft::vector<int> own(20, 5);
            ft::vector<int>::iterator ownIt = own.insert(own.begin() + 10, 10);

            std::vector<int> original(20, 5);
            std::vector<int>::iterator originalIt = original.insert(original.begin() + 10, 10);

            outputAssertion("after inserting 1 value at index 10 in a vector with size 20:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
        }
    }

    std::cout << "Values are equal to STL vector values:" << std::endl;
    {
        {
            ft::vector<int> own(2, 5);
            own.insert(own.begin(), 7);

            std::vector<int> original(2, 5);
            original.insert(original.begin(), 7);

            outputAssertion("after inserting 1 value at index 0 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
        }
        {
            ft::vector<int> own;
            own.insert(own.begin(), 7);

            std::vector<int> original;
            original.insert(original.begin(), 7);

            outputAssertion("after inserting 1 value at index 0 in a vector with size 0:", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.insert(own.begin() + 1, 7);

            std::vector<int> original(2, 5);
            original.insert(original.begin() + 1, 7);

            outputAssertion("after inserting 1 value at index 1 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.insert(own.begin() + 2, 7);

            std::vector<int> original(2, 5);
            original.insert(original.begin() + 2, 7);

            outputAssertion("after inserting 1 value at index 2 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 3, isDebug));
        }
        {
            ft::vector<int> own(20, 5);
            own.insert(own.begin() + 10, 7);

            std::vector<int> original(20, 5);
            original.insert(original.begin() + 10, 7);

            outputAssertion("after inserting 1 value at index 10 in a vector with size 20:", isStrictEqual<int>(own.data(), original.data(), 21, isDebug));
        }
    }
}