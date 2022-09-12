#pragma once
#ifndef __WRONGWrongAnimal_H__
#define __WRONGWrongAnimal_H__
#define RED "\033[0;31m"
#define NOCOL "\033[0m"
#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal(void);
    WrongAnimal(WrongAnimal const &src);

    virtual ~WrongAnimal(void);

    WrongAnimal &operator=(WrongAnimal const &src);

    virtual std::string getType(void) const;
    void makeSound(void) const;

protected:
    std::string type;
};

#endif