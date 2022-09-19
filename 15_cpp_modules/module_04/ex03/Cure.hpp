#ifndef __CURE_HPP__
#define __CURE_HPP__
#define CYAN "\033[0;36m"
#define NOCOL "\033[0m"
#include <iostream>

#include "AMateria.hpp"

class Cure : virtual public AMateria
{
public:
    Cure(void);
    Cure(Cure const &src);

    ~Cure(void);

    Cure &operator=(Cure const &src);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};

#endif