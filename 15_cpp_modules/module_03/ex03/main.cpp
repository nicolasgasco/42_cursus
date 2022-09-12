#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    DiamondTrap named("Diamondy");

    std::cout << named << std::endl;
    std::cout << std::endl;

    named.getAttackDamage();
    named.attack("Target");
    named.whoAmI();
    std::cout << std::endl;

    return (0);
}
