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

#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "algorithms.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "bst.hpp"
#include "pair.hpp"
// #endif

#include <stdlib.h>

#define YELLOW "\033[0;33m"
#define NOCOL "\033[0m"

using namespace std;

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
	// ft::vector<int> v1(100, 1);

	// ft::vector<int> v2;
	// v2.push_back(101);
	// v2.push_back(102);
	// v2.push_back(103);
	// v2.push_back(104);
	// v2.push_back(105);

	// v1.insert(v1.begin() + 0, v2.begin(), v2.end());
	// int i = 0;
	// for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it, ++i)
	// 	std::cout << *it << " (" << i << "), ";
	// std::cout << std::endl;

	// std::vector<int> vo1(100, 1);

	// std::cout << std::endl;

	// std::vector<int> vo2;
	// vo2.push_back(101);
	// vo2.push_back(102);
	// vo2.push_back(103);
	// vo2.push_back(104);
	// vo2.push_back(105);

	// vo1.insert(vo1.begin() + 0, vo2.begin(), vo2.end());
	// int i2 = 0;
	// for (std::vector<int>::iterator it = vo1.begin(); it != vo1.end(); ++it, ++i2)
	// 	std::cout << *it << " (" << i2 << "), ";

	// init

	// std::vector<int> v1(100, 1);
	// std::vector<int> v4(10, 5);

	// ft::vector<int> v2(4050000, 2);
	// ft::vector<int> v3(2600, 5);

	// // v1.insert(v1.end() + 1, v4.begin(), v4.end());
	// v2.insert(v2.begin() -1, v3.begin(), v3.end());
	// for (int i = 0; i < int(v2.size()); ++i)
	// {
	// 	std::cout << v2[i] << ", ";
	// }

	// ft::bst<std::string, int> myBst(ft::pair<std::string, int>("CCC", 42));

	// std::cout << "Inserting values" << std::endl;
	// myBst.insert(ft::pair<std::string, int>("DDD", 42));
	// myBst.insert(ft::pair<std::string, int>("AAA", 42));
	// myBst.insert(ft::pair<std::string, int>("ZZZ", 42));
	// myBst.insert(ft::pair<std::string, int>("AAAA", 42));
	// myBst.insert(ft::pair<std::string, int>("A", 42));

	// std::cout << "First node: " << myBst.search(ft::pair<std::string, int>("DDD", 42))->data() << std::endl;
	// std::cout << "Second node: " << myBst.search("ZZZ")->data() << std::endl;

	// myBst.inorder();

	// ft::bst<std::string, int> second(ft::pair<std::string, int>("CCC", 42));
	// ft::bst<std::string, int> other(second);
	// second.inorder();
	// other.inorder();

	// ft::vector<ft::pair<std::string, int> > myVector;
	// myVector.push_back(ft::pair<std::string, int>("ciao", 42));
	// myVector.push_back(ft::pair<std::string, int>("miao", 10));
	// myVector.push_back(ft::pair<std::string, int>("biao", 200));
	// ft::map<std::string, int> myMap(myVector.begin(), myVector.end());

	ft::map<std::string, int> seed;
	seed.insert(ft::pair<std::string, int>("one", 1));
	ft::map<std::string, int> const own = const_cast<ft::map<std::string, int> const &>(seed);
	ft::map<std::string, int>::const_iterator ownIt = own.begin();

	return 0;
}