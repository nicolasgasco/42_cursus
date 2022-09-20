#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{

    std::cout << "Create forms:" << std::endl;

    Form named = Form("Formy", 70);
    std::cout << named << std::endl;

    Form unnnamed;
    std::cout << unnnamed << std::endl;

    Form copy = named;
    std::cout << copy << std::endl;

    std::cout << "Creating Bureaucrats:" << std::endl;

    std::cout << "High-rank officer:" << std::endl;
    Bureaucrat max("Max", 1);
    std::cout << max << std::endl;

    std::cout << "Low-rank officer:" << std::endl;
    Bureaucrat min("Min", 150);
    std::cout << min << std::endl;

    std::cout << "Signing forms:" << std::endl;
    min.signForm(named);
    std::cout << std::endl;

    max.signForm(named);
    std::cout << std::endl;

    std::cout << named << std::endl;

    return (0);
}