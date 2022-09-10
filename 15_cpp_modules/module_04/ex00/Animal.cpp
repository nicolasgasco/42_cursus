#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
    std::cout << CYAN << "Animal default constructor called" << NOCOL << std::endl;
}

Animal::~Animal(void) {
    std::cout << CYAN << "Animal destructor called" << NOCOL << std::endl;
}

Animal::Animal(Animal const &src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src) {
    std::cout << "Animal assignation operator called" << std::endl;
    this->type = src.getType();
    return *this;
}
std::string Animal::getType(void) const {
    return this->type;
}

void Animal::makeSound(void) const {
    std::cout << CYAN << "I'm a generic animal, I don't have a voice :(" << NOCOL << std::endl;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, Animal const &std) {
    std::string type = std.getType();
    if (type.length()) {
        std::cout << "Type is: " << std.getType() << std::endl;
    } else {
        std::cout << "Class has no type" << std::endl;
    }
    return os;
}
