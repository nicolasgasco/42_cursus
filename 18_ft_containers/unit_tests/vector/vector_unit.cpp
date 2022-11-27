
#include <iostream>

#include <vector>
#include "../../vector/Vector.hpp"

#include "utils.hpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    std::cout << YELLOW << "VECTOR UNIT TESTS" << NOCOL << std::endl;

    /*
     * SIZE
     */
    std::cout << YELLOW << "Size" << NOCOL << std::endl;
    std::cout << "Is strictly equal to STL vector value:" << std::endl;
    {
        ft::vector<int> own;
        std::vector<int> original;
        outputAssertion("when empty:", isStrictEqual<int>(own.size(), original.size(), IS_DEBUG));
    }
    {
        std::vector<int> original = returnPopulatedVector<std::vector<int>, int>(1, 1);
        outputAssertion("when populated with 1 int:", isStrictEqual<int>(0, original.size(), IS_DEBUG));
    }
    {
        std::vector<int> original = returnPopulatedVector<std::vector<int>, int>(3, 1);
        outputAssertion("when populated with 3 int:", isStrictEqual<int>(0, original.size(), IS_DEBUG));
    }
    // Should be 3
    // Should be 100
    // Should be 99
    return (0);
}