#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__
#include <iostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(const int intValue);
    Fixed(const float floatValue);
    ~Fixed(void);
    Fixed(Fixed const &src);

    Fixed &operator=(const Fixed &fixed);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _FixedPointValue;
    static int const _NUM_FRACT_BITS = 8;
    int _numIntDigits;
    int _numFractDigits;

    int _calcNumIntDigits(int intNum);
    int _calcNumFractDigits(float floatNum);
    int _convertToFixedPointValue(float floatNum);
};

std::ostream &operator<<(std::ostream &os, Fixed const &std);

#endif