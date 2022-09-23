#ifndef __ROBOTOMY_HPP__
#define __ROBOTOMY_HPP__
#include <iostream>

#define BLUE "\033[1;34m"
#define NOCOL "\033[0m"

#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public virtual Form
{
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(Bureaucrat const &target);
    RobotomyRequestForm(RobotomyRequestForm const &src);

    ~RobotomyRequestForm(void);

    RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

    void action(void) const;

    Bureaucrat const *getTarget(void) const;

private:
    Bureaucrat const *target;
};

#endif