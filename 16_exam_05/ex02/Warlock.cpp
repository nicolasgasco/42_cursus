#include "Warlock.hpp"

#include <iostream>

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(void) {}

Warlock::Warlock(Warlock const &src)
{
    *this = src;
}

Warlock &Warlock::operator=(Warlock const &src)
{
    this->name = src.name;
    this->title = src.title;
    return *this;
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
    std::cout << "Set new title: " << str << std::endl;
    this->title = str;
}

void Warlock::introduce(void) const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    this->book.learnSpell(spell);
}

void Warlock::forgetSpell(std::string const spellName)
{
    this->book.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string const spellName, ATarget &target)
{
    ASpell *spell = this->book.createSpell(spellName);
    if (spell)
        spell->launch(target);
    else
        std::cout << "Spell wasn't learnt yet" << std::endl;
}