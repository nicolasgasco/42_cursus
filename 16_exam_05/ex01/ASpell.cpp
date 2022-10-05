#include "ASpell.hpp"

ASpell::ASpell(void) {}
ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects) {}
ASpell::ASpell(ASpell const &src) : name(src.name), effects(src.effects)
{
    *this = src;
}

ASpell::~ASpell(void) {}

ASpell const &ASpell::operator=(ASpell const &src)
{
    if (src.name.length() && src.effects.length())
    {
        // Continue
    }
    return *this;
}

std::string const &ASpell::getName(void) const
{
    return this->name;
}
std::string const &ASpell::getEffects(void) const
{
    return this->effects;
}

void ASpell::launch(ATarget const &target)
{
    target.getHitBySpell(const_cast<ASpell const &>(*this));
}
