#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>
#include <vector>

void maxSizeUnitTests(bool isDebug)
{
    outputSuiteTitle("MAX SIZE");

    if (isDebug)
    {
        // TODO fix max_size
    }
    {
        std::cout << "Is initialized equal to STL map value:" << std::endl;
        // {
        //     ft::map<std::string, int> own;
        //     std::map<std::string, int> original;

        //     outputAssertion("with std::string, int:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        // }
        // {
        //     ft::map<char, int> own;
        //     std::map<char, int> original;

        //     outputAssertion("with <char, int >:", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
        // }
    }
}