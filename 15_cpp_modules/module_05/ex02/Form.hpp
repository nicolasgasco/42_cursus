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
    Form(std::string name, int gradeToSign, int gradeToExec);
    Form(Form const &src);

    virtual ~Form(void);

    Form &operator=(Form const &src);

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int const &getGradeToSign(void) const;
    int const &getGradeToExec(void) const;

    void beSigned(Bureaucrat const &signee);
    void execute(Bureaucrat const &executor) const;
    virtual void action(Bureaucrat const &executor) const = 0;

protected:
    std::string name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExec;

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Grade too low");
        }
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Form is not signed");
        }
    };
};

std::ostream &operator<<(std::ostream &os, Form const &std);

#endif