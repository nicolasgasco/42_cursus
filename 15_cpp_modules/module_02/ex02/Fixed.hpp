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

    // Assignation
    Fixed &operator=(const Fixed &fixed);

    // Comparison
    bool operator>(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;

    // Arithmetic
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

    // Increment / Decrement
    Fixed operator++(void);
    Fixed operator++(int const);
    Fixed operator--(void);
    Fixed operator--(int const);

    // Min / max
    static Fixed &min(Fixed &src1, Fixed &src2);
    static Fixed const &min(Fixed const &src1, Fixed const &src2);
    static Fixed &max(Fixed &src1, Fixed &src2);
    static Fixed const &max(Fixed const &src1, Fixed const &src2);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    static int const _NUM_FRACT_BITS = 8;
    int _FixedPointValue;

    int
    _floatToFixedPoint(float const floatValue);
};

std::ostream &operator<<(std::ostream &os, Fixed const &std);

#endif