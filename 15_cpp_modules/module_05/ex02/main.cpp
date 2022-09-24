#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{
    Bureaucrat max("Max", 1);
    std::cout << max << std::endl;

    Bureaucrat min("Min", 150);
    std::cout << min << std::endl;

    PresidentialPardonForm pardon("pardon");
    std::cout << pardon << std::endl;

    try
    {
        min.signForm(pardon);
        std::cout << pardon << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Impossible to sign form: " << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    max.signForm(pardon);
    std::cout << pardon << std::endl;

    min.executeForm(pardon);
    std::cout << std::endl;

    max.executeForm(pardon);
    std::cout << std::endl;

    RobotomyRequestForm robot("robotomy");
    std::cout << robot << std::endl;

    max.signForm(robot);
    std::cout << robot << std::endl;

    min.executeForm(robot);
    std::cout << std::endl;

    max.executeForm(robot);
    std::cout << std::endl;

    ShrubberyCreationForm shrub("shrubbery");
    std::cout << shrub << std::endl;

    max.signForm(shrub);
    std::cout << shrub << std::endl;

    min.executeForm(shrub);
    std::cout << std::endl;

    max.executeForm(shrub);
    std::cout << std::endl;

    return (0);
}