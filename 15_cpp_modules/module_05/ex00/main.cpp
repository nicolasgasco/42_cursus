#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{

    std::cout << "Bureaucrat with default constructor:" << std::endl;
    Bureaucrat *first = new Bureaucrat();
    std::cout << *first << std::endl;

    std::cout << "Bureaucrat with parameter constructor:" << std::endl;
    Bureaucrat *high = new Bureaucrat("Korben", 1);
    std::cout << *high << std::endl;

    std::cout << "Bureaucrat with copy constructor:" << std::endl;
    Bureaucrat copy = *high;
    std::cout << copy << std::endl;

    std::cout << "Trying to promote Bureaucrat with level of 1:" << std::endl;
    try
    {
        high->promote();
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Trying to degrade Bureaucrat with level of 1:" << std::endl;
    high->degrade();
    std::cout << *high << std::endl;

    std::cout << "Bureaucrat with level of 150" << std::endl;
    Bureaucrat low("Dallas", 150);
    std::cout << low << std::endl;

    std::cout << "Trying to degrade Bureaucrat with level of 150:" << std::endl;
    try
    {
        low.degrade();
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Invalid Bureaucrats:" << std::endl;
    std::cout << "Bureaucrat with grade of 151:" << std::endl;
    try
    {
        Bureaucrat tooHigh("TooHigh", 151);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Bureaucrat with grade of 0:" << std::endl;
    try
    {
        Bureaucrat tooLow("TooLow", 0);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    delete first;
    delete high;
    return (0);
}