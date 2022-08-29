#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(void);
    ScavTrap(std::string name);

    ~ScavTrap(void);

    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void guardGate(void) const;
};

#endif