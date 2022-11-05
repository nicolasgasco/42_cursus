#pragma once

#include <iostream>

class ASpell;

class ATarget
{
public:
    ATarget(std::string const &type);
    virtual ~ATarget(void);

    std::string const &getType(void) const;

    virtual ATarget *clone(void) const = 0;

    void getHitBySpell(ASpell const &spell) const;

protected:
    std::string type;

    ATarget(void);
    ATarget(ATarget const &src);
    ATarget const &operator=(ATarget const &src);
};
