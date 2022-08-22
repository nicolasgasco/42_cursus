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

    std::cout << "\nciao " << this->_FixedPointValue << std::endl;
    int decimalPart = (float)(this->_FixedPointValue & EIGHT_ACTIVE_BITS);
    std::cout << "DecimalPart is " << decimalPart << std::endl;
    if (decimalPart == 0)
        return (integralPart);

    float decimalResult = 0.0f;
    for (int i = 1; i <= this->_NUM_FRACT_BITS; i++)
    {
        int bit = (decimalPart & (1 << (this->_NUM_FRACT_BITS - i))) >> (this->_NUM_FRACT_BITS - i);
        std::cout << "Bit is " << (bit) << std::endl;
        float multiplier = 2.0f;
        for (int x = 0; x <= i; x++)
        {
            multiplier /= 2.0f;
        }
        if (bit == 1)
            decimalResult += multiplier;
    }
    return (integralPart + decimalResult);
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
    int convertedIntegralPart = integralPart << this->_NUM_FRACT_BITS;
    // Do something for integral part
    std::cout << "ConvertedIntegralPart is " << convertedIntegralPart << std::endl;

    floatValueCopy -= (int)(floatValueCopy);
    std::cout << "floatValueCopy is " << floatValueCopy << std::endl;
    float divider = 2.0f;
    for (int i = 0; i < this->_NUM_FRACT_BITS; i++)
    {
        std::cout << "Bit position " << this->_NUM_FRACT_BITS - i << std::endl;
        std::cout << "Divider is " << divider << std::endl;
        float bitValue = (1.0 / divider);
        std::cout
            << "Bit value is " << bitValue << std::endl;
        std::cout << "FloatValueCopy is " << floatValueCopy << std::endl;
        float divisionResult = (((floatValueCopy) / bitValue));
        std::cout << "divisionResult is " << divisionResult << std::endl;
        if (divisionResult < 1)
        {
            std::cout << "Bit " << this->_NUM_FRACT_BITS - i << " is 0" << std::endl;
        }
        else
        {
            std::cout << "Bit " << this->_NUM_FRACT_BITS - i << " is 1" << std::endl;
            int bitPositionInt = 1;
            for (int x = 1; x < (this->_NUM_FRACT_BITS - i); x++)
                bitPositionInt *= 2;
            std::cout << "convertedIntegralPart is " << convertedIntegralPart << std::endl;
            convertedIntegralPart = convertedIntegralPart | bitPositionInt;
            std::cout << "convertedIntegralPart is " << convertedIntegralPart << std::endl;
            floatValueCopy -= bitValue;
        }
        std::cout << std::endl;
        divider *= 2.0f;
    }

    std::cout << std::endl;

    int numDecimals = 0;
    while (floatValueCopy != roundf(floatValueCopy))
    {
        floatValueCopy *= 10.0;
        integralPart *= 10;
        numDecimals++;
    }

    int convertedFloatPart = (int)(floatValueCopy - integralPart);
    // For numbers with higher decimal precision that 8 bits
    while (convertedFloatPart > EIGHT_ACTIVE_BITS)
    {
        convertedFloatPart /= 10;
        numDecimals--;
    }

    this->_numOfDecimals = numDecimals;
    return (convertedIntegralPart);
}

std::ostream &operator<<(std::ostream &os, Fixed const &std)
{
    std::cout << std.toFloat();
    return os;
}