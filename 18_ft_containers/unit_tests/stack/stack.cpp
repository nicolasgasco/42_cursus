#include <iostream>

#include "lifecycle/constructor.cpp"
#include "lifecycle/assign.cpp"
#include "access/top.cpp"
#include "capacity/empty.cpp"
#include "capacity/size.cpp"
#include "modifiers/push.cpp"
#include "modifiers/pop.cpp"

void stackUnitTests(bool IS_DEBUG)
{
    std::cout << std::endl
              << YELLOW << "STACK UNIT TESTS" << NOCOL << std::endl;
    constructorUnitTests(IS_DEBUG);
    assignStackUnitTests(IS_DEBUG);
    topStackUnitTests(IS_DEBUG);
    empyStackUnitTests(IS_DEBUG);
    sizeStackUnitTests(IS_DEBUG);
    pushStackUnitTests(IS_DEBUG);
    popStackUnitTests(IS_DEBUG);
}