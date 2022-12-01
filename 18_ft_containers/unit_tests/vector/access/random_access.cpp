#include "utils.hpp"
#include <vector>
#include "../../vector/vector.hpp"

void randomAccessUnitTests(bool isDebug)
{
    outputSuiteTitle("RANDOM ACCESS");
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    std::cout << "  NOT CONST" << std::endl;
    {
        ft::vector<int> own(10, 10);
        std::vector<int> original(10, 10);
        outputAssertion("[start] (fill constructor with value):", isStrictEqual<std::allocator<int>::reference>(own[0], original[0], isDebug));
        outputAssertion("[end] (fill constructor with value):", isStrictEqual<std::allocator<int>::reference>(own[9], original[9], isDebug));
    }
    std::cout << "  CONST" << std::endl;
    {
        ft::vector<int> const own(10, 10);
        std::vector<int> const original(10, 10);
        outputAssertion("[start] (fill constructor with value):", isStrictEqual<std::allocator<int>::const_reference>(own[0], original[0], isDebug));
        outputAssertion("[end] (fill constructor with value):", isStrictEqual<std::allocator<int>::const_reference>(own[9], original[9], isDebug));
    }

    std::cout << std::endl
              << "Const check compared to STL vector value:" << std::endl;
    {
        ft::vector<int> own(5, 10);
        std::vector<int> original(5, 10);
        outputAssertion("is not const with fill costructor (num: 5, value: 10) at [start]:", isStrictEqual<bool>(isConst(own[0]), isConst(original[0]), isDebug));
    }
    {
        ft::vector<int> const own(5, 10);
        std::vector<int> const original(5, 10);
        outputAssertion("is const with fill costructor (num: 5, value: 10) at [start]:", isStrictEqual<bool>(isConst(own[0]), isConst(original[0]), isDebug));
    }
}