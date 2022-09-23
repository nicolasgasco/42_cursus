#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy", 72, 45)
{
    std::cout << BLUE << "RobotomyRequestForm default constructor called" << NOCOL << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat const &target) : Form("Robotomy", 72, 45)
{
    this->target = &target;
    std::cout << BLUE << "RobotomyRequestForm parameter constructor called (" << name << ", sign: " << gradeToSign << ", exec: " << gradeToExec << ")" << NOCOL << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form("Robotomy", 72, 45)
{
    std::cout << BLUE << "RobotomyRequestForm copy constructor called" << NOCOL << std::endl;
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << BLUE << "RobotomyRequestForm destructor called" << NOCOL << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    std::cout << BLUE << "RobotomyRequestForm assignment operator (" << src.getName() << ")" << NOCOL << std::endl;
    this->target = src.getTarget();
    return *this;
}

Bureaucrat const *RobotomyRequestForm::getTarget(void) const
{
    return this->target;
}

void RobotomyRequestForm::action(void) const
{
    if (!this->target)
        std::cout << BLUE << "Impossible to execute. No target" << NOCOL << std::endl;

    srand(time(NULL));
    int successfullDrills = 0;
    for (int i = 0; i < 6; i++)
    {
        std::cout << BLUE << "* drilling noises *" << NOCOL << std::endl;
        if ((rand() % 2) == 1)
            successfullDrills++;
    }
    if (successfullDrills >= 3)
        std::cout << BLUE << this->target->getName() << " has been successfully lobotomized" << NOCOL << std::endl;
    else
        std::cout << BLUE << "It was not possible to lobotomize " << this->target->getName() << NOCOL << std::endl;
}
