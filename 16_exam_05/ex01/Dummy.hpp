#ifndef Dummy_HPP
#define Dummy_HPP

#include <iostream>

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
    Dummy(void);

    ATarget *clone(void) const;

    Dummy(Dummy const &src);
    Dummy const &operator=(Dummy const &src);
    ~Dummy(void);
};

#endif