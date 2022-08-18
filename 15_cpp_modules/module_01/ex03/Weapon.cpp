#include "Weapon.hpp"

#include <iomanip>
#include <iostream>

Weapon::Weapon(void)
{
}
Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

std::string const &Weapon::getType(void) const
{
    const std::string &typeRef = this->_type;
    return typeRef;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
