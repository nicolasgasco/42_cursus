#include "utils.hpp"
#include <vector>
#include "../vector.hpp"

void assignUnitTests(bool isDebug)
{
    outputSuiteTitle("ASSIGN");
    {
        std::cout << std::endl
                  << "Values are equal to STL vector values:" << std::endl;
        {
            std::cout << "  ITERATORS" << std::endl;
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(5, 5);
                own.assign(values, values + 5);

                std::vector<int> original(5, 5);
                original.assign(values, values + 5);

                outputAssertion("after assigning 5 values in a vector with size 5:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own;
                own.assign(values, values + 5);

                std::vector<int> original;
                original.assign(values, values + 5);

                outputAssertion("after inserting 5 values a vector with size 0:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                int values[5] = {1, 2, 3, 4, 5};

                ft::vector<int> own(50, 10);
                own.assign(values, values + 5);

                std::vector<int> original(50, 10);
                original.assign(values, values + 5);

                outputAssertion("after inserting 5 values in a vector with size 50:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                int values[] = {};

                ft::vector<int> own(5, 10);
                own.assign(values, values + 5);

                std::vector<int> original(5, 10);
                original.assign(values, values + 5);

                outputAssertion("after inserting 0 values in a vector with size 5:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
        }
        {
            std::cout << "  RANGE" << std::endl;
            {
                ft::vector<int> own(5, 5);
                own.assign(5, 1);

                std::vector<int> original(5, 5);
                original.assign(5, 1);

                outputAssertion("after assigning 5 values in a vector with size 5:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                ft::vector<int> own;
                own.assign(5, 1);

                std::vector<int> original;
                original.assign(5, 1);

                outputAssertion("after inserting 5 values a vector with size 0:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
            {
                ft::vector<int> own(50, 10);
                own.assign(5, 1);

                std::vector<int> original(50, 10);
                original.assign(5, 1);

                outputAssertion("after inserting 5 values in a vector with size 50:", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
            }
        }
    }
}