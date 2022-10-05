#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy(void){};

Dummy *Dummy::clone(void)
{
    return (new Dummy(*this));
}