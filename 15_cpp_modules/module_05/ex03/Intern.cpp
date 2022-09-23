#include "Intern.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include "Form.hpp"

Intern::Intern(void)
{
    std::cout << PURPLE << "Intern default constructor called" << NOCOL << std::endl;
}

Intern::Intern(Intern const &src)
{
    std::cout << PURPLE << "Intern copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Intern::~Intern(void)
{
    std::cout << PURPLE << "Intern destructor called" << NOCOL << std::endl;
}

Intern &Intern::operator=(Intern const &src)
{
    std::cout << PURPLE << "Intern assignment operator (" << &src << ")" << NOCOL << std::endl;
    return *this;
}

Form *Intern::makeForm(std::string form, std::string target)
{
    Bureaucrat *targetBureaucrat = new Bureaucrat(target, 1);
    std::cout << PURPLE << "Intern creates <form>" << NOCOL << std::endl;

    std::string formTypes[] = {"pardon", "robotomy", "shrubbery"};

    for (unsigned long i = 0; i < (sizeof(formTypes) / sizeof(std::string)); i++)
    {
        if (formTypes[i] == form)
        {

            std::cout << PURPLE << "Intern creates form " << NOCOL << std::endl;
            return (new PresidentialPardonForm(*targetBureaucrat));
        }
    }
    std::cout << form << std::endl;
    return (new PresidentialPardonForm());
}