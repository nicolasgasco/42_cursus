#include <iostream>
#include <iterator>
#include <list>

#include "easyfind.hpp"

int main(void)
{

    std::cout << "LIST OF INT:" << std::endl;
    std::cout << "Creating a list and filling it up with random values between 1 and 10: " << std::endl;
    std::list<int> myList;
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        myList.push_back(rand() % 10 + 1);
    }

    std::list<int>::iterator it = myList.begin();
    std::list<int>::iterator ite = myList.end();

    for (; it != ite; ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    int randInt = rand() % 10 + 1;
    std::cout << "Trying easyfind function with value of " << randInt << ":" << std::endl;
    try
    {
        easyfind(myList, randInt);
    }
    catch (const char *e)
    {
        std::cout << "Error: " << e << std::endl;
    }
    return (0);
}