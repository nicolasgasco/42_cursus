#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>(void);
    MutantStack<T>(MutantStack<T> const &src);

    ~MutantStack<T>(void);

    MutantStack<T> &operator=(const MutantStack<T> &src);

    typedef typename MutantStack<T>::container_type::iterator iterator;
    iterator begin(void);
    iterator end(void);

    using std::stack<T>::empty;
    using std::stack<T>::pop;
    using std::stack<T>::push;
    using std::stack<T>::size;
    using std::stack<T>::top;
    using std::stack<T>::swap;

private:
    using std::stack<T>::c;
};

#endif