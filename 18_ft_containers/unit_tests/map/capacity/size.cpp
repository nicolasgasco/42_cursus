#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>

void sizeUnitTests(bool isDebug)
{
    outputSuiteTitle("SIZE");
    {
        std::cout << "Is initialized equal to STL map value:" << std::endl;
        {
            ft::map<std::string, int> own;
            std::map<std::string, int> original;
            outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
    }
}