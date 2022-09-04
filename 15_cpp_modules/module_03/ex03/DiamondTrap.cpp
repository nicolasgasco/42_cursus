#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << PURPLE << "DiamondTrap default constructor called" << NOCOL << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->_name = name;
    ClapTrap::_name = name + "_clap_name";
    std::cout << PURPLE << "DiamondTrap parameter constructor called" << NOCOL << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << PURPLE << "DiamondTrap destructor called" << NOCOL << std::endl;
};

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
    this->_name = src.getName();
    std::cout << PURPLE << "DiamondTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

std::string DiamondTrap::getName(void) const
{
    return this->_name;
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << PURPLE << "DiamondTrap name is " << (this->_name.length() ? this->_name : "n/a") << " and ClapTrap name is " << (ClapTrap::getName().length() ? ClapTrap::getName() : "n/a") << std::endl;
}