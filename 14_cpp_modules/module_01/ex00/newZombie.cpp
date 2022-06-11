#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *newZombiePtr = new Zombie(name);
    return newZombiePtr;
}
