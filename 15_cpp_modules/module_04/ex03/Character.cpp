#include "Character.hpp"

Character::Character(void)
{
    for (int i = 0; i < this->materiaNum; i++)
        this->inventory[i] = NULL;
    std::cout << YELLOW << "Character default constructor" << NOCOL << std::endl;
}

Character::Character(std::string const &name)
{
    this->name = name;
    for (int i = 0; i < this->materiaNum; i++)
        this->inventory[i] = NULL;
    std::cout << YELLOW << "Character parameter constructor (" << name << ")" << NOCOL << std::endl;
}

Character::~Character(void)
{
    for (int i = 0; i < this->materiaNum; i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
    }
    std::cout << YELLOW << "Character destructor" << NOCOL << std::endl;
}

Character::Character(Character const &src)
{
    std::cout << YELLOW << "Character copy constructor called" << NOCOL << std::endl;
    for (int i = 0; i < this->materiaNum; i++)
        this->inventory[i] = NULL;
    *this = src;
}

Character &Character::operator=(const Character &src)
{
    this->name = src.getName();
    for (int i = 0; i < this->materiaNum; i++)
        this->inventory[i] = src.inventory[i];
    std::cout << YELLOW << "Character assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string const &Character::getName(void) const
{
    return this->name;
}

void Character::equip(AMateria *m)
{

    if (!m)
    {
        std::cout << YELLOW << "Character tried to equip invalid Materia" << NOCOL << std::endl;
        return;
    }

    int i = 0;
    for (; i < this->materiaNum; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            std::cout << YELLOW << "Character equipped Materia of type '" << m->getType() << "'"
                      << " at index " << i << NOCOL << std::endl;
            return;
        }
    }

    std::cout << YELLOW << "No space left in Character's inventory" << NOCOL << std::endl;
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < this->materiaNum)
    {
        if (!this->inventory[idx])
        {
            std::cout << YELLOW << (this->name.length() ? ("Character '" + this->name + "'") : "Unnamed Character") << " tried to unequip invalid Materia at slot " << idx << NOCOL << std::endl;
            return;
        }
        std::cout << YELLOW << (this->name.length() ? ("Character '" + this->name + "'") : "Unnamed Character") << " unequip() function: unequipped slot " << idx << NOCOL << std::endl;
        this->inventory[idx] = NULL;
        return;
    }
    std::cout << YELLOW << "Impossible to use Character unequip() function: index out of range" << NOCOL << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (!this->inventory[idx])
    {
        std::cout << YELLOW << "Impossible to use Character use() function: unequipped slot" << NOCOL << std::endl;
        return;
    }

    if (idx >= 0 && idx < this->materiaNum)
    {
        std::cout << YELLOW << (this->name.length() ? ("Character '" + this->name) : "Unnamed Character") << "' use() function:" << NOCOL << std::endl;
        this->inventory[idx]->use(target);
    }
    else
        std::cout << YELLOW << "Impossible to use Character use() function: index out of range" << NOCOL << std::endl;
}

void Character::outputInventoryAddress(void) const
{
    std::cout << this->inventory << std::endl;
}