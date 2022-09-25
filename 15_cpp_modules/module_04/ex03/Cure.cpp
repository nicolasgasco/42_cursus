#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
    this->type = "cure";
    std::cout << CYAN << "Cure default constructor" << NOCOL << std::endl;
}

Cure::~Cure(void)
{
    std::cout << CYAN << "Cure destructor" << NOCOL << std::endl;
}

Cure::Cure(Cure const &src)
{
    this->type = "cure";
    *this = src;
    std::cout << CYAN << "Cure copy constructor called" << NOCOL << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
    std::cout << CYAN << "Cure assignation operator called (" << src.getType() << ")" << NOCOL << std::endl;
    return *this;
}

AMateria *Cure::clone(void) const
{
    std::cout << CYAN << "Cloning a new Cure Materia" << NOCOL << std::endl;
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << CYAN << "* heals " << (target.getName().length() ? target.getName() : "Unnamed") << "'s wounds *" << NOCOL << std::endl;
}
