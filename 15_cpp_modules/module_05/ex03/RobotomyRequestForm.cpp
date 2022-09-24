#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy", 72, 45)
{
    std::cout << BLUE << "RobotomyRequestForm default constructor called" << NOCOL << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(target, 72, 45)
{
    std::cout << BLUE << "RobotomyRequestForm parameter constructor called (" << name << ", sign: " << gradeToSign << ", exec: " << gradeToExec << ")" << NOCOL << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src.getName(), 72, 45)
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
    return *this;
}

void RobotomyRequestForm::action(Bureaucrat const &executor) const
{
    srand(time(NULL));
    int successfullDrills = 0;
    for (int i = 0; i < 6; i++)
    {
        std::cout << BLUE << "* drilling noises *";
        if ((rand() % 2) == 1)
        {
            std::cout << " ✅" << NOCOL << std::endl;
            successfullDrills++;
        }
        else
            std::cout << " ❌" << NOCOL << std::endl;
    }
    if (successfullDrills >= 3)
        std::cout << BLUE << executor.getName() << " has been successfully lobotomized" << NOCOL << std::endl;
    else
        std::cout << BLUE << "It was not possible to lobotomize " << executor.getName() << NOCOL << std::endl;
}
