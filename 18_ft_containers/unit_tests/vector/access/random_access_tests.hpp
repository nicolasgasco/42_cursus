#pragma once

#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void randomAccessUnitTests(bool isDebug)
{
    outputSuiteTitle("RANDOM ACCESS");
    if (isDebug) {
        // Continue
    }
    // std::cout << "Is strictly equal to STL vector value:" << std::endl;
    // {
    //     // ft::vector<int> own;
    //     std::vector<int> original;
    //     original.push_back(10);
    //     outputAssertion("accessing[0] with reference:", isStrictEqual<std::allocator<int>::reference>(original[0], original[0], isDebug));
    // }
    // {
    //     ft::vector<int> own;
    //     own.push_back(10);
    //     std::vector<int> original;
    //     original.push_back(10);
    //     original = const_cast<const std::vector<int> &>(original);
    //     // own = const_cast<const std::vector<int> &>(own);
    //     outputAssertion("accessing[0] with const_reference:", isStrictEqual<std::allocator<int>::const_reference>(own[0], original[0], isDebug));
    // }
}