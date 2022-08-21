#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__
#include <iostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(int const intValue);
    Fixed(float const floatValue);
    Fixed(Fixed const &src);

    ~Fixed(void);

    Fixed &operator=(const Fixed &fixed);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    static int const _NUM_FRACT_BITS = 8;
    int _FixedPointValue;
    int _numOfDecimals;

    int
    _floatToFixedPoint(float const floatValue);
};

std::ostream &operator<<(std::ostream &os, Fixed const &std);

#endif