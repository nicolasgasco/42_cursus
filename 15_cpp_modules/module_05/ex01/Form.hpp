#ifndef __FORM_HPP__
#define __FORM_HPP__
#include <iostream>

#define YELLOW "\033[1;33m"
#define NOCOL "\033[0m"

class Bureaucrat;

class Form
{
public:
    Form(void);
    Form(std::string name, int grade);
    Form(Form const &src);

    ~Form(void);

    Form &operator=(Form const &src);

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;

    void beSigned(Bureaucrat const &signee);

private:
    std::string name;
    bool isSigned;
    int gradeToSign;

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Grade too low");
        }
    };
};

std::ostream &operator<<(std::ostream &os, Form const &std);

#endif