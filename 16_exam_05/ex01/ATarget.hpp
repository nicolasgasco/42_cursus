#ifndef TARGET_HPP
#define TARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
public:
    ATarget(void);
    ATarget(std::string const &type);
    ATarget(ATarget const &src);

    ~ATarget(void);

    ATarget const &operator=(ATarget const &src);

    std::string const &getType(void) const;

    virtual ATarget *clone(void) = 0;

    void getHitBySpell(ASpell const &spell) const;

protected:
    std::string const type;
};

#endif