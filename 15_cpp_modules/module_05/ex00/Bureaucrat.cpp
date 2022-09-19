#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : name("Unnamed"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat parameter constructor called (" << name << ", " << grade << ")" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
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
    this->name = src.getName();
    this->grade = src.getGrade();
    std::cout << "Bureaucrat assignment operator" << std::endl;
    return *this;
}

std::string Bureaucrat::getName(void) const
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
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Bureaucrat was promoted" << std::endl;
    this->grade--;
}

void Bureaucrat::degrade(void)
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat was degraded" << std::endl;
    this->grade++;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, Bureaucrat const &std)
{
    std::cout << std.getName() << ", bureaucrat grade " << std.getGrade() << std::endl;
    return os;
}
