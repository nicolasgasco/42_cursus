#include "ClapTrap.hpp"
#include <iomanip>

ClapTrap::ClapTrap(void) : Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << CYAN << "ClapTrap default constructor called" << NOCOL << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
    this->Name = name;
    std::cout << CYAN << "ClapTrap paramter constructor called (" << name << ")" << NOCOL << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
    *this = src;
    std::cout << CYAN << "ClapTrap copy constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << CYAN << "ClapTrap destructor called" << NOCOL << std::endl;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    this->Name = src.Name;
    std::cout << CYAN << "Assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void ClapTrap::attack(std::string const &target)
{
    this->EnergyPoints--;
    std::cout << CYAN << "ClapTrap " << (this->Name.length() ? this->Name : "without name")
              << " attacks " << (target.length() ? target : "Unnamed trap") << ", causing " << this->AttackDamage << " points of damage!" << NOCOL << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->Hitpoints -= amount;
    std::cout << CYAN << "ClapTrap " << (this->Name.length() ? this->Name : "without name") << " takes " << amount << " points of damage!" << NOCOL << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->Hitpoints += amount;
    std::cout << CYAN << "ClapTrap " << (this->Name.length() ? this->Name : "without name") << " has recovered " << amount << " points of life and has now " << this->Hitpoints << "!" << NOCOL << std::endl;
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
    std::cout << "_______________________________" << std::endl;
    std::cout << "| Name            | " << std::setw(10) << (std.getName().length() ? std.getName() : "n/a") << "|" << std::endl;
    std::cout << "| Hit points      | " << std::setw(10) << std.getHitPoints() << std::setfill(' ') << "|" << std::endl;
    std::cout << "| Damage points   | " << std::setw(10) << std.getAttackDamage() << "|" << std::endl;
    std::cout << "| Energy points   | " << std::setw(10) << std.getEnergyPoints() << "|" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    return os;
}
