#include "Karen.hpp"
#include <iostream>

Karen::Karen(void)
{
    mtd_ptr debug_ptr;
    
    debug_ptr.id = "DEBUG";
    debug_ptr.func_ptr = &Karen::debug;
    this->ptr_arr[0] = debug_ptr;

    debug_ptr.id = "INFO";
    debug_ptr.func_ptr = &Karen::info;
    this->ptr_arr[1] = debug_ptr;

    debug_ptr.id = "WARNING";
    debug_ptr.func_ptr = &Karen::warning;
    this->ptr_arr[2] = debug_ptr;

    debug_ptr.id = "ERROR";
    debug_ptr.func_ptr = &Karen::error;
    this->ptr_arr[3] = debug_ptr;
}
Karen::~Karen(void)
{
}

void Karen::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->ptr_arr[i].id.compare(level) == 0)
        {
            std::cout << "[" << this->ptr_arr[i].id << "]" << std::endl;
            (this->*ptr_arr[i].func_ptr)();
            return;
        }
    }
    std::cerr << "Wrong level identifier" << std::endl;
    return;
}

void Karen::debug(void) const
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}
void Karen::info(void) const
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}
void Karen::warning(void) const
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}
void Karen::error(void) const
{
    std::cerr << "This is unacceptable, I want to speak to the manager now." << std::endl;
}