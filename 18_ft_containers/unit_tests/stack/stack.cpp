#include <iostream>

#include "lifecycle/constructor.cpp"
#include "lifecycle/assign.cpp"
#include "access/top.cpp"
#include "capacity/empty.cpp"
#include "capacity/size.cpp"
#include "modifiers/push.cpp"
#include "modifiers/pop.cpp"
#include "operators/relational_operators.cpp"

#include "speed/stack_speed_tests.cpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << std::endl
              << YELLOW << "STACK UNIT TESTS" << NOCOL << std::endl;
    constructorUnitTests(IS_DEBUG);
    assignStackUnitTests(IS_DEBUG);
    topStackUnitTests(IS_DEBUG);
    empyStackUnitTests(IS_DEBUG);
    sizeStackUnitTests(IS_DEBUG);
    pushStackUnitTests(IS_DEBUG);
    popStackUnitTests(IS_DEBUG);
    reletionalOperatorStackUnitTests(IS_DEBUG);

    // Speed
    speedStackUnitTests(IS_DEBUG);
}