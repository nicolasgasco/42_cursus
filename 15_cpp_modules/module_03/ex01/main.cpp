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

    std::cout << "Copycat ScavTrap (assignment operator):" << std::endl;
    ScavTrap copyTrap;
    copyTrap = *namedTrap;
    std::cout << copyTrap << std::endl;

    std::cout << "Copycat ScavTrap (copy constructor):" << std::endl;
    ScavTrap copyTrap2(copyTrap);
    std::cout << copyTrap2 << std::endl;

    defaultTrap.attack(namedTrap->getName());
    namedTrap->takeDamage(defaultTrap.getAttackDamage());
    std::cout << *namedTrap << std::endl;

    namedTrap->beRepaired(10);
    std::cout << *namedTrap << std::endl;

    namedTrap->guardGate();
    std::cout << std::endl;

    delete namedTrap;
    std::cout << std::endl;
    return 0;
}
