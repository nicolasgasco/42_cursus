#include "Dog.hpp"

Dog::Dog(void) : type("Dog")
{
    this->brain = new Brain();
    std::cout << BLUE << "Dog default constructor called" << NOCOL << std::endl;
}

Dog::Dog(Dog const &src)
{
    this->brain = new Brain();
    *this = src;
    std::cout << BLUE << "Dog copy constructor called" << NOCOL << std::endl;
}

Dog::~Dog(void)
{
    delete this->brain;
    std::cout << BLUE << "Dog destructor called" << NOCOL << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    this->type = src.getType();
    *(this->brain) = *(src.brain);
    std::cout << BLUE << "Dog assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string Dog::getType(void) const
{
    return this->type;
}

Brain *Dog::getBrain(void) const
{
    return this->brain;
}

void Dog::makeSound(void) const
{
    std::cout << BLUE << "Bau bau bau" << NOCOL << std::endl;
}