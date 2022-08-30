#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    this->_name = name;
    std::cout << "ClapTrap paramter constructor called (" << name << ")" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    this->_name = src.getName();
    std::cout << "Assignment operator overload called" << std::endl;
    return *this;
}

void ClapTrap::attack(std::string const &target)
{
    this->_energyPoints--;
    if (this->_name.length())
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    else
        std::cout << "Unnamed ClapTrap attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitpoints -= amount;
    if (this->_name.length())
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    else
        std::cout << "Unnamed ClapTrap takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitpoints += amount;
    std::cout << "ClapTrap " << this->_name << " has recovered " << amount << " points of life and has now " << this->_hitpoints << "!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return this->_name;
}

int ClapTrap::getHitPoints(void) const
{
    return this->_hitpoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
    return this->_attackDamage;
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
