#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Pardon", 25, 5)
{
    std::cout << PURPLE << "PresidentialPardonForm default constructor called" << NOCOL << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form(target, 25, 5)
{
    std::cout << PURPLE << "PresidentialPardonForm parameter constructor called (" << name << ", sign: " << gradeToSign << ", exec: " << gradeToExec << ")" << NOCOL << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src.getName(), 25, 5)
{
    std::cout << PURPLE << "PresidentialPardonForm copy constructor called" << NOCOL << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << PURPLE << "PresidentialPardonForm destructor called" << NOCOL << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    std::cout << PURPLE << "PresidentialPardonForm assignment operator (" << src.getName() << ")" << NOCOL << std::endl;
    return *this;
}

void PresidentialPardonForm::action(Bureaucrat const &executor) const
{
    std::cout << PURPLE << executor.getName() << " has been pardoned by Zafod Beeblebrox" << NOCOL << std::endl;
}
