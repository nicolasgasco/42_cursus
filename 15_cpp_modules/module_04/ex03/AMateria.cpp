#include "AMateria.hpp"
#include <iomanip>

AMateria::AMateria(void)
{
    std::cout << GREEN << "AMateria default constructor" << NOCOL << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
    std::cout << GREEN << "AMateria parameter constructor" << NOCOL << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << GREEN << "AMateria destructor" << NOCOL << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
    *this = src;
    std::cout << GREEN << "AMateria copy constructor called" << NOCOL << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    this->type = src.getType();
    std::cout << GREEN << "AMateria assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string const &AMateria::getType(void) const
{
    return this->type;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, AMateria const &std)
{
    std::cout << "_______________________________" << std::endl;
    std::cout << "| Type            | " << std::setw(10) << (std.getType().length() ? std.getType() : "n/a") << "|" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    return os;
}
