#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{
    Bureaucrat max("Max", 1);
    std::cout << max << std::endl;

    Bureaucrat min("Min", 150);
    std::cout << min << std::endl;

    PresidentialPardonForm pardon(max);
    std::cout << pardon << std::endl;

    try
    {
        pardon.beSigned(min);
        std::cout << pardon << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Impossible to sign form: " << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    pardon.beSigned(max);
    std::cout << pardon << std::endl;

    min.executeForm(pardon);
    std::cout << std::endl;

    max.executeForm(pardon);
    std::cout << std::endl;

    RobotomyRequestForm robot(max);
    std::cout << robot << std::endl;

    robot.beSigned(max);
    std::cout << robot << std::endl;

    min.executeForm(robot);
    std::cout << std::endl;

    max.executeForm(robot);
    std::cout << std::endl;

    ShrubberyCreationForm shrub(max);
    std::cout << shrub << std::endl;

    shrub.beSigned(max);
    std::cout << shrub << std::endl;

    min.executeForm(shrub);
    std::cout << std::endl;

    max.executeForm(shrub);
    std::cout << std::endl;

    Intern intern;
    std::cout << std::endl;

    intern.makeForm("pardon", "Ben");
    std::cout << std::endl;

    return (0);
}