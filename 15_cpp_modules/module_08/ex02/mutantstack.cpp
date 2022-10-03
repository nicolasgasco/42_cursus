
#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
    std::cout << "Mutant stack default constructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src)
{
    std::cout << "Mutant stack copy constructor" << std::endl;
    *this = src;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
    std::cout << "Mutant stack destructor" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    this->c = src.c;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return this->c.end();
}