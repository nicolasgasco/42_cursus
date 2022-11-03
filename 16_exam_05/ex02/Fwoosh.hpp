#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>

#include "ASpell.hpp"

class ATarget;

class Fwoosh : public ASpell
{
public:
    Fwoosh(void);

    ASpell *clone(void) const;

    Fwoosh(Fwoosh const &src);
    Fwoosh const &operator=(Fwoosh const &src);
    ~Fwoosh(void);
};

#endif