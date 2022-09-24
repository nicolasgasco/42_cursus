#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{
    std::cout << "Creating bureaucrats:" << std::endl;
    Bureaucrat max("Max", 1);
    std::cout << max << std::endl;

    Bureaucrat min("Min", 150);
    std::cout << min << std::endl;

    std::cout << "Creating a Presidential Pardon form:" << std::endl;
    PresidentialPardonForm *pardon = new PresidentialPardonForm("pardon");
    std::cout << *pardon << std::endl;

    std::cout << "Sign a form without a high enough grade:" << std::endl;
    min.signForm(*pardon);
    std::cout << *pardon << std::endl;

    std::cout << "Sign a form with a high enough grade:" << std::endl;
    max.signForm(*pardon);
    std::cout << *pardon << std::endl;

    std::cout << "Executing a form without a high enough grade:" << std::endl;
    min.executeForm(*pardon);
    std::cout << std::endl;

    std::cout << "Executing a form with a high enough grade:" << std::endl;
    max.executeForm(*pardon);
    std::cout << std::endl;

    std::cout << "Creating a Robotomy Request form:" << std::endl;
    RobotomyRequestForm *robot = new RobotomyRequestForm("robotomy");
    std::cout << *robot << std::endl;

    std::cout << "Sign a form with a high enough grade:" << std::endl;
    max.signForm(*robot);
    std::cout << *robot << std::endl;

    std::cout << "Executing a form without a high enough grade:" << std::endl;
    min.executeForm(*robot);
    std::cout << std::endl;

    std::cout << "Executing a form with a high enough grade:" << std::endl;
    max.executeForm(*robot);
    std::cout << std::endl;

    std::cout << "Creating a Shrubbery Creation form:" << std::endl;
    ShrubberyCreationForm *shrub = new ShrubberyCreationForm("shrubbery");
    std::cout << *shrub << std::endl;

    std::cout << "Sign a form with a high enough grade:" << std::endl;
    max.signForm(*shrub);
    std::cout << *shrub << std::endl;

    std::cout << "Executing a form without a high enough grade:" << std::endl;
    min.executeForm(*shrub);
    std::cout << std::endl;

    std::cout << "Executing a form with a high enough grade:" << std::endl;
    max.executeForm(*shrub);
    std::cout << std::endl;

    delete pardon;
    delete robot;
    delete shrub;
    std::cout << std::endl;

    return (0);
}