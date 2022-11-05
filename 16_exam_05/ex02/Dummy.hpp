#pragma once

#include <iostream>

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
    Dummy(void);

    virtual ATarget *clone(void) const;

    Dummy(Dummy const &src);
    Dummy const &operator=(Dummy const &src);
    ~Dummy(void);
};
