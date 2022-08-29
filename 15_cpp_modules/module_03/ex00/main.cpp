#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "ClapTrap with default constructor:" << std::endl;
    ClapTrap defaultTrap;
    std::cout << defaultTrap << std::endl;

    std::cout << "ClapTrap with name:" << std::endl;
    ClapTrap namedTrap("Clappy");
    std::cout << namedTrap << std::endl;

    std::cout << "Copycat ClapTrap:" << std::endl;
    ClapTrap copycat;
    copycat = namedTrap;
    std::cout << copycat << std::endl;

    defaultTrap.attack(namedTrap.getName());
    namedTrap.takeDamage(defaultTrap.getAttackDamage());
    std::cout << namedTrap << std::endl;

    std::cout << "One potion later..." << std::endl;
    namedTrap.beRepaired(10);
    std::cout << namedTrap << std::endl;

    std::cout << "Copycat name is... " << copycat.getName() << std::endl;
    std::cout << copycat << std::endl;
    std::cout << std::endl;

    return 0;
}
