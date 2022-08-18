#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _FixedPointValue(0), _numFractDigits(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) : _FixedPointValue(intValue), _numFractDigits(0)
{
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
{
    this->_numIntDigits = this->_calcNumIntDigits(floatValue);
    this->_numFractDigits = this->_calcNumFractDigits(floatValue);
    this->_FixedPointValue = this->_convertToFixedPointValue(floatValue);
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    this->_FixedPointValue = src._FixedPointValue;
    this->_numIntDigits = src._numIntDigits;
    this->_numFractDigits = src._numFractDigits;
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    this->_FixedPointValue = rhs._FixedPointValue;
    this->_numIntDigits = rhs._numIntDigits;
    this->_numFractDigits = rhs._numFractDigits;
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    std::cout << "+ operator called" << std::endl;
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    std::cout << "- operator called" << std::endl;
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    std::cout << "* operator called" << std::endl;
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    std::cout << "* operator called" << std::endl;
    return Fixed(this->toFloat() / rhs.toFloat());
}

float Fixed::toFloat(void) const
{
    float result = (float)this->_FixedPointValue;
    for (int i = 0; i < this->_numFractDigits; i++)
    {
        result /= 10;
    }
    return (result);
}

int Fixed::toInt(void) const
{
    int result = this->_FixedPointValue;
    for (int i = 0; i < this->_numFractDigits; i++)
    {
        result /= 10;
    }
    return (result);
}

int Fixed::_calcNumIntDigits(int intNum)
{
    int i;
    for (i = 0; intNum != 0; i++)
    {
        intNum /= 10;
    }
    return (i);
}

int Fixed::_calcNumFractDigits(float floatNum)
{
    float num = floatNum;
    int i = 0;
    while (true)
    {
        if (((num - roundf(num)) * 10) <= 1)
        {
            i++;
            break;
        }
        num *= 10;
        i++;
    }
    return (i);
}

int Fixed::_convertToFixedPointValue(const float floatNum)
{
    float result = floatNum;
    for (int i = 0; i < this->_numIntDigits; i++)
    {
        result *= 10;
    }
    return (roundf(result));
}

std::ostream &operator<<(std::ostream &os, Fixed const &std)
{
    std::cout << std.toFloat();
    return os;
}