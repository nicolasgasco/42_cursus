#ifndef SPELL_HPP
#define SPELL_HPP

#include <iostream>

class ATarget;

class ASpell
{
public:
    ASpell(std::string const &name, std::string const &effects);
    virtual ~ASpell(void);

    std::string const &getName(void) const;
    std::string const &getEffects(void) const;

    virtual ASpell *clone(void) const = 0;

    void launch(ATarget const &target) const;

protected:
    std::string name;
    std::string effects;

    ASpell(void);
    ASpell(ASpell const &src);
    ASpell const &operator=(ASpell const &src);
};

#endif