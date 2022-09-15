#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__
#include <iostream>
#include "ClapTrap.hpp"
#define BLUE "\033[1;34m"
#define NOCOL "\033[0m"

class FragTrap : public ClapTrap
{
public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap &src);

    ~FragTrap(void);

    FragTrap &operator=(FragTrap const &src);

    using ClapTrap::attack;
    using ClapTrap::beRepaired;
    using ClapTrap::takeDamage;

    void highFivesGuys(void) const;

private:
    using ClapTrap::AttackDamage;
    using ClapTrap::EnergyPoints;
    using ClapTrap::Hitpoints;
    using ClapTrap::Name;
};

#endif