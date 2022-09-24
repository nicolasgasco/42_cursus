#include "Form.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

Form::Form(void) : name("Unnamed"), isSigned(false), gradeToSign(1), gradeToExec(1)
{
    std::cout << YELLOW << "Form default constructor called" << NOCOL << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    std::cout << YELLOW "Form parameter constructor called (" << name << ", sign: " << gradeToSign << ", exec: " << gradeToExec << ")" << NOCOL << std::endl;
}

Form::Form(Form const &src) : name(src.getName()), gradeToSign(src.getGradeToSign()), gradeToExec(src.getGradeToExec())
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
    this->isSigned = src.getIsSigned();
    std::cout << YELLOW << "Form assignment operator" << NOCOL << std::endl;
    return *this;
}

std::string const &Form::getName(void) const
{
    return this->name;
}

bool Form::getIsSigned(void) const
{
    return this->isSigned;
}

int const &Form::getGradeToSign(void) const
{
    return this->gradeToSign;
}

int const &Form::getGradeToExec(void) const
{
    return this->gradeToExec;
}

void Form::beSigned(Bureaucrat const &signee)
{
    if ((signee.getGrade() > this->gradeToSign))
    {
        throw Form::GradeTooLowException();
        return;
    }
    this->isSigned = true;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, Form const &std)
{
    std::cout << YELLOW << "_______________________________" << std::endl;
    std::cout << "| Name            | " << std::setw(10) << std.getName() << "|" << std::endl;
    std::cout << "| Signed          | " << std::setw(10) << (std.getIsSigned() ? "yes" : "no") << std::setfill(' ') << "|" << std::endl;
    std::cout << "| Sign grade      | " << std::setw(10) << std.getGradeToSign() << "|" << std::endl;
    std::cout << "| Exec grade      | " << std::setw(10) << std.getGradeToExec() << "|" << std::endl;
    std::cout << "-------------------------------" << NOCOL << std::endl;
    return os;
}
