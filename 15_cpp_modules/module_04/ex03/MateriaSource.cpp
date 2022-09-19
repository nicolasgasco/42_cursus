#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << RED << "MateriaSource default constructor" << NOCOL << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    *this = src;
    std::cout << RED << "MateriaSource copy constructor called" << NOCOL << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << RED << "MateriaSource destructor" << NOCOL << std::endl;
    for (int i = 0; i < this->materiaNum; i++)
        delete this->materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    for (int i = 0; i < this->materiaNum; i++)
        this->materias[i] = src.materias[i];
    std::cout << RED << "MateriaSource assignation operator called" << NOCOL << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria *src)
{
    if (!src)
    {
        std::cout << RED << "MateriaSource tried to learn invalid Materia" << NOCOL << std::endl;
        return;
    }

    int i = 0;
    for (; i < this->materiaNum; i++)
    {
        if (!this->materias[i])
        {
            this->materias[i] = src;
            std::cout << RED << "MateriaSource learnt new Materia of type '" << src->getType() << "' at index " << i << NOCOL << std::endl;
            return;
        }
    }

    std::cout << RED << "No slot available to learn new Materia of type '" << src->getType() << "'" << NOCOL << std::endl;
    delete src;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < this->materiaNum; i++)
    {
        if (this->materias[i] && (this->materias[i]->getType() == type))
        {
            std::cout << RED << "MateriaSource createMateria(): created Materia of type '" << type << "'" << NOCOL << std::endl;
            return this->materias[i]->clone();
        }
    }
    std::cout << RED << "MateriaSource createMateria(): impossible to create Materia" << NOCOL << std::endl;
    return 0;
}