#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
void easyfind(T container, int value)
{
    typename T::iterator foundIt = std::find(container.begin(), container.end(), value);

    if (foundIt == container.end())
        throw("Index value out of bound");

    std::cout << "Found value " << value << " at index " << std::distance(container.begin(), foundIt) << std::endl;
}
#endif