#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
#include <map>
#include <stack>
#include <vector>
#include <iterator>
// 	namespace ft = std;
// #else
// #include <map.hpp>
// #include <stack.hpp>

#include "vector.hpp"
#include "algorithms.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
// #endif

#include <stdlib.h>

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

#include <iostream>
int main()
{
    ft::vector<int> own;
    own.reserve(1);
    own.push_back(1);
    std::vector<int> original;
    original.reserve(1);
    original.push_back(1);

    system("leaks ft_containers");
    return 0;
}