#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#define EIGHT_ACTIVE_BITS 255

Fixed::Fixed(void) : _FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const intValue) : _FixedPointValue(intValue)
{
    this->_FixedPointValue = (intValue << this->_NUM_FRACT_BITS);
    std::cout
        << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->_FixedPointValue = this->_floatToFixedPoint(floatValue);
    std::cout << "Fixed point value is " << this->_FixedPointValue << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_FixedPointValue = src.getRawBits();
    this->_numOfDecimals = src._numOfDecimals;
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

float Fixed::toFloat(void) const
{
    float integralPart = this->toInt();

    float decimalPart = (float)(this->_FixedPointValue & EIGHT_ACTIVE_BITS);
    if (decimalPart == 0)
        return (integralPart);

    for (int i = 0; i < this->_numOfDecimals; i++)
        decimalPart /= 10;
    return (integralPart + decimalPart);
}

int Fixed::toInt(void) const
{
    int integralPart = this->_FixedPointValue >> this->_NUM_FRACT_BITS;
    return (integralPart);
}

int Fixed::_floatToFixedPoint(float const floatValue)
{
    float floatValueCopy = floatValue;

    int integralPart = (int)floatValue;
    int numDecimals = 0;
    while (floatValueCopy != roundf(floatValueCopy))
    {
        floatValueCopy *= 10.0;
        integralPart *= 10;
        numDecimals++;
    }

    int convertedIntegralPart = (int)roundf(floatValue) << this->_NUM_FRACT_BITS;
    // Do something for integral part

    int convertedFloatPart = (int)(floatValueCopy - integralPart);
    // For numbers with higher decimal precision that 8 bits
    while (convertedFloatPart > EIGHT_ACTIVE_BITS)
    {
        convertedFloatPart /= 10;
        numDecimals--;
    }

    this->_numOfDecimals = numDecimals;
    return (convertedIntegralPart + convertedFloatPart);
}

std::ostream &operator<<(std::ostream &os, Fixed const &std)
{
    std::cout << std.toFloat();
    return os;
}