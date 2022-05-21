#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}
HumanA::~HumanA(void)
{
}
void HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
