#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__
#include <iostream>

#define CYAN "\033[1;36m"
#define NOCOL "\033[0m"

class Bureaucrat
{
public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &src);

    ~Bureaucrat(void);

    Bureaucrat &operator=(Bureaucrat const &src);

    std::string const &getName(void) const;
    int getGrade(void) const;

    void promote(void);
    void degrade(void);

private:
    std::string const name;
    int grade;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Grade too high");
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Grade too low");
        }
    };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &std);

#endif