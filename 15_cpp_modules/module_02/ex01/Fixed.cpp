#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#define EIGHT_ACTIVE_BITS 255

// Constructors
Fixed::Fixed(void) : _FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const intValue)
{
    this->_FixedPointValue = (intValue << this->_NUM_FRACT_BITS);
    std::cout
        << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatValue)
{
    this->_FixedPointValue = this->_floatToFixedPoint(floatValue);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &src)
{
    this->_FixedPointValue = src.getRawBits();
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

// Getter/Setter
int Fixed::getRawBits(void) const
{
    return (this->_FixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_FixedPointValue = raw;
}

// Conversion
float Fixed::toFloat(void) const
{
    float integralPart = (float)this->toInt();
    int fractionalFixedPointPart = (float)(this->_FixedPointValue & EIGHT_ACTIVE_BITS);
    if (fractionalFixedPointPart == 0)
        return (integralPart);

    float fractionResult = 0.0f;
    fractionResult += 1.0f;
    for (int i = 1; i <= this->_NUM_FRACT_BITS; i++)
    {
        int currentBitPosition = this->_NUM_FRACT_BITS - i;
        int bitDecimalValue = 1 << currentBitPosition;
        int bitBinaryValue = (fractionalFixedPointPart & bitDecimalValue) >> currentBitPosition;

        float multiplier = 2.0f;
        for (int x = 0; x <= i; x++)
            multiplier /= 2.0f;

        if (bitBinaryValue == 1)
            fractionResult += multiplier;
    }
    float result = integralPart + fractionResult;
    result -= 1.0f;
    return (result);
}

int Fixed::toInt(void) const
{
    int integralPart = this->_FixedPointValue >> this->_NUM_FRACT_BITS;
    return (integralPart);
}

int Fixed::_floatToFixedPoint(float const floatValue)
{
    int fixedPointResult = 0;

    int integralPart = (int)floatValue;
    fixedPointResult += (integralPart << this->_NUM_FRACT_BITS);

    float fractionalPart = floatValue - (int)floatValue;

    float divider = 2.0f;
    for (int i = 0; i < this->_NUM_FRACT_BITS; i++)
    {
        float bitFractionValue = (1.0 / divider);
        bool isBitActivated = (fractionalPart / bitFractionValue) >= 1.0f;
        if (isBitActivated)
        {
            int bitDecimalValue = (1 << (this->_NUM_FRACT_BITS - i - 1));
            fixedPointResult |= bitDecimalValue;
            fractionalPart -= bitFractionValue;
        }
        divider *= 2.0f;
    }
    return (fixedPointResult);
}

// stream overload
std::ostream &operator<<(std::ostream &os, Fixed const &std)
{
    std::cout << std.toFloat();
    return os;
}