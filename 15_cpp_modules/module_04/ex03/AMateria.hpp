#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__
#define GREEN "\033[0;32m"
#define NOCOL "\033[0m"
#include <iostream>

class ICharacter;

class AMateria
{
public:
    AMateria(void);
    AMateria(std::string const &type);
    AMateria(AMateria const &src);
    virtual ~AMateria(void);

    AMateria &operator=(AMateria const &src);

    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter &target);

    std::string const &getType(void) const;

protected:
    std::string type;
};

#endif