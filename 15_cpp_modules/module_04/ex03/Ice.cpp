#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void)
{
    this->type = "ice";
    std::cout << PURPLE << "Ice default constructor" << NOCOL << std::endl;
}

Ice::~Ice(void)
{
    std::cout << PURPLE << "Ice destructor" << NOCOL << std::endl;
}

Ice::Ice(Ice const &src)
{
    this->type = "ice";
    *this = src;
    std::cout << PURPLE << "Ice copy constructor called" << NOCOL << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
    std::cout << PURPLE << "Ice assignation operator called (" << src.getType() << ")" << NOCOL << std::endl;
    return *this;
}

AMateria *Ice::clone(void) const
{
    std::cout << PURPLE << "Cloning a new Ice Materia" << NOCOL << std::endl;
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << PURPLE << "* shoots an ice bolt at " << (target.getName().length() ? target.getName() : "Unnamed") << " *" << NOCOL << std::endl;
}
