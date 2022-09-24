#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery", 145, 137)
{
    std::cout << GREEN << "ShrubberyCreationForm default constructor called" << NOCOL << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(target, 145, 137)
{
    std::cout << GREEN << "ShrubberyCreationForm parameter constructor called (" << name << ", sign: " << gradeToSign << ", exec: " << gradeToExec << ")" << NOCOL << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src.getName(), 145, 137)
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
    return *this;
}

void ShrubberyCreationForm::action(Bureaucrat const &executor) const
{
    std::string fileName = executor.getName() + "_shrubbery";
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
    std::cout << GREEN << executor.getName() << " requested a tree" << NOCOL << std::endl;
}
