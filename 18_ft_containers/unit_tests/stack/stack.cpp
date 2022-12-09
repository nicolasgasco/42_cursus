#include <iostream>

#include "lifecycle/constructor.cpp"
#include "lifecycle/assign.cpp"
#include "access/top.cpp"

void stackUnitTests(bool IS_DEBUG)
{
    std::cout << std::endl
              << YELLOW << "STACK UNIT TESTS" << NOCOL << std::endl;
    constructorUnitTests(IS_DEBUG);
    assignStackUnitTests(IS_DEBUG);
    topStackUnitTests(IS_DEBUG);
}