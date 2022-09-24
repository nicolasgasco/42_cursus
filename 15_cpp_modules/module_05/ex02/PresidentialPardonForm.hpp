#ifndef __PRESIDENTIAL_HPP__
#define __PRESIDENTIAL_HPP__
#include <iostream>

#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public virtual Form
{
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &src);

    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

    void action(Bureaucrat const &executor) const;
};

#endif