#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__
#include <iostream>

class ClapTrap
{
public:
    ClapTrap(void);
    ClapTrap(std::string name);

    ~ClapTrap(void);

    ClapTrap &operator=(const ClapTrap &src);

    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;

protected:
    std::string Name;
    int Hitpoints;
    int EnergyPoints;
    int AttackDamage;
};

std::ostream &operator<<(std::ostream &os, ClapTrap const &std);

#endif