#include "Zombie.hpp"

#include <iomanip>
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie(void) {
    std::cout << this->_name << " is dead (for real)" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}