#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>

void emptyUnitTests(bool isDebug)
{
    outputSuiteTitle("EMPTY");
    {
        {
            std::cout << "Is equal to STL map value:" << std::endl;
            {
                ft::map<std::string, int> own;
                std::map<std::string, int> original;
                outputAssertion("after empty constructor:", isStrictEqual<bool>(own.empty(), original.empty(), isDebug));
            }
        }
    }
}