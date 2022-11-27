#include <string>
#include <iostream>

#define YELLOW "\033[0;33m"
#define NOCOL "\033[0m"

void outputAssertion(std::string description, bool value)
{
    std::cout << "  - " << description << " " << ((value == true) ? "✅" : "❌") << std::endl;
}

template <typename T>
bool isStrictEqual(T value, T reference, bool printValue)
{
    if (printValue)
        std::cout << " (" << value << ", " << reference << ")" << std::endl;
    return (value == reference) ? true : false;
}

template <typename T, typename V>
T returnPopulatedVector(int numOfEls, V value)
{
    T vector;
    for (int i = 0; i < numOfEls; ++i)
        vector.push_back(value);
    return vector;
}
