#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
    this->Name = name;
    std::cout << "ClapTrap paramter constructor called (" << name << ")" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    this->Name = src.getName();
    std::cout << "Assignment operator overload called" << std::endl;
    return *this;
}

void ClapTrap::attack(std::string const &target)
{
    this->EnergyPoints--;
    if (this->Name.length())
        std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    else
        std::cout << "Unnamed ClapTrap attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->Hitpoints -= amount;
    if (this->Name.length())
        std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage!" << std::endl;
    else
        std::cout << "Unnamed ClapTrap takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->Hitpoints += amount;
    std::cout << "ClapTrap " << this->Name << " has recovered " << amount << " points of life and has now " << this->Hitpoints << "!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return this->Name;
}

int ClapTrap::getHitPoints(void) const
{
    return this->Hitpoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->EnergyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
    return this->AttackDamage;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, ClapTrap const &std)
{
    if (std.getName().length())
        std::cout << "Name: " << std.getName() << std::endl;
    else
        std::cout << "Name: n/a" << std::endl;
    std::cout << "Hit points: " << std.getHitPoints() << std::endl;
    std::cout << "Damage points: " << std.getAttackDamage() << std::endl;
    std::cout << "Energy points: " << std.getEnergyPoints() << std::endl;
    return os;
}
