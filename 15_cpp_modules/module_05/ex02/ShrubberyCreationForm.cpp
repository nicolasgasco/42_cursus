#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery", 145, 137)
{
    std::cout << GREEN << "ShrubberyCreationForm default constructor called" << NOCOL << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat const &target) : Form("Shrubbery", 145, 137)
{
    this->target = &target;
    std::cout << GREEN << "ShrubberyCreationForm parameter constructor called (" << name << ", sign: " << gradeToSign << ", exec: " << gradeToExec << ")" << NOCOL << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form("Shrubbery", 145, 137)
{
    std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << NOCOL << std::endl;
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << GREEN << "ShrubberyCreationForm destructor called" << NOCOL << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    std::cout << GREEN << "ShrubberyCreationForm assignment operator (" << src.getName() << ")" << NOCOL << std::endl;
    this->target = src.getTarget();
    return *this;
}

Bureaucrat const *ShrubberyCreationForm::getTarget(void) const
{
    return this->target;
}

void ShrubberyCreationForm::action(void) const
{
    if (!this->target)
        std::cout << GREEN << "Impossible to execute. No target" << NOCOL << std::endl;

    std::string fileName = target->getName() + "_shrubbery";
    std::ofstream shrubberyFile;
    shrubberyFile.open(fileName);
    shrubberyFile << "                                                         .\n"
                     "                                          .         ;  \n"
                     "             .              .              ;%     ;;   \n"
                     "               ,           ,                :;%  %;   \n"
                     "                :         ;                   :;%;'     .,   \n"
                     "       ,.        %;     %;            ;        %;'    ,;\n"
                     "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
                     "          %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
                     "           ;%;      %;        ;%;        % ;%;  ,%;'\n"
                     "            `%;.     ;%;     %;'         `;%%;.%;'\n"
                     "             `:;%.    ;%%. %@;        %; ;@%;%'\n"
                     "                `:%;.  :;bd%;          %;@%;'\n"
                     "                  `@%:.  :;%.         ;@@%;'   \n"
                     "                    `@%.  `;@%.      ;@@%;         \n"
                     "                      `@%%. `@%%    ;@@%;        \n"
                     "                        ;@%. :@%%  %@@%;       \n"
                     "                          %@bd%%%bd%%:;     \n"
                     "                            #@%%%%%:;;\n"
                     "                            %@@%%%::;\n"
                     "                            %@@@%(o);  . '         \n"
                     "                            %@@@o%;:(.,'         \n"
                     "                        `.. %@@@o%::;         \n"
                     "                           `)@@@o%::;         \n"
                     "                            %@@(o)::;        \n"
                     "                           .%@@@@%::;         \n"
                     "                           ;%@@@@%::;.          \n"
                     "                          ;%@@@@%%:;;;. \n"
                     "                      ...;%@@@@@%%:;;;;,.. \n";
    shrubberyFile.close();
    std::cout << GREEN << this->target->getName() << " requested a tree" << NOCOL << std::endl;
}
