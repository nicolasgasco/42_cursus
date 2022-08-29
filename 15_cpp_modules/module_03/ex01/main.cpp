#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "ScavTrap with default constructor:" << std::endl;
    ScavTrap defaultTrap;
    std::cout << defaultTrap << std::endl;
    std::cout << defaultTrap << std::endl;

    std::cout << "ScavTrap with name:" << std::endl;
    ScavTrap namedTrap("Scavvy");
    std::cout << namedTrap << std::endl;
    namedTrap.guardGate();
    defaultTrap.attack(namedTrap.getName());
    namedTrap.takeDamage(defaultTrap.getAttackDamage());
    std::cout << defaultTrap << std::endl;
    std::cout << std::endl;

    return 0;
}
