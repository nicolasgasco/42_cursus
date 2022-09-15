#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
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

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src.getName())
{
    this->Hitpoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    *this = src;
    std::cout << YELLOW << "ScavTrap copy constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << YELLOW << "ScavTrap destructor called" << NOCOL << std::endl;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
    this->Name = src.Name;
    std::cout << YELLOW << "ScavTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    this->EnergyPoints--;
    std::cout << YELLOW << "ScavTrap " << (this->Name.length() ? this->Name : "without name")
              << " attacks " << (target.length() ? target : "Unnamed trap") << ", causing " << this->AttackDamage << " points of damage!" << NOCOL << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    this->Hitpoints -= amount;
    std::cout << YELLOW << "ScavTrap " << (this->Name.length() ? this->Name : "without name") << " takes " << amount << " points of damage!" << NOCOL << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    this->Hitpoints += amount;
    std::cout << YELLOW << "ScavTrap " << (this->Name.length() ? this->Name : "without name") << " has recovered " << amount << " points of life and has now " << this->Hitpoints << "!" << NOCOL << std::endl;
}

void ScavTrap::guardGate(void) const
{
    std::cout << YELLOW << "ScavTrap " << (this->Name.length() ? this->Name : "without name") << " has entered Gate keeper mode" << NOCOL << std::endl;
}