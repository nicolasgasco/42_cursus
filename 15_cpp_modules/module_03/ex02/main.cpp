#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap unnamed;
    std::cout << unnamed << std::endl;

    FragTrap named("Fraggy");
    std::cout << unnamed << std::endl;

    named.highFivesGuys();
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}
