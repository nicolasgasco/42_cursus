#include "Character.hpp"

Character::Character(void)
{
    std::cout << YELLOW << "Character default constructor" << NOCOL << std::endl;
}

Character::Character(std::string const &name)
{
    this->name = name;
    std::cout << YELLOW << "Character parameter constructor (" << name << ")" << NOCOL << std::endl;
}

Character::~Character(void)
{
    std::cout << YELLOW << "Character destructor" << NOCOL << std::endl;
    for (int i = 0; i < this->materiaNum; i++)
        delete this->inventory[i];
}

Character::Character(Character const &src)
{
    *this = src;
    std::cout << YELLOW << "Character copy constructor called" << NOCOL << std::endl;
}

Character &Character::operator=(const Character &src)
{
    this->name = src.getName();
    AMateria *newInventory[this->materiaNum];
    for (int i = 0; i < this->materiaNum; i++)
        newInventory[i] = this->inventory[i];
    std::cout << YELLOW << "Character assignation operator called" << NOCOL << std::endl;
    return *this;
}

std::string const &Character::getName(void) const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    int i = 0;
    for (; i < this->materiaNum; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            break;
        }
    }
    if (i == this->materiaNum)
        std::cout << YELLOW << "No space left in Character's inventory" << NOCOL << std::endl;
    else
    {
        std::cout << YELLOW << "Character equipped Materia of type '" << m->getType() << "'"
                  << " at index " << i << NOCOL << std::endl;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < this->materiaNum)
    {
        std::cout << YELLOW << (this->name.length() ? ("Character '" + this->name + "'") : "Unnamed Character") << " unequip() function: unequipped slot " << idx << NOCOL << std::endl;
        this->inventory[idx] = NULL;
    }
    else
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