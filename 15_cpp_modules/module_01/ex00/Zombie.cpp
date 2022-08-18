#include "Zombie.hpp"

#include <iomanip>
#include <iostream>

Zombie::Zombie(void)
{
    std::cout << "Zombie initialized without name" << std::endl;
    return;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << name << " initialized" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " is dead (for real)" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}
