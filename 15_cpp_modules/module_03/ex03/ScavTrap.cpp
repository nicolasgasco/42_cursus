#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << YELLOW << "ScavTrap default constructor called" << NOCOL << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << YELLOW << "ScavTrap parameter constructor called (" << name << ")" << NOCOL << std::endl;
};

ScavTrap::~ScavTrap(void)
{
    std::cout << YELLOW << "ScavTrap destructor called" << NOCOL << std::endl;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
    this->_name = src.getName();
    std::cout << YELLOW << "ScavTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    ClapTrap::attack(target);
    if (this->_name.length())
        std::cout << YELLOW << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << NOCOL << std::endl;
    else
        std::cout << YELLOW << "Unnamed ScavTrap attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << NOCOL << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    ClapTrap::takeDamage(amount);
    if (this->_name.length())
        std::cout << YELLOW << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << NOCOL << std::endl;
    else
        std::cout << YELLOW << "Unnamed ScavTrap takes " << amount << " points of damage!" << NOCOL << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    ClapTrap::beRepaired(amount);
    std::cout << YELLOW << "ScavTrap " << this->_name << " has recovered " << amount << " points of life and has now " << this->_hitpoints << "!" << NOCOL << std::endl;
}

void ScavTrap::guardGate(void) const
{
    if (this->_name.length())
        std::cout << YELLOW << "ScavTrap " << this->_name << " has entered Gate keeper mode" << NOCOL << std::endl;
    else
        std::cout << YELLOW << "Unnamed ScavTrap has entered Gate keeper mode" << NOCOL << std::endl;
}