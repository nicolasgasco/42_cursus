#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    this->Hitpoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << BLUE << "FragTrap default constructor called" << NOCOL << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->Name = name;
    this->Hitpoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << BLUE << "FragTrap parameter constructor called (" << name << ")" << NOCOL << std::endl;
};

FragTrap::~FragTrap(void)
{
    std::cout << BLUE << "FragTrap destructor called" << NOCOL << std::endl;
};

FragTrap &FragTrap::operator=(FragTrap const &src)
{
    this->Name = src.getName();
    std::cout << BLUE << "FragTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << BLUE << "FragTrap " << (this->Name.length() ? this->Name : "n/a")
              << " gives everyone an high five" << NOCOL << std::endl;
}