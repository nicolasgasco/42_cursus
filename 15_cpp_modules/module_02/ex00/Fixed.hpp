#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed
{
public:
    Fixed(void);
    Fixed(Fixed const &src);
    ~Fixed(void);

    Fixed &operator=(const Fixed &src);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _FixedPointValue;
    static int const _NUM_FRACT_BITS = 8;
};

#endif