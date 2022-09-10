#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    const Animal* meta = new Animal();
    std::cout << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "meta type is: " << meta->getType() << std::endl;
    std::cout << "j type is: " << j->getType() << std::endl;
    std::cout << "j type is: " << i->getType() << std::endl;
    std::cout << std::endl;

    j->makeSound();
    i->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    std::cout << std::endl;
    delete j;
    std::cout << std::endl;
    delete i;
    std::cout << std::endl;

    std::cout << "Wrong animals:" << std::endl;
    std::cout << std::endl;

    const WrongAnimal* wrong = new WrongAnimal();
    std::cout << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << std::endl;

    std::cout << "wrong type is: " << wrong->getType() << std::endl;
    std::cout << std::endl;
    std::cout << "wrongCat type is: " << wrongCat->getType() << std::endl;
    std::cout << std::endl;

    wrong->makeSound();
    wrongCat->makeSound();
    std::cout << std::endl;

    delete wrong;
    std::cout << std::endl;
    delete wrongCat;
    std::cout << std::endl;
    return (0);
}