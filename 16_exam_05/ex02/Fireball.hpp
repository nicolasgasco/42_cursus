#ifndef Fireball_HPP
#define Fireball_HPP

#include <iostream>

#include "ASpell.hpp"

class ATarget;

class Fireball : public ASpell
{
public:
    Fireball(void);

    ASpell *clone(void) const;

    Fireball(Fireball const &src);
    Fireball const &operator=(Fireball const &src);
    ~Fireball(void);
};

#endif