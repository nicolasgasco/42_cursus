#include "Fireball.hpp"
#include "ATarget.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp")
{
    std::cout << "Creating new Fireball: " << this->name << ", " << this->effects << std::endl;
}

Fireball::Fireball(Fireball const &src)
{
    *this = src;
}

Fireball::~Fireball(void) {}

Fireball const &Fireball::operator=(Fireball const &src)
{
    this->name = src.name;
    this->effects = src.effects;
    return *this;
}

ASpell *Fireball::clone(void) const
{
    return new Fireball();
}