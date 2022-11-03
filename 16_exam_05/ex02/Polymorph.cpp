#include "Polymorph.hpp"
#include "ATarget.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph(Polymorph const &src)
{
    *this = src;
}

Polymorph::~Polymorph(void) {}

Polymorph const &Polymorph::operator=(Polymorph const &src)
{
    this->name = src.name;
    this->effects = src.effects;
    return *this;
}

ASpell *Polymorph::clone(void) const
{
    return new Polymorph();
}