#include "Brain.hpp"

Brain::Brain(void) : type("Brain") {
    *ideas = "ciao";
    std::cout << GREEN << "Brain default constructor called" << NOCOL << std::endl;
}

Brain::~Brain(void) {
    *ideas = "ciao";
    std::cout << GREEN << "Brain destructor called" << NOCOL << std::endl;
}

Brain::Brain(Brain const &src) {
    std::cout << GREEN << "Brain copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Brain &Brain::operator=(const Brain &src) {
    std::cout << GREEN << "Brain assignation operator called" << NOCOL << std::endl;
    this->type = src.getType();
    return *this;
}

std::string Brain::getType(void) const {
    return this->type;
}