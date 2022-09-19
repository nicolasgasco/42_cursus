#ifndef __ICE_HPP__
#define __ICE_HPP__
#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"
#include <iostream>

#include "AMateria.hpp"

class Ice : virtual public AMateria
{
public:
    Ice(void);
    Ice(Ice const &src);

    ~Ice(void);

    Ice &operator=(Ice const &src);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};

#endif