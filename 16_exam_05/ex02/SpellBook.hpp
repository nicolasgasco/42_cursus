#pragma once

#include <iostream>

#include <list>

class ASpell;

class SpellBook
{
public:
    SpellBook(void);
    virtual ~SpellBook(void);

    void learnSpell(ASpell *);
    void forgetSpell(std::string const &);
    ASpell *createSpell(std::string const &);

protected:
    std::list<ASpell *> spells;

    SpellBook(SpellBook const &src);
    SpellBook const &operator=(SpellBook const &src);
};
