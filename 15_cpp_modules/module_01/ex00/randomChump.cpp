#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie randomZombie = Zombie(name);
    randomZombie.announce();
}
