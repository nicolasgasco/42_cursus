#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    Zombie newZombieStack = Zombie("Stacky");
    newZombieStack.announce();

    Zombie* newZombieHeap = newZombie("Heapy");
    newZombieHeap->announce();

    randomChump("Stacky 2");

    Zombie* newZombieHeap2 = newZombie("Heapy 2");
    newZombieHeap2->announce();
    
    std::cout << "End of program" << std::endl;

    delete newZombieHeap;
    delete newZombieHeap2;
    return (0);
}
