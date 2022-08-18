#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombieHorde = new Zombie[N];

    for (int i = 0; i < N; ++i)
    {
        std::string zombieName = name + " " + std::to_string(i + 1);
        zombieHorde[i].setName(zombieName);
    }
    return zombieHorde;
}
