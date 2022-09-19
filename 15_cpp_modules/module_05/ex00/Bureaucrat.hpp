#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__
#include <iostream>

class Bureaucrat
{
public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &src);

    ~Bureaucrat(void);

    Bureaucrat &operator=(Bureaucrat const &src);

    std::string getName(void) const;
    int getGrade(void) const;

    void promote(void);
    void degrade(void);

private:
    std::string name;
    int grade;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Grade too high, impossible to promote further");
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Grade too low, impossible to degrade further");
        }
    };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &std);

#endif