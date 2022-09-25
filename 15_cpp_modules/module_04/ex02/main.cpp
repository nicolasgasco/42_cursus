#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define NUM_ANIMALS

int main(void)
{

    std::cout << "Create a dog and a cat:" << std::endl;
    std::cout << std::endl;
    const Animal *j = new Dog();
    std::cout << std::endl;
    const Animal *i = new Cat();
    std::cout << std::endl;

    std::cout << "Types:" << std::endl;
    std::cout << "j type is: " << j->getType() << std::endl;
    std::cout << "j type is: " << i->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "Sounds:" << std::endl;
    j->makeSound();
    i->makeSound();
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;
    delete i;
    std::cout << std::endl;

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

    // const Animal *wrong = new Animal();
    return (0);
}