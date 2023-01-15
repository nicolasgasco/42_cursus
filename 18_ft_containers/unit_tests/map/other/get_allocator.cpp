#include "../../utils.hpp"
#include "../../../map.hpp"
#include <map>

void getAllocatorUnitTests()
{
    outputSuiteTitle("GET_ALLOCATOR");
    // Allocator type
    std::cout << "Allocator type strictly equal to STL map value:" << std::endl;
    {
        ft::map<std::string, int> own;
        std::map<std::string, int> original;
        outputAssertion("when initialized with empty constructor:", isStrictEqual<std::allocator<ft::pair<const std::string, int> > >(own.get_allocator(), original.get_allocator()));
    }
    {
        std::allocator<ft::pair<const std::string, int> > alloc = std::allocator<ft::pair<const std::string, int> >();
        std::less<std::string> comp = std::less<std::string>();
        ft::map<std::string, int> own(comp, alloc);
        std::map<std::string, int> original(comp, alloc);
        outputAssertion("when initialized with empty constructor (custom allocator):", isStrictEqual<std::allocator<int> >(own.get_allocator(), original.get_allocator()));
    }
}
