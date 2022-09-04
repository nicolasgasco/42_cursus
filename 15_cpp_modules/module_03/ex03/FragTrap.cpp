#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << BLUE << "FragTrap default constructor called" << NOCOL << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << BLUE << "FragTrap parameter constructor called (" << name << ")" << NOCOL << std::endl;
};

FragTrap::~FragTrap(void)
{
    std::cout << BLUE << "FragTrap destructor called" << NOCOL << std::endl;
};

FragTrap &FragTrap::operator=(FragTrap const &src)
{
    this->_name = src.getName();
    std::cout << BLUE << "FragTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) const
{
    if (this->_name.length())
        std::cout << BLUE << "FragTrap " << this->_name << " gives everyone an high five" << NOCOL << std::endl;
    else
        std::cout << BLUE << "Unnamed FragTrap gives everyone an high five" << NOCOL << std::endl;
}