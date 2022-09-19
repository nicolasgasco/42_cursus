#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#define CYAN "\033[1;36m"
#define NOCOL "\033[0m"
#include <iostream>

class Animal
{
public:
    Animal(void);
    Animal(Animal const &src);

    virtual ~Animal(void);

    Animal &operator=(Animal const &src);

    virtual std::string getType(void) const;
    virtual void makeSound(void) const;

protected:
    std::string type;
};

#endif