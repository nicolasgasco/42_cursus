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
    std::list<ASpell *>::iterator start = this->spells.begin();
    std::list<ASpell *>::iterator end = this->spells.end();
    for (; start != end; ++start)
    {
        delete *start;
    }
    this->spells.clear();
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

void Warlock::learnSpell(ASpell *spell)
{
    std::list<ASpell *>::iterator start = this->spells.begin();
    std::list<ASpell *>::iterator end = this->spells.end();
    for (; start != end; ++start)
    {
        if ((*start)->getName() == spell->getName())
        {
            std::cout << "Spell already learnt" << std::endl;
            return;
        }
    }
    this->spells.push_back(spell->clone());
    std::cout << "Learnt spell " << spell->getName() << std::endl;
}

void Warlock::forgetSpell(std::string const spellName)
{
    std::list<ASpell *>::iterator start = this->spells.begin();
    std::list<ASpell *>::iterator end = this->spells.end();
    for (; start != end; ++start)
    {
        if ((*start)->getName() == spellName)
        {
            std::cout << "Spell deleted: " << spellName << std::endl;
            delete *start;
            this->spells.erase(start);
            return;
        }
    }
    std::cout << "No spell to forget" << std::endl;
}

void Warlock::launchSpell(std::string const spellName, ATarget &target)
{
    std::list<ASpell *>::iterator start = this->spells.begin();
    std::list<ASpell *>::iterator end = this->spells.end();
    for (; start != end; ++start)
    {
        if ((*start)->getName() == spellName)
        {
            (*start)->launch(target);
            return;
        }
    }
    std::cout << "No spell to launch" << std::endl;
}