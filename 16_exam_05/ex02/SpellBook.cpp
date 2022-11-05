#include "ASpell.hpp"
#include "SpellBook.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void)
{
    std::list<ASpell *>::iterator start = this->spells.begin();
    std::list<ASpell *>::iterator end = this->spells.end();
    for (; start != end; ++start)
        delete *start;
    this->spells.clear();
}

void SpellBook::learnSpell(ASpell *spell)
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

void SpellBook::forgetSpell(std::string const &spellName)
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

ASpell *SpellBook::createSpell(std::string const &spellName)
{
    std::list<ASpell *>::iterator start = this->spells.begin();
    std::list<ASpell *>::iterator end = this->spells.end();
    for (; start != end; ++start)
    {
        if ((*start)->getName() == spellName)
            break;
    }
    return (*start);
}
