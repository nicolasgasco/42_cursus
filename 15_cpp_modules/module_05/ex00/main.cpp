#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{

    Bureaucrat first;
    std::cout << first << std::endl;

    Bureaucrat high("Korben", 1);
    std::cout << high << std::endl;

    Bureaucrat copy = high;
    std::cout << copy << std::endl;

    try
    {
        high.promote();
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
    }
    std::cout << std::endl;
    high.degrade();
    std::cout << high << std::endl;

    Bureaucrat low("Dallas", 150);
    std::cout << low << std::endl;

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
    try
    {
        Bureaucrat tooHigh("TooHigh", 151);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat tooLow("TooLow", 0);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
    }
    std::cout << std::endl;
    return (0);
}