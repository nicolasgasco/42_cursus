#include "Warlock.hpp"

#include <iostream>

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName(void) const
{
    return this->name;
}

std::string const &Warlock::getTitle(void) const
{
    return this->title;
}

void Warlock::setTitle(std::string const &str)
{
    this->title = str;
}

void Warlock::introduce(void) const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
