#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "Animal default:" << std::endl;
    const Animal *meta = new Animal();
    std::cout << std::endl;

    std::cout << "Animal copy:" << std::endl;
    const Animal *copy = new Animal(*meta);
    std::cout << std::endl;

    std::cout << "Cats and dogs:" << std::endl;
    const Animal *j = new Dog();
    std::cout << std::endl;
    const Animal *i = new Cat();
    std::cout << std::endl;

    std::cout << "Types:" << std::endl;
    std::cout << "meta type is: " << meta->getType() << std::endl;
    std::cout << "copy type is: " << copy->getType() << std::endl;
    std::cout << "j type is: " << j->getType() << std::endl;
    std::cout << "j type is: " << i->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "Sounds:" << std::endl;
    meta->makeSound();
    j->makeSound();
    i->makeSound();
    std::cout << std::endl;

    std::cout << "Destruct:" << std::endl;
    delete meta;
    std::cout << std::endl;

    delete copy;
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Wrong animals:" << std::endl;
    const WrongAnimal *wrong = new WrongAnimal();

    std::cout << std::endl;
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << std::endl;

    std::cout << std::endl;
    const WrongCat *rightCat = new WrongCat();
    std::cout << std::endl;

    std::cout << "Types:" << std::endl;
    std::cout << "wrong type is: " << wrong->getType() << std::endl;
    std::cout << "wrongCat type is: " << wrongCat->getType() << std::endl;
    std::cout << "rightCat type is: " << rightCat->getType() << std::endl;

    std::cout << std::endl;

    std::cout << "Sounds:" << std::endl;
    wrong->makeSound();
    wrongCat->makeSound();
    rightCat->makeSound();
    std::cout << std::endl;

    delete wrong;
    std::cout << std::endl;

    delete wrongCat;
    std::cout << std::endl;

    delete rightCat;
    std::cout << std::endl;

    std::cout << "Completeness checks:" << std::endl;
    const Animal *src = new Animal();
    std::cout << std::endl;

    const Animal *k = new Animal(*src);
    std::cout << std::endl;

    const Cat *l = new Cat();
    std::cout << std::endl;

    const Animal *m = new Cat(*l);
    std::cout << std::endl;

    const Dog *n = new Dog();
    std::cout << std::endl;

    const Animal *o = new Dog(*n);
    std::cout << std::endl;

    delete src;
    std::cout << std::endl;

    delete k;
    std::cout << std::endl;

    delete l;
    std::cout << std::endl;

    delete m;
    std::cout << std::endl;

    delete n;
    std::cout << std::endl;

    delete o;
    std::cout << std::endl;

    return (0);
}