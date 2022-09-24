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
    std::string formTypes[] = {"pardon", "robotomy", "shrubbery"};

    std::cout << PURPLE << "Intern tries to create " << form << " form" << NOCOL << std::endl;
    for (unsigned long i = 0; i < (sizeof(formTypes) / sizeof(std::string)); i++)
    {
        if (formTypes[i] == form && i == 0)
            return (new PresidentialPardonForm(target));
        if (formTypes[i] == form && i == 1)
            return (new RobotomyRequestForm(target));
        else if (formTypes[i] == form && i == 2)
            return (new ShrubberyCreationForm(target));
    }
    throw FormNotFoundException();
}