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
    for (int i = 0; i < this->ideasNum; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << GREEN << "Brain assignation operator called" << NOCOL << std::endl;
    return *this;
}

void Brain::populateIdeas(std::string animalType)
{
    for (int i = 0; i < this->ideasNum; i++)
        this->ideas[i] = animalType + "_" + std::to_string(i + 1);
}