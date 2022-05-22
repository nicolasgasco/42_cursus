#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"
#include <iostream>

class HumanA
{

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);

    void attack(void) const;

private:
    std::string _name;
    Weapon &_weapon;
};

#endif