#include "Data.hpp"
#include <iostream>

Data::Data(void) : value(0)
{
}

Data::Data(int value) : value(value)
{
}

Data::Data(Data const &src)
{
    *this = src;
}

Data::~Data(void)
{
}

Data &Data::operator=(const Data &src)
{
    this->value = src.getValue();
    return *this;
}

int Data::getValue(void) const
{
    return (this->value);
}
