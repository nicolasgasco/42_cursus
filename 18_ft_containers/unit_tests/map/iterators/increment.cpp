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
                ft::map<std::string, int>::iterator ownIt = own.begin()++;

                std::map<std::string, int> original;
                original.insert(std::pair<std::string, int>("one", 1));
                original.insert(std::pair<std::string, int>("two", 2));
                std::map<std::string, int>::iterator originalIt = original.begin()++;

                outputAssertion("after post-incrementing once:", isStrictEqual<std::string, int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::map<std::string, int> own;
                own.insert(ft::pair<std::string, int>("one", 1));
                own.insert(ft::pair<std::string, int>("two", 2));
                ft::map<std::string, int>::iterator ownIt = ++own.begin();

                std::map<std::string, int> original;
                original.insert(std::pair<std::string, int>("one", 1));
                original.insert(std::pair<std::string, int>("two", 2));
                std::map<std::string, int>::iterator originalIt = ++original.begin();

                outputAssertion("after pre-incrementing once:", isStrictEqual<std::string, int>(*ownIt, *originalIt, isDebug));
            }
            {
                ft::map<std::string, int> own;
                own.insert(ft::pair<std::string, int>("one", 1));
                own.insert(ft::pair<std::string, int>("two", 2));
                own.insert(ft::pair<std::string, int>("three", 3));
                ft::map<std::string, int>::iterator ownIt = own.begin()++;
                ownIt++;


                std::map<std::string, int> original;
                original.insert(std::pair<std::string, int>("one", 1));
                original.insert(std::pair<std::string, int>("two", 2));
                original.insert(std::pair<std::string, int>("three", 3));
                std::map<std::string, int>::iterator originalIt = original.begin()++;
                originalIt++;

                outputAssertion("after post-incrementing twice:", isStrictEqual<std::string, int>(*ownIt, *originalIt, isDebug));
            }
            // {
            //     ft::map<std::string, int> own;
            //     own.insert(ft::pair<std::string, int>("one", 1));
            //     own.insert(ft::pair<std::string, int>("two", 2));
            //     own.insert(ft::pair<std::string, int>("three", 3));
            //     ft::map<std::string, int>::iterator ownIt = ++own.begin();

            //     std::map<std::string, int> original;
            //     original.insert(std::pair<std::string, int>("one", 1));
            //     original.insert(std::pair<std::string, int>("two", 2));
            //     original.insert(std::pair<std::string, int>("three", 3));
            //     std::map<std::string, int>::iterator originalIt = ++original.begin();

            //     outputAssertion("after pre-incrementing twice:", isStrictEqual<std::string, int>(*(++ownIt), *(++originalIt), isDebug));
            // }
        }
    }
}
