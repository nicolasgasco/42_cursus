#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class IndexOutOfBound : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return ("Index value out of bound");
    }
};

template <typename T>
void easyfind(T container, int value)
{
    typename T::iterator startIt = container.begin();
    typename T::iterator endIt = container.end();
    typename T::iterator foundIt = std::find(startIt, endIt, value);

    if (foundIt == endIt)
        throw IndexOutOfBound();

    std::cout << "Found value " << value << " at index " << std::distance(startIt, foundIt) << std::endl;
}
#endif