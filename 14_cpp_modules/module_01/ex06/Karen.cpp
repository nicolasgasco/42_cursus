#include "Karen.hpp"
#include <iostream>

Karen::Karen(void)
{
}
Karen::~Karen(void)
{
}

void Karen::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelInt;

    for (size_t i = 0; i < 3; i++)
    {
        if (levels[i].compare(level) == 0)
            levelInt = i + 1;
    }

    enum Level
    {
        debug = 1,
        info,
        warning,
        error
    };

    switch (levelInt)
    {
    case debug:
        this->debug();
    case info:
        this->info();
    case warning:
        this->warning();
    case error:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Karen::debug(void) const
{
    std::cout << "[ DEBUG ]" << std::endl;

    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl
              << std::endl;
}
void Karen::info(void) const
{
    std::cout << "[ INFO ]" << std::endl;

    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl
              << std::endl;
}
void Karen::warning(void) const
{
    std::cout << "[ WARNING ]" << std::endl;

    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl
              << std::endl;
}
void Karen::error(void) const
{
    std::cout << "[ ERROR ]" << std::endl;

    std::cerr << "This is unacceptable, I want to speak to the manager now." << std::endl
              << std::endl;
}
