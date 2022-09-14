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

    std::cout << "Copycat ScavTrap:" << std::endl;
    ScavTrap copyTrap;
    copyTrap = *namedTrap;
    std::cout << copyTrap << std::endl;

    defaultTrap.attack(namedTrap->getName());
    namedTrap->takeDamage(defaultTrap.getAttackDamage());
    std::cout << *namedTrap << std::endl;

    copyTrap.beRepaired(10);
    std::cout << copyTrap << std::endl;

    namedTrap->guardGate();
    std::cout << std::endl;

    delete namedTrap;
    std::cout << std::endl;
    return 0;
}
