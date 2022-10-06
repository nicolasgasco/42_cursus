#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
    Fwoosh(void);
    ~Fwoosh(void);
    virtual Fwoosh *clone(void);
};

#endif