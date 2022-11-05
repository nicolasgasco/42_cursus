#pragma once

#include <iostream>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
    Fwoosh(void);

    virtual ASpell *clone(void) const;

    Fwoosh(Fwoosh const &src);
    Fwoosh const &operator=(Fwoosh const &src);
    ~Fwoosh(void);
};
