#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void) {
    Zombie newZombieStack = Zombie("Carlos");
    newZombieStack.announce();

    Zombie* newZombieHeap = newZombie("Mario");
    newZombieHeap->announce();
    delete newZombieHeap;
    return (0);
}