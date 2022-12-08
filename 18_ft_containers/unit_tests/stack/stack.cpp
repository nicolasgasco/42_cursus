#include <iostream>

#include "lifecycle/constructor.cpp"

void stackUnitTests(bool IS_DEBUG)
{
    std::cout << std::endl
              << YELLOW << "STACK UNIT TESTS" << NOCOL << std::endl;
    constructorUnitTests(IS_DEBUG);
}