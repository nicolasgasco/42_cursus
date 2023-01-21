#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>

void incrementUnitTests(bool isDebug)
{
    outputSuiteTitle("INCREMENT");
    {
        std::cout << std::endl
                  << "Has same value of STL iterator:" << std::endl;
        {
            std::cout << std::endl
                      << "++ operator" << std::endl;
            {
                ft::map<std::string, int> own;
                own.insert(ft::pair<std::string, int>("one", 1));
                own.insert(ft::pair<std::string, int>("two", 2));

                std::map<std::string, int> original;
                original.insert(std::pair<std::string, int>("one", 1));
                original.insert(std::pair<std::string, int>("two", 2));

                outputAssertion("after inserting 2 elements and post-incrementing once:", isStrictEqual<std::string, int>(*(own.begin()++), *(original.begin()++), isDebug));
            }
            {
                ft::map<std::string, int> own;
                own.insert(ft::pair<std::string, int>("one", 1));
                own.insert(ft::pair<std::string, int>("two", 2));

                std::map<std::string, int> original;
                original.insert(std::pair<std::string, int>("one", 1));
                original.insert(std::pair<std::string, int>("two", 2));

                outputAssertion("after inserting 2 elements and pre-incrementing once:", isStrictEqual<std::string, int>(*(++own.begin()), *(++original.begin()), isDebug));
            }
        }
    }
}
