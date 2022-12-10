#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void greaterThanEqualUnitTests(bool isDebug)
{
    outputSuiteTitle("GREATER THAN EQUAL");
    {
        std::cout
            << "Return value is equal to STL vector value:" << std::endl;
        {
            ft::vector<int> seedOwn(5, 10);
            ft::vector<int> own(5, 10);

            std::vector<int> seedOriginal(5, 10);
            std::vector<int> original(5, 10);
            outputAssertion("returns true when same size and v1 == v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            ft::vector<int> seedOwn(5, 10);
            ft::vector<int> own(5, 1);

            std::vector<int> seedOriginal(5, 10);
            std::vector<int> original(5, 1);
            outputAssertion("returns false when same size and v1 < v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            ft::vector<int> seedOwn(5, 10);
            ft::vector<int> own(6, 10);

            std::vector<int> seedOriginal(5, 10);
            std::vector<int> original(6, 10);
            outputAssertion("returns true when different size and v1 > v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> seedOwn;
            fillVectorWithValues<int>(seedOwn, values, 5);
            ft::vector<int> own;
            fillVectorWithValues<int>(own, values, 5);

            std::vector<int> seedOriginal;
            fillVectorWithValues<int>(seedOriginal, values, 5);
            std::vector<int> original;
            fillVectorWithValues<int>(original, values, 5);
            outputAssertion("returns true when same size and v1 == v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> seedOwn;
            fillVectorWithValues<int>(seedOwn, values, 5);
            ft::vector<int> own;
            fillVectorWithValues<int>(own, values, 4);

            std::vector<int> seedOriginal;
            fillVectorWithValues<int>(seedOriginal, values, 5);
            std::vector<int> original;
            fillVectorWithValues<int>(original, values, 4);
            outputAssertion("returns false when different size and v1 < v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> seedOwn;
            fillVectorWithValues<int>(seedOwn, values, 5);
            ft::vector<int> own(5, 10);

            std::vector<int> seedOriginal;
            fillVectorWithValues<int>(seedOriginal, values, 5);
            std::vector<int> original(5, 10);
            outputAssertion("returns true when same size and v1 > v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            ft::vector<int> seedOwn;
            ft::vector<int> own;

            std::vector<int> seedOriginal;
            std::vector<int> original;
            outputAssertion("returns true when size = 0", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            ft::vector<int> seedOwn(5, 10);
            ft::vector<int> own(4, 10);

            std::vector<int> seedOriginal(5, 10);
            std::vector<int> original(4, 10);
            outputAssertion("returns false when same values and size v1 < v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            int values1[4] = {1, 2, 3, 4};
            int values2[4] = {1, 2, 4, 3};

            ft::vector<int> seedOwn;
            fillVectorWithValues<int>(seedOwn, values2, 4);
            ft::vector<int> own;
            fillVectorWithValues<int>(own, values1, 4);

            std::vector<int> seedOriginal;
            fillVectorWithValues<int>(seedOriginal, values2, 4);
            std::vector<int> original;
            fillVectorWithValues<int>(original, values1, 4);
            outputAssertion("returns false when same size and v1 < v2", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
        {
            int values[4] = {1, 2, 4, 3};

            ft::vector<int> seedOwn;
            ft::vector<int> own;
            fillVectorWithValues<int>(own, values, 4);

            std::vector<int> seedOriginal;
            std::vector<int> original;
            fillVectorWithValues<int>(original, values, 4);
            outputAssertion("returns true when v2 is size 0 and v1 size > 0", isStrictEqual<bool>((own >= seedOwn), (original >= seedOriginal), isDebug));
        }
    }
}