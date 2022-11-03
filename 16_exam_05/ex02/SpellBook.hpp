#ifndef SPELL_HPP
#define SPELL_HPP

#include <iostream>

class ATarget;

class SpellBook
{
public:
    SpellBook(std::string const &name, std::string const &effects);
    virtual ~SpellBook(void);

    std::string const &getName(void) const;
    std::string const &getEffects(void) const;

    virtual SpellBook *clone(void) const = 0;

    void launch(ATarget const &target) const;

protected:
    std::string name;
    std::string effects;

    SpellBook(void);
    SpellBook(SpellBook const &src);
    SpellBook const &operator=(SpellBook const &src);
};

#endif