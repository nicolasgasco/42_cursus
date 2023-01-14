#include "../../../vector.hpp"
#include <vector>

#include "constructors.cpp"
#include "modifiers.cpp"
#include "capacity.cpp"
#include "access.cpp"

void speedUnitTests(bool isDebug)
{
    outputSuiteTitle("SPEED");
    {
        constructorsSpeedTest(isDebug);
        modifiersSpeedTest(isDebug);
        capacitySpeedTest(isDebug);
        accessSpeedTest(isDebug);
    }
}
