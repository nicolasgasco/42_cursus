#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void randomAccessUnitTests(bool isDebug)
{
    outputSuiteTitle("RANDOM ACCESS");
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own(10, 10);
        std::vector<int> original(10, 10);
        outputAssertion("[start] with reference (fill constructor with value):", isStrictEqual<std::allocator<int>::reference>(own[0], original[0], isDebug));
    }
    {
        ft::vector<int> own(10, 10);
        std::vector<int> original(10, 10);
        outputAssertion("[end] with reference (fill constructor with value):", isStrictEqual<std::allocator<int>::reference>(own[9], original[9], isDebug));
    }
    // {
    //     ft::vector<int> own(1, 10);
    //     own = const_cast<const std::vector<int> &>(own);
    //     std::vector<int> original(1, 10);
    //     original = const_cast<const std::vector<int> &>(original);
    //     outputAssertion("accessing[0] with const_reference:", isStrictEqual<std::allocator<int>::const_reference>(own[0], original[0], isDebug));
    // }
}