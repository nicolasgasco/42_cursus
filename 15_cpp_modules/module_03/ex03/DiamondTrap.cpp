#include "DiamondTrap.hpp"
#include <iomanip>

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
    std::cout << PURPLE << "DiamondTrap parameter constructor called (" << name << ")" << NOCOL << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ScavTrap(src.getName()), FragTrap(src.getName())
{
    this->Hitpoints = FragTrap::HitpointsValue;
    this->EnergyPoints = ScavTrap::EnergyPointsValue;
    this->AttackDamage = FragTrap::AttackDamageValue;
    *this = src;
    std::cout << PURPLE << "DiamondTrap copy constructor called (" << this->Name << ")" << NOCOL << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << PURPLE << "DiamondTrap destructor called" << NOCOL << std::endl;
};

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
    this->Name = src.getName();
    ClapTrap::Name = this->Name + "_clap_name";
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

// Stream oeprator
std::ostream &operator<<(std::ostream &os, DiamondTrap const &std)
{
    std::cout << "_________________________________________" << std::endl;
    std::cout << "| Name            | " << std::setw(20) << (std.getName().length() ? std.getName() : "n/a") << "|" << std::endl;
    std::cout << "| Hit points      | " << std::setw(20) << std.getHitPoints() << std::setfill(' ') << "|" << std::endl;
    std::cout << "| Damage points   | " << std::setw(20) << std.getAttackDamage() << "|" << std::endl;
    std::cout << "| Energy points   | " << std::setw(20) << std.getEnergyPoints() << "|" << std::endl;
    std::cout << "_________________________________________" << std::endl;
    return os;
}
