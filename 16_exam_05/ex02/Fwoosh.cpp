#include "Fwoosh.hpp"
#include "ATarget.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed")
{
    std::cout << "Creating new Fwoosh: " << this->name << ", " << this->effects << std::endl;
}

Fwoosh::Fwoosh(Fwoosh const &src)
{
    *this = src;
}

Fwoosh::~Fwoosh(void) {}

Fwoosh const &Fwoosh::operator=(Fwoosh const &src)
{
    this->name = src.name;
    this->effects = src.effects;
    return *this;
}

ASpell *Fwoosh::clone(void) const
{
    return new Fwoosh();
}