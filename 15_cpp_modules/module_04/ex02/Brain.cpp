#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << GREEN << "Brain default constructor called" << NOCOL << std::endl;
}

Brain::Brain(Brain const &src)
{
    std::cout << GREEN << "Brain copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Brain::~Brain(void)
{
    std::cout << GREEN << "Brain destructor called" << NOCOL << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << GREEN << "Brain assignation operator called" << NOCOL << std::endl;
    for (int i = 0; i < this->ideasNum; i++)
        this->ideas[i] = src.ideas[i];
    return *this;
}