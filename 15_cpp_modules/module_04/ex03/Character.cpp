#include "Character.hpp"

Character::Character(void)
{
    std::cout << YELLOW << "Character default constructor" << NOCOL << std::endl;
}

Character::Character(std::string const &name)
{
    this->name = name;
    std::cout << YELLOW << "Character parameter constructor (" << name << ")" << NOCOL << std::endl;
}

Character::~Character(void)
{
    std::cout << YELLOW << "Character destructor" << NOCOL << std::endl;
}

Character::Character(Character const &src)
{
    this->name = src.getName();
    *this = src;
    std::cout << YELLOW << "Character copy constructor called" << NOCOL << std::endl;
}

Character &Character::operator=(const Character &src)
{
    this->name = src.getName();
    std::cout << YELLOW << "Character assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string const &Character::getName(void) const
{
    return this->name;
}