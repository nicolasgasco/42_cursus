#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#define YELLOW "\033[1;33m"
#define NOCOL "\033[0m"
#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : virtual public ICharacter
{
public:
    Character(void);
    Character(std::string const &type);
    Character(Character const &src);

    ~Character(void);

    Character &operator=(Character const &src);

    std::string const &getName(void) const;
    // virtual void equip(AMateria *m) = 0;
    // virtual void unequip(int idx) = 0;
    // virtual void use(int idx, ICharacter &target) = 0;

private:
    std::string name;
    static int const materiaNum = 4;
    AMateria *inventory[materiaNum];
};

#endif