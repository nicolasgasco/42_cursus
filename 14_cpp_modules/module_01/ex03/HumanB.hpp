#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"
#include <iostream>

class HumanB
{

public:
    HumanB(std::string name);
    HumanB(std::string name, Weapon &weapon);
    ~HumanB(void);

    void attack(void) const;
    void setWeapon(Weapon &weapon);

private:
    std::string _name;
    Weapon *_weapon;
};

#endif