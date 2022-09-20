#include "Form.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

Form::Form(void) : name("Unnamed"), isSigned(false), gradeToSign(1)
{
    std::cout << YELLOW << "Form default constructor called" << NOCOL << std::endl;
}

Form::Form(std::string name, int gradeToSign) : name(name), isSigned(false), gradeToSign(gradeToSign)
{
    std::cout << YELLOW "Form parameter constructor called (" << name << ", " << gradeToSign << ")" << NOCOL << std::endl;
}

Form::Form(Form const &src)
{
    std::cout << YELLOW << "Form copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Form::~Form(void)
{
    std::cout << YELLOW << "Form destructor called" << NOCOL << std::endl;
}

Form &Form::operator=(Form const &src)
{
    this->name = src.getName();
    this->gradeToSign = src.getGradeToSign();
    this->isSigned = src.getIsSigned();
    std::cout << YELLOW << "Form assignment operator" << NOCOL << std::endl;
    return *this;
}

std::string Form::getName(void) const
{
    return this->name;
}

bool Form::getIsSigned(void) const
{
    return this->isSigned;
}

int Form::getGradeToSign(void) const
{
    return this->gradeToSign;
}

void Form::beSigned(Bureaucrat const &signee)
{
    if ((signee.getGrade() > this->gradeToSign))
        throw Form::GradeTooLowException();
    this->isSigned = true;
    return;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, Form const &std)
{
    std::cout << YELLOW << "_______________________________" << std::endl;
    std::cout << "| Name            | " << std::setw(10) << std.getName() << "|" << std::endl;
    std::cout << "| Signed          | " << std::setw(10) << (std.getIsSigned() ? "yes" : "no") << std::setfill(' ') << "|" << std::endl;
    std::cout << "| Required grade  | " << std::setw(10) << std.getGradeToSign() << "|" << std::endl;
    std::cout << "-------------------------------" << NOCOL << std::endl;
    return os;
}
