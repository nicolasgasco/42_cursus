#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy")
{
    std::cout << "Creating new Dummy: " << this->type << std::endl;
}

Dummy::Dummy(Dummy const &src)
{
    *this = src;
}

Dummy::~Dummy(void) {}

Dummy const &Dummy::operator=(Dummy const &src)
{
    this->type = src.type;
    return *this;
}

ATarget *Dummy::clone(void) const
{
    return new Dummy();
}