#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{
    std::cout << "Create forms:" << std::endl;

    std::cout << "Form with parameter constructor:" << std::endl;
    Form *named = new Form("Formy", 70, 70);
    std::cout << *named << std::endl;

    std::cout << "Form with default constructor:" << std::endl;
    Form unnnamed;
    std::cout << unnnamed << std::endl;

    std::cout << "Form with copy constructor:" << std::endl;
    Form copy = *named;
    std::cout << copy << std::endl;

    std::cout << "Creating Bureaucrats:" << std::endl;

    std::cout << "Bureaucrat with level of 1:" << std::endl;
    Bureaucrat max("Max", 1);
    std::cout << max << std::endl;

    std::cout << "Bureaucrat with level of 150:" << std::endl;
    Bureaucrat min("Min", 150);
    std::cout << min << std::endl;

    std::cout << "Signing forms:" << std::endl;

    std::cout << "Form with too low grade:" << std::endl;
    min.signForm(*named);
    std::cout << std::endl;

    std::cout << "Form with high enough grade:" << std::endl;
    max.signForm(*named);
    std::cout << *named << std::endl;

    std::cout << "Faulty forms:" << std::endl;
    std::cout << "Form with grade of 151:" << std::endl;
    try
    {
        Form tooHigh("TooHigh", 151, 151);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Form with grade of 0:" << std::endl;
    try
    {
        Form tooLow("TooLow", 0, 0);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    delete named;
    return (0);
}