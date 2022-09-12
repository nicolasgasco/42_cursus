#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << RED << "WrongAnimal default constructor called" << NOCOL << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << RED << "WrongAnimal destructor called" << NOCOL << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    this->type = src.getType();
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    return *this;
}
std::string WrongAnimal::getType(void) const
{
    return this->type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << RED << "I'm a generic WrongAnimal, I don't have a voice :(" << NOCOL << std::endl;
}
