#include "ASpell.hpp"
#include "SpellBook.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void) {}


void SpellBook::learnSpell(ASpell *spell) {
    this->spells.push_back(this->createSpell(spell->getName()));
}

void SpellBook::forgetSpell(std::string const &spellName) {
    std::list<ASpell *>::iterator start = this->spells.begin();
    std::list<ASpell *>::iterator end = this->spells.end();
    for (; start != end; ++start)
    {
        if ((*start)->getName() == spellName)
        {
            this->spells.erase(start);
        }
    }
}

ASpell *SpellBook::createSpell(std::string const &spellName) {
    if (spellName == "Fwoosh") {
        return (new Fwoosh());
    } else if (spellName == "Fireball") {
        return (new Fireball());
    } else {
        return (new Polymorph());
    }
}
