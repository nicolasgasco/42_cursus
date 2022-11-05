#pragma once

#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
public:
    Warlock(std::string const &name, std::string const &title);

    ~Warlock(void);

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;

    void setTitle(std::string const &str);

    void introduce(void) const;

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const spellName);
    void launchSpell(std::string const spellName, ATarget &target);

private:
    std::string name;
    std::string title;

    SpellBook book;

    Warlock(void);
    Warlock(Warlock const &src);
    Warlock &operator=(Warlock const &src);
};
