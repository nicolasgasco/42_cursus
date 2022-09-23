#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Pardon", 25, 5)
{
    std::cout << BLUE << "PresidentialPardonForm default constructor called" << NOCOL << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(Bureaucrat const &target) : Form("Pardon", 25, 5)
{
    this->target = &target;
    std::cout << BLUE "PresidentialPardonForm parameter constructor called (" << name << ", " << gradeToSign << ")" << NOCOL << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form("Pardon", 25, 5)
{
    std::cout << BLUE << "PresidentialPardonForm copy constructor called" << NOCOL << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << BLUE << "PresidentialPardonForm destructor called" << NOCOL << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    std::cout << BLUE << "PresidentialPardonForm assignment operator (" << src.getName() << ")" << NOCOL << std::endl;
    this->target = src.getTarget();
    return *this;
}

Bureaucrat const *PresidentialPardonForm::getTarget(void) const
{
    return this->target;
}

void PresidentialPardonForm::action(void) const
{
    if (!this->target)
        std::cout << BLUE << "Impossible to execute. No target" << NOCOL << std::endl;

    std::cout << BLUE << this->target->getName() << " has been pardoned by Zafod Beeblebrox" << NOCOL << std::endl;
}
