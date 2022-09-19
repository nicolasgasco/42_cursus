#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__
#define YELLOW "\033[1;33m"
#define NOCOL "\033[0m"
#include <iostream>

#include "ICharacter.hpp"

class Character : virtual public ICharacter
{
public:
    Character(void);
    Character(std::string const &name);
    Character(Character const &src);

    ~Character(void);

    Character &operator=(Character const &src);

    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

    std::string const &getName(void) const;

    void outputInventoryAddress(void) const;

private:
    std::string name;
    static int const materiaNum = 4;
    AMateria *inventory[materiaNum];
};

#endif