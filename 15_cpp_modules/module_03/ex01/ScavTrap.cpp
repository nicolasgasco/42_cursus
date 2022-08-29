#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
    this->_name = name;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap parameter constructor called (" << name << ")" << std::endl;
};

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
};

void ScavTrap::attack(std::string const &target)
{
    ClapTrap::attack(target);
    if (this->_name.length())
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "Unnamed ScavTrap attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    ClapTrap::takeDamage(amount);
    if (this->_name.length())
    {
        std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "Unnamed ScavTrap takes " << amount << " points of damage!" << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    ClapTrap::beRepaired(amount);
    std::cout << "ScavTrap " << this->_name << " has recovered " << amount << " points of life and has now " << this->_hitpoints << "!" << std::endl;
}

void ScavTrap::guardGate(void) const
{
    if (this->_name.length())
    {
        std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode" << std::endl;
    }
    else
    {
        std::cout << "Unnamed ScavTrap has entered Gate keeper mode" << std::endl;
    }
}