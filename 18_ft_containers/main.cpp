#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
#include <map>
#include <stack>
#include <vector>
// 	namespace ft = std;
// #else
// #include <map.hpp>
// #include <stack.hpp>

#include "vector/Vector.hpp"
// #endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
    int idx;
    char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

#define YELLOW "\033[0;33m"
#define NOCOL "\033[0m"
// template <typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
//     MutantStack() {}
//     MutantStack(const MutantStack<T> &src) { *this = src; }
//     MutantStack<T> &operator=(const MutantStack<T> &rhs)
//     {
//         this->c = rhs.c;
//         return *this;
//     }
//     ~MutantStack() {}

//     typedef typename ft::stack<T>::container_type::iterator iterator;

//     iterator begin() { return this->c.begin(); }
//     iterator end() { return this->c.end(); }
// };

int main()
{
    return (0);
}