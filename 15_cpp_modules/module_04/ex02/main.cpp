#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define NUM_ANIMALS

int main(void) {
    std::cout << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "j type is: " << j->getType() << std::endl;
    std::cout << "j type is: " << i->getType() << std::endl;
    std::cout << std::endl;

    j->makeSound();
    i->makeSound();
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;
    delete i;
    std::cout << std::endl;
    return (0);
}