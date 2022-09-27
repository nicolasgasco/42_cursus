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

    Form *makePardon(std::string const &target);
    Form *makeRobotomy(std::string const &target);
    Form *makeShrubbery(std::string const &target);

private:
    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Form not found");
        }
    };
};

#endif