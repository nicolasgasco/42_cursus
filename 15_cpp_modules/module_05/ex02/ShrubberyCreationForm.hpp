#ifndef __SHRUBBERY_HPP__
#define __SHRUBBERY_HPP__
#include <iostream>

#define GREEN "\033[0;32m"
#define NOCOL "\033[0m"

#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public virtual Form
{
public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);

    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

    void action(Bureaucrat const &executor) const;
};

#endif