#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->Hitpoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << YELLOW << "ScavTrap default constructor called" << NOCOL << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->Name = name;
    this->Hitpoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << YELLOW << "ScavTrap parameter constructor called (" << name << ")" << NOCOL << std::endl;
};

ScavTrap::~ScavTrap(void)
{
    std::cout << YELLOW << "ScavTrap destructor called" << NOCOL << std::endl;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
    this->Name = src.getName();
    std::cout << YELLOW << "ScavTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    ClapTrap::attack(target);
    if (this->Name.length())
        std::cout << YELLOW << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << NOCOL << std::endl;
    else
        std::cout << YELLOW << "Unnamed ScavTrap attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << NOCOL << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    ClapTrap::takeDamage(amount);
    if (this->Name.length())
        std::cout << YELLOW << "ScavTrap " << this->Name << " takes " << amount << " points of damage!" << NOCOL << std::endl;
    else
        std::cout << YELLOW << "Unnamed ScavTrap takes " << amount << " points of damage!" << NOCOL << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    ClapTrap::beRepaired(amount);
    std::cout << YELLOW << "ScavTrap " << this->Name << " has recovered " << amount << " points of life and has now " << this->Hitpoints << "!" << NOCOL << std::endl;
}

void ScavTrap::guardGate(void) const
{
    if (this->Name.length())
        std::cout << YELLOW << "ScavTrap " << this->Name << " has entered Gate keeper mode" << NOCOL << std::endl;
    else
        std::cout << YELLOW << "Unnamed ScavTrap has entered Gate keeper mode" << NOCOL << std::endl;
}