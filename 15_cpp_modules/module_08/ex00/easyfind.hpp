#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
void easyfind(T container, int value)
{
    typename T::iterator startIt = container.begin();
    typename T::iterator endIt = container.end();

    typename T::iterator foundIt = std::find(startIt, endIt, value);

    if (foundIt == endIt)
        throw("Index value out of bound");

    std::cout << "Found value " << value << " at index " << std::distance(startIt, foundIt) << std::endl;
}
#endif