#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define NUM_ANIMALS

int main(void)
{
    std::cout << "Array of 4 animals:" << std::endl;
    Animal *animals[4] = {
        new Dog(),
        new Dog(),
        new Cat(),
        new Cat(),
    };
    std::cout << std::endl;

    for (unsigned long i = 0; i < sizeof(animals) / sizeof(Animal *); i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }

    std::cout << "Deep copy tests:" << std::endl;
    Cat seed;
    std::cout << std::endl;

    Cat copy = Cat(seed);
    std::cout << std::endl;

    Cat copy2 = seed;
    std::cout << std::endl;

    std::cout << "Brains memory addresses:" << std::endl;
    std::cout << seed.getBrain() << std::endl;
    std::cout << copy.getBrain() << std::endl;
    std::cout << copy2.getBrain() << std::endl;
    std::cout << std::endl;

    Dog seedDog;
    std::cout << std::endl;

    Dog copyDog = Dog(seedDog);
    std::cout << std::endl;

    Dog copy2Dog = seedDog;
    std::cout << std::endl;

    std::cout << "Brains memory addresses:" << std::endl;
    std::cout << seedDog.getBrain() << std::endl;
    std::cout << copyDog.getBrain() << std::endl;
    std::cout << copy2Dog.getBrain() << std::endl;
    std::cout << std::endl;

    return (0);
}