#include "WrongCat.hpp"

WrongCat::WrongCat(void) : type("WrongCat")
{
    std::cout << YELLOW << "WrongCat default constructor called" << NOCOL << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat(void)
{
    std::cout << YELLOW << "WrongCat destructor called" << NOCOL << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    this->type = src.getType();
    std::cout << "WrongCat assignation operator called" << std::endl;
    return *this;
}
std::string WrongCat::getType(void) const
{
    return this->type;
}

void WrongCat::makeSound(void) const
{
    std::cout << YELLOW << "Miao miao miao" << NOCOL << std::endl;
}