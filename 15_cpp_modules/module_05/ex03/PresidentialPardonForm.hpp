#ifndef __PRESIDENTIAL_HPP__
#define __PRESIDENTIAL_HPP__
#include <iostream>

#define BLUE "\033[1;34m"
#define NOCOL "\033[0m"

#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public virtual Form
{
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(Bureaucrat const &target);
    PresidentialPardonForm(PresidentialPardonForm const &src);

    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

    void action(void) const;

    Bureaucrat const *getTarget(void) const;

private:
    Bureaucrat const *target;
};

#endif