#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

class Weapon
{
public:
    Weapon(void);
    Weapon(std::string type);
    ~Weapon(void);

    std::string const &getType(void) const;
    void setType(std::string type);

private:
    std::string _type;
};

#endif
