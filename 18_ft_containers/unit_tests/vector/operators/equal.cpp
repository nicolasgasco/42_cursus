#include <vector>

#include "utils.hpp"
#include "../vector.hpp"

void equalUnitTests(bool isDebug)
{
    outputSuiteTitle("EQUAL");
    {
        std::cout
            << "Return value is equal to STL vector value:" << std::endl;
        {
            ft::vector<int> seedOwn(5, 10);
            ft::vector<int> own(5, 10);

            std::vector<int> seedOriginal(5, 10);
            std::vector<int> original(5, 10);
            outputAssertion("when same size and same value repeated", isStrictEqual<bool>((own == seedOwn), (original == seedOriginal), isDebug));
        }
        {
            ft::vector<int> seedOwn(5, 10);
            ft::vector<int> own(6, 10);

            std::vector<int> seedOriginal(5, 10);
            std::vector<int> original(6, 10);
            outputAssertion("when different size and same value repeated", isStrictEqual<bool>((own == seedOwn), (original == seedOriginal), isDebug));
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
            outputAssertion("when same size and varied values", isStrictEqual<bool>((own == seedOwn), (original == seedOriginal), isDebug));
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
            outputAssertion("when different size and same varied values", isStrictEqual<bool>((own == seedOwn), (original == seedOriginal), isDebug));
        }
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> seedOwn;
            fillVectorWithValues<int>(seedOwn, values, 5);
            ft::vector<int> own(5, 10);

            std::vector<int> seedOriginal;
            fillVectorWithValues<int>(seedOriginal, values, 5);
            std::vector<int> original(5, 10);
            outputAssertion("when same size and differnet values", isStrictEqual<bool>((own == seedOwn), (original == seedOriginal), isDebug));
        }
        {
            ft::vector<int> seedOwn;
            ft::vector<int> own;

            std::vector<int> seedOriginal;
            std::vector<int> original;
            outputAssertion("when size = 0", isStrictEqual<bool>((own == seedOwn), (original == seedOriginal), isDebug));
        }
        {
            ft::vector<int> seedOwn(5);
            ft::vector<int> own(5);

            std::vector<int> seedOriginal(5);
            std::vector<int> original(5);
            outputAssertion("when same size and default filled", isStrictEqual<bool>((own == seedOwn), (original == seedOriginal), isDebug));
        }
    }
}