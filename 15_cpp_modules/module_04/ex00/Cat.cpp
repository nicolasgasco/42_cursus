#include "Cat.hpp"

Cat::Cat(void) : type("Cat")
{
    std::cout << PURPLE << "Cat default constructor called" << NOCOL << std::endl;
}

Cat::Cat(Cat const &src)
{
    *this = src;
    std::cout << PURPLE << "Cat copy constructor called" << NOCOL << std::endl;
}

Cat::~Cat(void)
{
    std::cout << PURPLE << "Cat destructor called" << NOCOL << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    this->type = src.getType();
    std::cout << PURPLE << "Cat assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string Cat::getType(void) const
{
    return this->type;
}

void Cat::makeSound(void) const
{
    std::cout << PURPLE << "Miao miao miao" << NOCOL << std::endl;
}