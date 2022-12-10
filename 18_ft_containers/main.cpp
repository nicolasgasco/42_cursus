#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
#include <map>
#include <stack>
#include <vector>
#include <iterator>
#include <list>
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
	ft::vector<int> v1(100, 1);

	ft::vector<int> v2;
	v2.push_back(101);
	v2.push_back(102);
	v2.push_back(103);
	v2.push_back(104);
	v2.push_back(105);

	v1.insert(v1.begin() + 0, v2.begin(), v2.end());
	int i = 0;
	for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it, ++i)
		std::cout << *it << " (" << i << "), ";
	std::cout << std::endl;

	std::vector<int> vo1(100, 1);

	std::cout << std::endl;

	std::vector<int> vo2;
	vo2.push_back(101);
	vo2.push_back(102);
	vo2.push_back(103);
	vo2.push_back(104);
	vo2.push_back(105);

	vo1.insert(vo1.begin() + 0, vo2.begin(), vo2.end());
	int i2 = 0;
	for (std::vector<int>::iterator it = vo1.begin(); it != vo1.end(); ++it, ++i2)
		std::cout << *it << " (" << i2 << "), ";
	return 0;
}