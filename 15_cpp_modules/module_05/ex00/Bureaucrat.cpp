#include "Bureaucrat.hpp"
#include <iostream>
#include <iomanip>

Bureaucrat::Bureaucrat(void) : name("Unnamed"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    static_cast<std::string>(this->name) = name;
    this->grade = grade;
    std::cout << "Bureaucrat parameter constructor called (" << name << ", " << grade << ")" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.getName())
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    this->grade = src.getGrade();
    std::cout << "Bureaucrat assignment operator" << std::endl;
    return *this;
}

std::string const &Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void Bureaucrat::promote(void)
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat was promoted" << std::endl;
    this->grade--;
}

void Bureaucrat::degrade(void)
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Bureaucrat was degraded" << std::endl;
    this->grade++;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, Bureaucrat const &std)
{
    std::cout << "_______________________________" << std::endl;
    std::cout << "| Name            | " << std::setw(10) << std.getName() << "|" << std::endl;
    std::cout << "| Grade           | " << std::setw(10) << (std.getGrade() ? "yes" : "no") << std::setfill(' ') << "|" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    return os;
}
