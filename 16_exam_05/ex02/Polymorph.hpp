#ifndef Polymorph_HPP
#define Polymorph_HPP

#include <iostream>

#include "ASpell.hpp"

class ATarget;

class Polymorph : public ASpell
{
public:
    Polymorph(void);

    virtual ASpell *clone(void) const;

    Polymorph(Polymorph const &src);
    Polymorph const &operator=(Polymorph const &src);
    ~Polymorph(void);
};

#endif