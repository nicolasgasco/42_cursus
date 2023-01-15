#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>

void maxSizeUnitTests(bool isDebug)
{
    outputSuiteTitle("MAX SIZE");
    {
        std::cout << "Is initialized equal to STL map value:" << std::endl;
        {
            ft::map<std::string, int> own;
            std::map<std::string, int> original;
            outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        }
    }
}