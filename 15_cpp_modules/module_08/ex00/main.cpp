#include <iostream>
#include <iterator>
#include <list>
#include <iomanip>

#include "easyfind.hpp"

#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{
    std::cout << YELLOW << "LIST OF INT:" << NOCOL << std::endl;
    std::cout << "Creating a list of ints and filling it up with random values between 1 and 10: " << std::endl;
    std::list<int> myList;
    srand(time(0));
    for (int i = 0; i < 10; ++i)
        myList.push_back(rand() % 10 + 1);

    std::cout << "Printing list using iterators" << std::endl;
    std::list<int>::iterator it = myList.begin();
    std::list<int>::iterator ite = myList.end();
    for (; it != ite; ++it)
        std::cout << std::right << " " << *it << "\t";
    std::cout << std::endl;

    for (int i = 0; i < 10; ++i)
        std::cout << std::right << "[" << i << "]"
                  << "\t";
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
        std::cout << "Error: " << RED << e << NOCOL << std::endl;
    }

    std::cout << std::endl;
    std::cout << YELLOW << "LIST OF FLOAT:" << NOCOL << std::endl;
    std::cout << "Creating a list of floats and filling it up with random values between 0.0 and 1.0: " << std::endl;
    std::list<float> myListF;
    srand(time(0));
    for (int i = 0; i < 10; ++i)
        myListF.push_back(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)));

    std::cout << "Printing list using iterators" << std::endl;
    std::list<float>::iterator itf = myListF.begin();
    std::list<float>::iterator itef = myListF.end();
    for (; itf != itef; ++itf)
        std::cout << std::right << std::setprecision(2) << *itf << "\t";
    std::cout << std::endl;

    for (int i = 0; i < 10; ++i)
        std::cout << std::right << "[" << i << "]"
                  << "\t";
    std::cout << std::endl;

    std::cout << std::endl;
    float randFloat = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX));
    std::cout << "Trying easyfind function with value of " << randFloat << ":" << std::endl;
    try
    {
        easyfind(myListF, randFloat);
    }
    catch (const char *e)
    {
        std::cout << "Error: " << RED << e << NOCOL << std::endl;
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "LIST OF CHAR:" << NOCOL << std::endl;
    std::list<char> myListC;
    srand(time(0));
    for (int i = 0; i < 10; ++i)
        myListC.push_back('a' + rand() % 26);

    std::cout << "Printing list using iterators" << std::endl;
    std::list<char>::iterator itc = myListC.begin();
    std::list<char>::iterator itec = myListC.end();
    for (; itc != itec; ++itc)
        std::cout << std::right << *itc << "\t";
    std::cout << std::endl;

    for (int i = 0; i < 10; ++i)
        std::cout << std::right << "[" << i << "]"
                  << "\t";
    std::cout << std::endl;

    std::cout << std::endl;
    char randChar = static_cast<char>('a' + rand() % 26);
    std::cout << "Trying easyfind function with value of " << randChar << ":" << std::endl;
    try
    {
        easyfind(myListC, randChar);
    }
    catch (const char *e)
    {
        std::cout << "Error: " << RED << e << NOCOL << std::endl;
    }
    std::cout << std::endl;
    return (0);
}