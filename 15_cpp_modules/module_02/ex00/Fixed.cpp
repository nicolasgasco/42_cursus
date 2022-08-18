#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    this->_FixedPointValue = src._FixedPointValue;
    std::cout << "Copy constructor called" << std::endl;
    this->getRawBits();
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    this->_FixedPointValue = fixed._FixedPointValue;
    std::cout << "Assignation operator called" << std::endl;
    this->getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_FixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_FixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}
