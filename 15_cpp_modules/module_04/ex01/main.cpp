#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define NUM_ANIMALS

int main(void)
{
    Animal *animals[6] = {
        new Dog(),
        new Dog(),
        new Cat(),
        new Cat(),
    };
    std::cout << std::endl;

    for (unsigned long i = 0; i < sizeof(animals) / sizeof(Animal *); i++)
        delete animals[i];
    std::cout << std::endl;
    return (0);
}