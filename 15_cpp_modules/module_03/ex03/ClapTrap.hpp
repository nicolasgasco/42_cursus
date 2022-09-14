#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__
#include <iostream>
#define CYAN "\033[1;36m"
#define NOCOL "\033[0m"

class ClapTrap
{
public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &src);

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

#endif