#pragma once
#ifndef __CAT_H__
#define __CAT_H__
#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"
#include <iostream>

#include "Animal.hpp"

class Cat : virtual public Animal
{
public:
    Cat(void);
    Cat(Cat const &src);

    virtual ~Cat(void);

    Cat &operator=(Cat const &src);

    std::string getType(void) const;
    void makeSound(void) const;

private:
    std::string type;
};

#endif