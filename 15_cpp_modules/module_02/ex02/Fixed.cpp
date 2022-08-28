#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#define EIGHT_ACTIVE_BITS 255
#define LEAST_SIGNIFICANT_FRACTION 0.0039625f

// Constructors
Fixed::Fixed(void) : _FixedPointValue(0) {}

Fixed::Fixed(int const intValue)
{
    this->_FixedPointValue = (intValue << this->_NUM_FRACT_BITS);
}

Fixed::Fixed(float const floatValue)
{
    this->_FixedPointValue = this->_floatToFixedPoint(floatValue);
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

// Destructor
Fixed::~Fixed(void) {}

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

// Assignment operator
Fixed &Fixed::operator=(const Fixed &src)
{
    this->_FixedPointValue = src.getRawBits();
    return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->_FixedPointValue > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->_FixedPointValue >= fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->_FixedPointValue < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->_FixedPointValue <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->_FixedPointValue == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->_FixedPointValue != fixed.getRawBits());
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &src) const
{
    return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const
{
    return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return (Fixed(this->toFloat() / src.toFloat()));
}

// Increment
Fixed Fixed::operator++(void)
{
    Fixed temp(this->toFloat());
    this->setRawBits(Fixed(this->toFloat() + 1.0f + LEAST_SIGNIFICANT_FRACTION).getRawBits());
    return (temp);
}

Fixed Fixed::operator++(int const)
{
    this->setRawBits(Fixed(this->toFloat() + 1.0f + LEAST_SIGNIFICANT_FRACTION).getRawBits());
    return (*this);
}

// Decrement
Fixed Fixed::operator--(void)
{
    Fixed temp(this->toFloat());
    this->setRawBits(Fixed(this->toFloat() - (1.0f + LEAST_SIGNIFICANT_FRACTION)).getRawBits());
    return (temp);
}

Fixed Fixed::operator--(int const)
{
    this->setRawBits(Fixed(this->toFloat() - (1.0f + LEAST_SIGNIFICANT_FRACTION)).getRawBits());
    return (*this);
}

// Min
Fixed &Fixed::min(Fixed &src1, Fixed &src2)
{
    return src1 < src2 ? src1 : src2;
}

Fixed const &Fixed::min(Fixed const &src1, Fixed const &src2)
{
    return src1 < src2 ? src1 : src2;
}

// Max
Fixed &Fixed::max(Fixed &src1, Fixed &src2)
{
    return src1 > src2 ? src1 : src2;
}

Fixed const &Fixed::max(Fixed const &src1, Fixed const &src2)
{
    return src1 > src2 ? src1 : src2;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, Fixed const &std)
{
    std::cout << std.toFloat();
    return os;
}
