#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    this->Hitpoints = FragTrap::Hitpoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = FragTrap::AttackDamage;
    std::cout << PURPLE << "DiamondTrap default constructor called" << NOCOL << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->Name = name;
    ClapTrap::Name = name + "_clap_name";
    std::cout << FragTrap::AttackDamage << std::endl;
    this->Hitpoints = FragTrap::Hitpoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = FragTrap::AttackDamage;
    std::cout << PURPLE << "DiamondTrap parameter constructor called" << NOCOL << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << PURPLE << "DiamondTrap destructor called" << NOCOL << std::endl;
};

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
    this->Name = src.getName();
    std::cout << PURPLE << "DiamondTrap assignment operator overload called" << NOCOL << std::endl;
    return *this;
}

std::string DiamondTrap::getName(void) const
{
    return this->Name;
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << PURPLE << "DiamondTrap name is " << (this->Name.length() ? this->Name : "n/a") << " and ClapTrap name is " << (ClapTrap::getName().length() ? ClapTrap::getName() : "n/a") << std::endl;
}