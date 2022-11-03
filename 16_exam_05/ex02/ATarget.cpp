#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(void){};

ATarget::ATarget(std::string const &type) : type(type) {}

ATarget::ATarget(ATarget const &src) : type(src.type)
{
    *this = src;
}

ATarget::~ATarget(void) {}

ATarget const &ATarget::operator=(ATarget const &src)
{
    this->type = src.type;
    return *this;
}

std::string const &ATarget::getType(void) const
{
    return this->type;
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}