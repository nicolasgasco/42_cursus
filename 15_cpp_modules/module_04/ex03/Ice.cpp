#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria()
{
    std::cout << PURPLE << "Ice default constructor" << NOCOL << std::endl;
}

Ice::Ice(std::string const &type) : AMateria(type)
{
    this->type = type;
    std::cout << PURPLE << "Ice parameter constructor (" << type << ")" << NOCOL << std::endl;
}

Ice::~Ice(void)
{
    std::cout << PURPLE << "Ice destructor" << NOCOL << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src.getType())
{
    *this = src;
    std::cout << PURPLE << "Ice copy constructor called" << NOCOL << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
    this->type = src.getType();
    std::cout << PURPLE << "Ice assignation operator called" << NOCOL << std::endl;
    return *this;
}

AMateria *Ice::clone(void) const
{
    return new Ice(this->type);
}

void Ice::use(ICharacter &target)
{
    std::cout << PURPLE << "* shoots an ice bolt at " << (target.getName().length() ? target.getName() : "Unnamed") << " *" << NOCOL << std::endl;
}
