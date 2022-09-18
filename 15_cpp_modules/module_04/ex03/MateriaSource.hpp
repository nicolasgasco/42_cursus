#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__
#define RED "\033[31;1m"
#define NOCOL "\033[0m"

#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : virtual public IMateriaSource
{
public:
    MateriaSource(void);
    MateriaSource(MateriaSource const &src);

    ~MateriaSource(void);

    MateriaSource &operator=(MateriaSource const &src);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);

private:
    static int const materiaNum = 4;
    AMateria *materias[materiaNum];
};

#endif