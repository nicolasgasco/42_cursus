#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "ScavTrap with default constructor:" << std::endl;
    ScavTrap defaultTrap;
    std::cout << defaultTrap << std::endl;

    std::cout << "ScavTrap with name:" << std::endl;
    ScavTrap *namedTrap = new ScavTrap("Scavvy");
    std::cout << *namedTrap << std::endl;

    namedTrap->guardGate();
    std::cout << std::endl;

    defaultTrap.attack(namedTrap->getName());
    namedTrap->takeDamage(defaultTrap.getAttackDamage());

    std::cout << *namedTrap << std::endl;
    std::cout << std::endl;

    std::cout << "Copycat ScavTrap:" << std::endl;
    ScavTrap copyTrap;
    copyTrap = *namedTrap;
    std::cout << std::endl;

    delete namedTrap;
    return 0;
}
