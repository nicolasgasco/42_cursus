#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>

void insertUnitTests(bool isDebug)
{
    outputSuiteTitle("INSERT");
    std::cout << "Deferenced return value is equal to STL map:" << std::endl;
    {
        {
            std::cout << "  SINGLE ELEMENT" << std::endl;
            {
                ft::map<std::string, int> own;
                ft::pair<std::string, int> ownPair("one", 1);
                ft::pair<ft::map<std::string, int>::iterator, bool> ownRes = own.insert(ownPair);

                std::map<std::string, int> original;
                std::pair<std::string, int> originalPair("one", 1);
                std::pair<std::map<std::string, int>::iterator, bool> originalRes = original.insert(originalPair);

                outputAssertion("after inserting 1 value in a map with size 0:", isStrictEqual<std::string, int>(*(ownRes.first), *(originalRes.first), isDebug));
            }
        }
    }
}