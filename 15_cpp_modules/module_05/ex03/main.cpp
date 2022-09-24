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
    std::cout << "Creating Bureaucrat:" << std::endl;
    Bureaucrat max("Max", 1);
    std::cout << max << std::endl;

    Bureaucrat min("Min", 150);
    std::cout << min << std::endl;

    std::cout << "Creating intern:" << std::endl;
    Intern intern;
    std::cout << std::endl;

    std::cout << "Making a Pardon form:" << std::endl;
    Form *pardon = intern.makeForm("pardon", "Ben");
    std::cout << *pardon << std::endl;

    std::cout << "Signing a form without a high enough grade:" << std::endl;
    min.signForm(*pardon);
    std::cout << *pardon << std::endl;

    std::cout << "Signing a form with a high enough grade:" << std::endl;
    max.signForm(*pardon);
    std::cout << *pardon << std::endl;

    std::cout << "Executing a form without a high enough grade:" << std::endl;
    min.executeForm(*pardon);
    std::cout << std::endl;

    std::cout << "Executing a form with a high enough grade:" << std::endl;
    max.executeForm(*pardon);
    std::cout << std::endl;

    std::cout << "Making a Robotomy form:" << std::endl;
    Form *robot = intern.makeForm("robotomy", "Jon");
    std::cout << *robot << std::endl;

    std::cout << "Signing a form without a high enough grade:" << std::endl;
    max.signForm(*robot);
    std::cout << *robot << std::endl;

    std::cout << "Executing a form without a high enough grade:" << std::endl;
    min.executeForm(*robot);
    std::cout << std::endl;

    std::cout << "Executing a form with a high enough grade:" << std::endl;
    max.executeForm(*robot);
    std::cout << std::endl;

    std::cout << "Making a Shrubbery form:" << std::endl;
    Form *shrub = intern.makeForm("shrubbery", "Mary");
    std::cout << *shrub << std::endl;

    std::cout << "Signing a form without a high enough grade:" << std::endl;
    max.signForm(*shrub);
    std::cout << *shrub << std::endl;

    std::cout << "Executing a form without a high enough grade:" << std::endl;
    min.executeForm(*shrub);
    std::cout << std::endl;

    std::cout << "Executing a form with a high enough grade:" << std::endl;
    max.executeForm(*shrub);
    std::cout << std::endl;

    std::cout << "Making a form of a non-existing type:" << std::endl;
    Form *ghost;
    try
    {
        ghost = intern.makeForm("ghost", "Mary");
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
        std::cout << std::endl;

        delete pardon;
        std::cout << std::endl;

        delete robot;
        std::cout << std::endl;

        delete shrub;
        std::cout << std::endl;
        return (0);
    }

    delete ghost;
    std::cout << std::endl;

    delete robot;
    std::cout << std::endl;

    delete pardon;
    std::cout << std::endl;

    return (0);
}