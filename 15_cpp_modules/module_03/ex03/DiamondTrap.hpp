#pragma once
#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    DiamondTrap(void);
    DiamondTrap(std::string name);

    ~DiamondTrap(void);

    DiamondTrap &operator=(DiamondTrap const &src);

    std::string getName(void) const;
    void whoAmI(void) const;

private:
    std::string Name;
};

#endif