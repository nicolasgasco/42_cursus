#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
    this->gradeToSign = 25;
    this->gradeToExec = 5;
    std::cout << YELLOW << "PresidentialPardonForm default constructor called" << NOCOL << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(Bureaucrat const &target)
{
    this->gradeToSign = 25;
    this->gradeToExec = 5;
    this->target = &target;
    std::cout << YELLOW "PresidentialPardonForm parameter constructor called (" << name << ", " << gradeToSign << ")" << NOCOL << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
    this->gradeToSign = 25;
    this->gradeToExec = 5;
    std::cout << YELLOW << "PresidentialPardonForm copy constructor called" << NOCOL << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << YELLOW << "PresidentialPardonForm destructor called" << NOCOL << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    std::cout << YELLOW << "PresidentialPardonForm assignment operator (" << src.getName() << ")" << NOCOL << std::endl;
    this->target = src.getTarget();
    return *this;
}

Bureaucrat const *PresidentialPardonForm::getTarget(void) const
{
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    std::cout << executor.getName();
    return;
}
