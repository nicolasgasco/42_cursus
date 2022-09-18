#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << CYAN << "Animal default constructor called" << NOCOL << std::endl;
}

Animal::~Animal(void)
{
    std::cout << CYAN << "Animal destructor called" << NOCOL << std::endl;
}

Animal::Animal(Animal const &src)
{
    std::cout << CYAN << "Animal copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src)
{
    std::cout << CYAN << "Animal assignation operator called" << NOCOL << std::endl;
    this->type = src.getType();
    return *this;
}