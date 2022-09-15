#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "FragTrap with default constructor:" << std::endl;
    FragTrap defaultTrap;
    std::cout << defaultTrap << std::endl;

    std::cout << "FragTrap with name:" << std::endl;
    FragTrap *namedTrap = new FragTrap("Fraggy");
    std::cout << *namedTrap << std::endl;

    std::cout << "Copycat FragTrap (assignment operator):" << std::endl;
    FragTrap copyTrap;
    copyTrap = *namedTrap;
    std::cout << copyTrap << std::endl;

    std::cout << "Copycat FragTrap (copy constructor):" << std::endl;
    FragTrap copyTrap2(*namedTrap);
    std::cout << copyTrap2 << std::endl;

    defaultTrap.attack(namedTrap->getName());
    namedTrap->takeDamage(defaultTrap.getAttackDamage());
    std::cout << *namedTrap << std::endl;

    namedTrap->beRepaired(10);
    std::cout << *namedTrap << std::endl;

    namedTrap->highFivesGuys();
    std::cout << std::endl;

    delete namedTrap;
    std::cout << std::endl;
    return 0;
}
