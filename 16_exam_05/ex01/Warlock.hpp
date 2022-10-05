#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"

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
    void forgetSpell(std::string const &spellType);
    void launchSpell(std::string const &spellName, ATarget &target) const;

private:
    std::string name;
    std::string title;
    std::vector<ASpell *> spells;

    Warlock(void);
    Warlock(Warlock const &src);
    Warlock &operator=(Warlock const &src);
};

#endif