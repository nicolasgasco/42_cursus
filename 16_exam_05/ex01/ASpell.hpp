#ifndef SPELL_HPP
#define SPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
public:
    ASpell(void);
    ASpell(std::string const &name, std::string const &effects);
    ASpell(ASpell const &src);
    virtual ~ASpell(void);

    ASpell const &operator=(ASpell const &src);

    std::string const &getName(void) const;
    std::string const &getEffects(void) const;

    virtual ASpell *clone(void) = 0;

    void launch(ATarget const &target) const;

protected:
    std::string const name;
    std::string const effects;
};

#endif