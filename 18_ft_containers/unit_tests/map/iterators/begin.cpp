#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>

void beginUnitTests(bool isDebug)
{
    outputSuiteTitle("BEGIN");
    {
        std::cout << "Is const/ not const like STL iterator value:" << std::endl;
        {
            ft::map<std::string, int> own;
            own.insert(ft::pair<std::string, int>("one", 1));
            ft::map<std::string, int>::iterator ownIt = own.begin();

            std::cout << typeid(ownIt).name() << std::endl;
            outputAssertion("is not const with ::iterator:", !strcmp(typeid(ownIt).name(), "N2ft12map_iteratorINS_8bst_nodeINSt3__112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEiNS_4pairIS8_iEENS6_ISA_EEEEEE"));
        }
        {
            ft::map<std::string, int> seed;
            seed.insert(ft::pair<std::string, int>("one", 1));
            ft::map<std::string, int> const own = const_cast<ft::map<std::string, int> const &>(seed);
            ft::map<std::string, int>::const_iterator ownIt = own.begin();

            std::cout << typeid(ownIt).name() << std::endl;
            outputAssertion("is const with ::const_iterator:", !strcmp(typeid(ownIt).name(), "N2ft12map_iteratorIKNS_8bst_nodeINSt3__112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEiNS_4pairIS8_iEENS6_ISA_EEEEEE"));
        }
    }
    {
        std::cout << std::endl
                  << "Has same value of STL iterator value:" << std::endl;
        // {
        //     // TODO test this
        //     ft::map<std::string, int> own;

        //     std::map<std::string, int> original;

        //     outputAssertion("when no element is inserted:", isStrictEqual<std::string, int>(*(own.begin()), *(original.begin()), isDebug));
        // }
        {
            ft::map<std::string, int> own;
            own.insert(ft::pair<std::string, int>("one", 1));

            std::map<std::string, int> original;
            original.insert(std::pair<std::string, int>("one", 1));

            outputAssertion("after inserting 1 element:", isStrictEqual<std::string, int>(*(own.begin()), *(original.begin()), isDebug));
        }
        {
            ft::map<std::string, int> own;
            own.insert(ft::pair<std::string, int>("one", 1));
            own.insert(ft::pair<std::string, int>("two", 2));

            std::map<std::string, int> original;
            original.insert(std::pair<std::string, int>("one", 1));
            original.insert(std::pair<std::string, int>("two", 2));

            outputAssertion("after inserting 2 elements:", isStrictEqual<std::string, int>(*(own.begin()), *(original.begin()), isDebug));
        }
        {
            ft::map<std::string, int> own;
            own.insert(ft::pair<std::string, int>("one", 1));
            own.insert(ft::pair<std::string, int>("two", 2));
            own.insert(ft::pair<std::string, int>("three", 3));

            std::map<std::string, int> original;
            original.insert(std::pair<std::string, int>("one", 1));
            original.insert(std::pair<std::string, int>("two", 2));
            original.insert(std::pair<std::string, int>("three", 3));

            outputAssertion("after inserting 3 elements:", isStrictEqual<std::string, int>(*(own.begin()), *(original.begin()), isDebug));
        }
        {
            ft::map<std::string, int> own;
            own.insert(ft::pair<std::string, int>("one", 1));
            own.insert(ft::pair<std::string, int>("two", 2));

            std::map<std::string, int> original;
            original.insert(std::pair<std::string, int>("one", 1));
            original.insert(std::pair<std::string, int>("two", 2));

            outputAssertion("after inserting 2 elements and post-decrementing once:", isStrictEqual<std::string, int>(*(own.begin()++), *(original.begin()++), isDebug));
        }
        {
            ft::map<std::string, int> own;
            own.insert(ft::pair<std::string, int>("one", 1));
            own.insert(ft::pair<std::string, int>("two", 2));

            std::map<std::string, int> original;
            original.insert(std::pair<std::string, int>("one", 1));
            original.insert(std::pair<std::string, int>("two", 2));

            outputAssertion("after inserting 2 elements and pre-decrementing once:", isStrictEqual<std::string, int>(*(++own.begin()), *(++original.begin()), isDebug));
        }
    }
}
