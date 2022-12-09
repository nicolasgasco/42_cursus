#include <vector>

#include "../vector.hpp"

#include "constructors.cpp"
#include "capacity.cpp"
// #include "modifiers.cpp"
// #include "access.cpp"

void speedStackUnitTests(bool isDebug)
{
    outputSuiteTitle("SPEED:");
    {
        constructorsStackSpeedTest(isDebug);
        capacityStackSpeedTest(isDebug);
    }
}
