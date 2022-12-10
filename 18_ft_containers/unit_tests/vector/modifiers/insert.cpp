#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void insertUnitTests(bool isDebug)
{
    outputSuiteTitle("INSERT");
    std::cout << "Deferenced return value is equal to STL vector:" << std::endl;
    {
        {
            std::cout << "  ITERATOR + VALUE" << std::endl;
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownIt = own.insert(own.begin(), 10);

                std::vector<int> original(2, 5);
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
        {
            std::cout << std::endl
                      << "  ITERATOR + COUNT + VALUE" << std::endl;
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownIt = own.insert(own.begin(), 3, 10);

                std::vector<int> original(2, 5);
                std::vector<int>::iterator originalIt = original.insert(original.begin(), 3, 10);

                outputAssertion("after inserting 3 values at index 0 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> own;
                ft::vector<int>::iterator ownIt = own.insert(own.begin(), 5, 10);

                std::vector<int> original;
                std::vector<int>::iterator originalIt = original.insert(original.begin(), 5, 10);

                outputAssertion("after inserting 5 values at index 0 in a vector with size 0:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownIt = own.insert(own.begin() + 1, 10, 10);

                std::vector<int> original(2, 5);
                std::vector<int>::iterator originalIt = original.insert(original.begin() + 1, 10, 10);

                outputAssertion("after inserting 10 values at index 1 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                ft::vector<int>::iterator ownIt = own.insert(own.begin() + 1, 0, 10);

                std::vector<int> original(2, 5);
                std::vector<int>::iterator originalIt = original.insert(original.begin() + 1, 0, 10);

                outputAssertion("after inserting 0 values at index 1 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> own(20, 5);
                ft::vector<int>::iterator ownIt = own.insert(own.begin() + 10, 100, 10);

                std::vector<int> original(20, 5);
                std::vector<int>::iterator originalIt = original.insert(original.begin() + 10, 100, 10);

                outputAssertion("after inserting 100 value at index 10 in a vector with size 20:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> ownTest(1, 1);
                ft::vector<int> ownTest2(5, 5);
                ownTest.insert(ownTest.begin(), 200, 12);
                std::cout << ownTest.capacity() << " - " << ownTest.size() << std::endl;
                ownTest.insert(ownTest.begin() + 12, 200, 30);
                std::cout << ownTest.capacity() << " - " << ownTest.size() << std::endl;
                ownTest.insert(ownTest.end(), 12, 50);
                std::cout << ownTest.capacity() << " - " << ownTest.size() << std::endl;
                ownTest.insert(ownTest.end() - 1, 0, 60);
                std::cout << ownTest.capacity() << " - " << ownTest.size() << std::endl;
                ownTest.insert(ownTest.end() - 1, 1, 70);
                std::cout << ownTest.capacity() << " - " << ownTest.size() << std::endl;

                std::vector<int> originalTest(1, 1);
                std::vector<int> originalTest2(5, 5);
                originalTest.insert(originalTest.begin(), 200, 12);
                std::cout << originalTest.capacity() << " - " << originalTest.size() << std::endl;
                originalTest.insert(originalTest.begin() + 12, 200, 30);
                std::cout << originalTest.capacity() << " - " << originalTest.size() << std::endl;
                originalTest.insert(originalTest.end(), 12, 50);
                std::cout << originalTest.capacity() << " - " << originalTest.size() << std::endl;
                originalTest.insert(originalTest.end() - 1, 0, 60);
                std::cout << originalTest.capacity() << " - " << originalTest.size() << std::endl;
                originalTest.insert(originalTest.end() - 1, 1, 70);
                std::cout << originalTest.capacity() << " - " << originalTest.size() << std::endl;
                outputAssertion("after insert values 5 times in a row:", isStrictEqual<int>(ownTest.capacity(), originalTest.capacity(), isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  ITERATORS" << std::endl;
            {
                ft::vector<int> own(2, 5);
                ft::vector<int> ownRef(3, 1);
                ft::vector<int>::iterator ownIt = own.insert(own.begin(), ownRef.begin(), ownRef.end());

                std::vector<int> original(2, 5);
                std::vector<int> originalRef(3, 1);
                std::vector<int>::iterator originalIt = original.insert(original.begin(), originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 3 values at index 0 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> own;
                ft::vector<int> ownRef(5, 1);
                ft::vector<int>::iterator ownIt = own.insert(own.begin(), ownRef.begin(), ownRef.end());

                std::vector<int> original;
                std::vector<int> originalRef(5, 1);
                std::vector<int>::iterator originalIt = original.insert(original.begin(), originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 5 values at index 0 in a vector with size 0:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                ft::vector<int> ownRef(10, 1);
                ft::vector<int>::iterator ownIt = own.insert(own.begin() + 1, ownRef.begin(), ownRef.end());

                std::vector<int> original(2, 5);
                std::vector<int> originalRef(10, 1);
                std::vector<int>::iterator originalIt = original.insert(original.begin() + 1, originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 10 values at index 1 in a vector with size 2:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::vector<int> own(20, 5);
                ft::vector<int> ownRef(100, 1);
                ft::vector<int>::iterator ownIt = own.insert(own.begin() + 10, ownRef.begin(), ownRef.end());

                std::vector<int> original(20, 5);
                std::vector<int> originalRef(100, 1);
                std::vector<int>::iterator originalIt = original.insert(original.begin() + 10, originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 100 value at index 10 in a vector with size 20:", isStrictEqual<int>(*ownIt, *originalIt, isDebug));
            }
        }
    }

    std::cout << std::endl
              << "Values are equal to STL vector values:" << std::endl;
    {
        {
            std::cout << "  ITERATOR + VALUE" << std::endl;
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
        {
            std::cout << std::endl
                      << "  ITERATOR + COUNT + VALUE cacca" << std::endl;
            {
                ft::vector<int> own(2, 5);
                own.insert(own.begin(), 3, 10);

                std::vector<int> original(2, 5);
                original.insert(original.begin(), 3, 10);

                outputAssertion("after inserting 3 values at index 0 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                ft::vector<int> own;
                own.insert(own.begin(), 5, 10);

                std::vector<int> original;
                original.insert(original.begin(), 5, 10);

                outputAssertion("after inserting 5 values at index 0 in a vector with size 0:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                own.insert(own.begin() + 1, 10, 10);

                std::vector<int> original(2, 5);
                original.insert(original.begin() + 1, 10, 10);

                outputAssertion("after inserting 10 values at index 1 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 12, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                own.insert(own.begin() + 1, 0, 10);

                std::vector<int> original(2, 5);
                original.insert(original.begin() + 1, 0, 10);

                outputAssertion("after inserting 0 values at index 1 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 2, isDebug));
            }
            {
                ft::vector<int> own(20, 5);
                own.insert(own.begin() + 10, 100, 10);

                std::vector<int> original(20, 5);
                original.insert(original.begin() + 10, 100, 10);

                outputAssertion("after inserting 100 value at index 10 in a vector with size 20:", isStrictEqual<int>(own.data(), original.data(), 120, isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "  ITERATORS" << std::endl;
            {
                ft::vector<int> own(2, 5);
                ft::vector<int> ownRef(3, 1);
                own.insert(own.begin(), ownRef.begin(), ownRef.end());

                std::vector<int> original(2, 5);
                std::vector<int> originalRef(3, 1);
                original.insert(original.begin(), originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 3 values at index 0 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                ft::vector<int> own;
                ft::vector<int> ownRef(5, 1);
                own.insert(own.begin(), ownRef.begin(), ownRef.end());

                std::vector<int> original;
                std::vector<int> originalRef(5, 1);
                original.insert(original.begin(), originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 5 values at index 0 in a vector with size 0:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                ft::vector<int> ownRef(10, 1);
                own.insert(own.begin() + 1, ownRef.begin(), ownRef.end());

                std::vector<int> original(2, 5);
                std::vector<int> originalRef(10, 1);
                original.insert(original.begin() + 1, originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 10 values at index 1 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 12, isDebug));
            }
            {
                ft::vector<int> own(2, 5);
                ft::vector<int> ownRef;
                own.insert(own.begin() + 1, ownRef.begin(), ownRef.end());

                std::vector<int> original(2, 5);
                std::vector<int> originalRef;
                original.insert(original.begin() + 1, originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 0 values at index 1 in a vector with size 2:", isStrictEqual<int>(own.data(), original.data(), 2, isDebug));
            }
            {
                ft::vector<int> own(20, 5);
                ft::vector<int> ownRef(100, 1);
                own.insert(own.begin() + 10, ownRef.begin(), ownRef.end());

                std::vector<int> original(20, 5);
                std::vector<int> originalRef(100, 1);
                original.insert(original.begin() + 10, originalRef.begin(), originalRef.end());

                outputAssertion("after inserting 100 value at index 10 in a vector with size 20:", isStrictEqual<int>(own.data(), original.data(), 120, isDebug));
            }
            {
                int values[10] = {30, 27, 24, 21, 18, 15, 12, 9, 6, 3};

                ft::vector<int> own;
                own.insert(own.end(), 42);
                own.insert(own.begin(), 2, 21);
                own.insert(own.end() - 2, 42);
                own.insert(own.end(), 2, 84);
                own.resize(4);

                ft::vector<int> ownRef(values, values + 10);
                own.insert(own.begin() + 2, ownRef.begin(), ownRef.end());

                ft::vector<int> original;
                original.insert(original.end(), 42);
                original.insert(original.begin(), 2, 21);
                original.insert(original.end() - 2, 42);
                original.insert(original.end(), 2, 84);
                original.resize(4);

                ft::vector<int> originalRef(values, values + 10);
                original.insert(original.begin() + 2, originalRef.begin(), originalRef.end());
                outputAssertion("after adding 10 values at index 2 with insert (iterators) in a vector with size 4:", isStrictEqual<int>(own.data(), original.data(), 14, isDebug));
            }
        }
    }
}