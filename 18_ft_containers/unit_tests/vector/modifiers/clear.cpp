#include "utils.hpp"
#include <vector>
#include "../../vector/Vector.hpp"

void clearUnitTests(bool isDebug)
{
    outputSuiteTitle("CLEAR");
    std::cout << "Size value is equal as STL vector:" << std::endl;
    {
        {
            ft::vector<int> own;
            own.clear();
            std::vector<int> original;
            original.clear();
            outputAssertion("with size = 0", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(1, 5);
            own.clear();
            std::vector<int> original(1, 5);
            original.clear();
            outputAssertion("with size = 1", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(10, 5);
            own.clear();
            std::vector<int> original(10, 5);
            original.clear();
            outputAssertion("with size = 10", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(100, 5);
            own.clear();
            std::vector<int> original(100, 5);
            original.clear();
            outputAssertion("with size = 100", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
    }

    std::cout << std::endl
              << "Capacity value is equal as STL vector:" << std::endl;
    {
        {
            ft::vector<int> own;
            own.clear();
            std::vector<int> original;
            original.clear();
            outputAssertion("with size = 0", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own(1, 5);
            own.clear();
            std::vector<int> original(1, 5);
            original.clear();
            outputAssertion("with size = 1", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own(10, 5);
            own.clear();
            std::vector<int> original(10, 5);
            original.clear();
            outputAssertion("with size = 10", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own(100, 5);
            own.clear();
            std::vector<int> original(100, 5);
            original.clear();
            outputAssertion("with size = 100", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
    }
}