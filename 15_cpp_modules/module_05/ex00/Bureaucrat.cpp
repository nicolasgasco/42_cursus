#include "Bureaucrat.hpp"
#include <iostream>
#include <iomanip>

Bureaucrat::Bureaucrat(void) : name("Unnamed"), grade(150)
{
    std::cout << CYAN << "Bureaucrat default constructor called" << NOCOL << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << CYAN << "Bureaucrat parameter constructor called (" << name << ", " << grade << ")" << NOCOL << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.getName())
{
    std::cout << CYAN "Bureaucrat copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << CYAN "Bureaucrat destructor called" << NOCOL << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    this->grade = src.getGrade();
    std::cout << CYAN "Bureaucrat assignment operator" << NOCOL << std::endl;
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
        throw Bureaucrat::GradeTooHighException();
    std::cout << CYAN << "Bureaucrat was promoted" << NOCOL << std::endl;
    this->grade--;
}

void Bureaucrat::degrade(void)
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << CYAN << "Bureaucrat was degraded" << NOCOL << std::endl;
    this->grade++;
}

// Stream oeprator
std::ostream &operator<<(std::ostream &os, Bureaucrat const &std)
{
    std::cout << CYAN << "_______________________________" << std::endl;
    std::cout << "| Name            | " << std::setw(10) << std.getName() << "|" << std::endl;
    std::cout << "| Grade           | " << std::setw(10) << std.getGrade() << std::setfill(' ') << "|" << std::endl;
    std::cout << "-------------------------------" << NOCOL << std::endl;
    return os;
}
