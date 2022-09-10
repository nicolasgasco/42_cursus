#include "Cat.hpp"

Cat::Cat(void) : type("Cat") {
    std::cout << PURPLE << "Cat default constructor called" << NOCOL << std::endl;
}

Cat::~Cat(void) {
    std::cout << PURPLE << "Cat destructor called" << NOCOL << std::endl;
}

Cat::Cat(Cat const &src) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src) {
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = src.getType();
    return *this;
}
std::string Cat::getType(void) const {
    return this->type;
}

void Cat::makeSound(void) const {
    std::cout << PURPLE << "Miao miao miao" << NOCOL << std::endl;
}