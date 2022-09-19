#pragma once
#ifndef __DOG_H__
#define __DOG_H__
#define BLUE "\033[1;34m"
#define NOCOL "\033[0m"
#include <iostream>

#include "Animal.hpp"

class Dog : virtual public Animal
{
public:
    Dog(void);
    Dog(Dog const &src);

    virtual ~Dog(void);

    Dog &operator=(Dog const &src);

    std::string getType(void) const;
    void makeSound(void) const;

private:
    std::string type;
};

#endif