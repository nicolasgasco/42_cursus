#include "Cat.hpp"

Cat::Cat(void) : type("Cat")
{
    this->brain = new Brain();
    std::cout << PURPLE << "Cat default constructor called" << NOCOL << std::endl;
}

Cat::Cat(Cat const &src)
{
    this->brain = new Brain();
    *this = src;
    std::cout << PURPLE << "Cat copy constructor called" << NOCOL << std::endl;
}

Cat::~Cat(void)
{
    delete this->brain;
    std::cout << PURPLE << "Cat destructor called" << NOCOL << std::endl;
}

Cat &Cat::operator=(Cat const &src)
{
    this->type = src.getType();
    *(this->brain) = *(src.brain);
    std::cout << PURPLE << "Cat assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string Cat::getType(void) const
{
    return this->type;
}

Brain *Cat::getBrain(void) const
{
    return this->brain;
}

void Cat::makeSound(void) const
{
    std::cout << PURPLE << "Miao miao miao" << NOCOL << std::endl;
}