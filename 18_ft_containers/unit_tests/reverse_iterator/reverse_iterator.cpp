#include <iostream>

#include "constructors.cpp"
#include "access.cpp"
#include "modifiers.cpp"
#include "non-member.cpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << std::endl
              << YELLOW << "REVERSE ITERATOR UNIT TESTS" << NOCOL << std::endl;
    constructorsUnitTests(IS_DEBUG);
    accessUnitTests(IS_DEBUG);
    modifiersUnitTests(IS_DEBUG);
    nonMemberUnitTests(IS_DEBUG);
}