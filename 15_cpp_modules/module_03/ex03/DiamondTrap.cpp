#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    this->Hitpoints = FragTrap::HitpointsValue;
    this->EnergyPoints = ScavTrap::EnergyPointsValue;
    this->AttackDamage = FragTrap::AttackDamageValue;
    std::cout << PURPLE << "DiamondTrap default constructor called" << NOCOL << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
    this->Name = name;
    ClapTrap::Name = name + "_clap_name";
    this->Hitpoints = FragTrap::HitpointsValue;
    this->EnergyPoints = ScavTrap::EnergyPointsValue;
    this->AttackDamage = FragTrap::AttackDamageValue;
    std::cout << PURPLE << "DiamondTrap parameter constructor called" << NOCOL << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ScavTrap(src.getName()), FragTrap(src.getName())
{
    this->Hitpoints = FragTrap::HitpointsValue;
    this->EnergyPoints = ScavTrap::EnergyPointsValue;
    this->AttackDamage = FragTrap::AttackDamageValue;
    *this = src;
    std::cout << CYAN << "ClapTrap copy constructor called (" << this->Name << ")" << NOCOL << std::endl;
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