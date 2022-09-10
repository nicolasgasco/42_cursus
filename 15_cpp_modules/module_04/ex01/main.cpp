#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define NUM_ANIMALS

int main(void) {
    Animal *animals[6];
    std::cout << std::endl;

    for (int i = 0; i < (6 / 2); i++) {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 3; i < 6; i++) {
        animals[i] = new Cat();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (unsigned long i = 0; i < sizeof(animals) / sizeof(Animal *); i++) {
        delete animals[i];
    }
    std::cout << std::endl;
    return (0);
}