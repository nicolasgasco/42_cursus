#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "DiamondTrap with default constructor:" << std::endl;
    DiamondTrap defaultTrap;
    std::cout << defaultTrap << std::endl;

    std::cout << "DiamondTrap with name:" << std::endl;
    DiamondTrap *namedTrap = new DiamondTrap("Scavvy");
    std::cout << *namedTrap << std::endl;

    std::cout << "Copycat DiamondTrap (assignment operator):" << std::endl;
    DiamondTrap copyTrap;
    copyTrap = *namedTrap;
    std::cout << copyTrap << std::endl;

    std::cout << "Copycat DiamondTrap (copy constructor):" << std::endl;
    DiamondTrap copyTrap2(*namedTrap);
    std::cout << copyTrap2 << std::endl;

    std::cout << "Attack inherited by ScavTrap:" << std::endl;
    namedTrap->attack(defaultTrap.getName());
    defaultTrap.takeDamage(namedTrap->getAttackDamage());
    std::cout << *namedTrap << std::endl;

    std::cout << "Special inherited functions:" << std::endl;
    namedTrap->highFivesGuys();
    namedTrap->guardGate();
    std::cout << std::endl;

    std::cout << "whoAmI:" << std::endl;
    namedTrap->whoAmI();
    std::cout << std::endl;

    delete namedTrap;
    std::cout << std::endl;
    return 0;
}
