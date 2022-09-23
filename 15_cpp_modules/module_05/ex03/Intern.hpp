#ifndef __INTERN_HPP__
#define __INTERN_HPP__
#include <iostream>

#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

#include "Form.hpp"

class Intern
{
public:
    Intern(void);
    Intern(Intern const &src);

    ~Intern(void);

    Intern &operator=(Intern const &src);

    Form *makeForm(std::string form, std::string target);
};

#endif