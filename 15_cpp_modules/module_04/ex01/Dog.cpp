#include "Dog.hpp"

Dog::Dog(void) : type("Dog")
{
    this->brain = new Brain();
    std::cout << BLUE << "Dog default constructor called" << NOCOL << std::endl;
}

Dog::Dog(Dog const &src)
{
    this->brain = new Brain();
    std::cout << BLUE << "Dog copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Dog::~Dog(void)
{
    delete this->brain;
    std::cout << BLUE << "Dog destructor called" << NOCOL << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << BLUE << "Dog assignation operator called" << NOCOL << std::endl;
    this->type = src.getType();
    return *this;
}
std::string Dog::getType(void) const
{
    return this->type;
}

void Dog::makeSound(void) const
{
    std::cout << BLUE << "Bau bau bau" << NOCOL << std::endl;
}