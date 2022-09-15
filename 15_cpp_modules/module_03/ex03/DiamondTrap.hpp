#pragma once
#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &src);

    ~DiamondTrap(void);

    DiamondTrap &operator=(DiamondTrap const &src);

    std::string getName(void) const;
    void whoAmI(void) const;

    using ScavTrap::attack;

    using FragTrap::highFivesGuys;
    using ScavTrap::guardGate;

private:
    std::string Name;

    using ClapTrap::AttackDamage;
    using ClapTrap::EnergyPoints;
    using ClapTrap::Hitpoints;
};

std::ostream &operator<<(std::ostream &os, DiamondTrap const &std);

#endif