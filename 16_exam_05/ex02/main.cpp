#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"

int main(void)
{
    Warlock richard("Richard", "foo");
    richard.setTitle("Hello, I'm Richard the Warlock!");
    BrickWall model1;

    Polymorph *polymorph = new Polymorph();
    TargetGenerator tarGen;

    tarGen.learnTargetType(&model1);
    richard.learnSpell(polymorph);

    Fireball *fireball = new Fireball();

    richard.learnSpell(fireball);

    ATarget *wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

    richard.introduce();
    richard.launchSpell("Polymorph", *wall);
    richard.launchSpell("Fireball", *wall);

    richard.forgetSpell("Polymorph");
    richard.forgetSpell("Fireball");

    // system("leaks a.out");
}