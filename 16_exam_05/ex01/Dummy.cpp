#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {}

Dummy::Dummy(Dummy const &src)
{
    *this = src;
}

Dummy const &Dummy::operator=(Dummy const &src)
{
    this->type = src.type;
    return *this;
}

Dummy::~Dummy(void) {}

ATarget *Dummy::clone(void) const
{
    return new Dummy();
}