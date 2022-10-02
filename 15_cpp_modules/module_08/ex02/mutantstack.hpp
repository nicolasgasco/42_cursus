#pragma once
#ifndef __STACK_H__
#define __STACK_H__

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>(void)
    {
        std::cout << "Mutant stack default constructor" << std::endl;
    }

    ~MutantStack<T>(void)
    {
        std::cout << "Mutant stack destructor" << std::endl;
    }

    MutantStack<T>(MutantStack<T> const &src)
    {
        std::cout << "Mutant stack copy constructor" << std::endl;
        *this = src;
    }

    MutantStack &operator=(const MutantStack &src)
    {
        if (src.values.size())
        {
            // Contineu
        }
    }

    typedef typename MutantStack<T>::container_type::iterator iterator;

    iterator begin(void)
    {
        return this->c.begin();
    }

    iterator end(void)
    {
        return this->c.end();
    }

private:
};

#endif