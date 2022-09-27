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

Form *Intern::makePardon(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

Form *Intern::makeRobotomy(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

Form *Intern::makeShrubbery(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string form, std::string target)
{
    std::string formTypes[] = {"pardon", "robotomy", "shrubbery"};

    Form *(Intern::*actions[3])(std::string const &) = {
        &Intern::makePardon, &Intern::makeRobotomy, &Intern::makeShrubbery

    };

    std::cout << PURPLE << "Intern tries to create " << form << " form" << NOCOL << std::endl;
    for (unsigned long i = 0; i < (sizeof(formTypes) / sizeof(std::string)); i++)
    {
        if (formTypes[i] == form)
            return ((this->*(actions[i]))(target));
    }
    throw FormNotFoundException();
}