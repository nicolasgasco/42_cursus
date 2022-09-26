#include "Data.hpp"
#include <iostream>

Data::Data(void) : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Data::Data(int value) : value(value)
{
    std::cout << "Default constructor called" << std::endl;
}

Data::Data(Data const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Data::~Data(void)
{
    std::cout << "Destructor called" << std::endl;
}

Data &Data::operator=(const Data &src)
{
    std::cout << "Assignation operator called" << std::endl;
    this->value = src.getValue();
    return *this;
}

Data::operator int(void)
{
    return static_cast<uintptr_t>(this->value);
}

int Data::getValue(void) const
{
    return (this->value);
}
