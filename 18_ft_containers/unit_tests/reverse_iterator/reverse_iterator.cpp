#include <iostream>

#include "constructors.cpp"
#include "access.cpp"
#include "modifiers.cpp"
#include "non-member.cpp"

void reverseIteratorUnitTests(bool IS_DEBUG)
{
    std::cout << std::endl
              << YELLOW << "REVERSE ITERATOR UNIT TESTS" << NOCOL << std::endl;
    constructorsUnitTests(IS_DEBUG);
    accessUnitTests(IS_DEBUG);
    modifiersUnitTests(IS_DEBUG);
    nonMemberUnitTests(IS_DEBUG);
}