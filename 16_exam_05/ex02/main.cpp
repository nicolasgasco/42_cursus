#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"

#define YELLOW "\033[0;33m"
#define NOCOL "\e[0m"

int main(void)
{
    std::cout << YELLOW << "Creating new Richard:" << NOCOL << std::endl;
    Warlock richard("Richard", "foo");

    std::cout << std::endl
              << YELLOW << "Setting a title on Richard:" << NOCOL << std::endl;
    richard.setTitle("Hello, I'm Richard the Warlock!");

    std::cout << std::endl
              << YELLOW << "Creating new BrickWall:" << NOCOL << std::endl;
    BrickWall model1;

    std::cout << std::endl
              << YELLOW << "Creating new Polymorph:" << NOCOL << std::endl;
    Polymorph *polymorph = new Polymorph();

    std::cout << std::endl
              << YELLOW << "Creating new TargetGenerator:" << NOCOL << std::endl;
    TargetGenerator tarGen;

    std::cout << std::endl
              << YELLOW << "Learning new target:" << NOCOL << std::endl;
    tarGen.learnTargetType(&model1);

    std::cout << std::endl
              << YELLOW << "Learning non-existent spell:" << NOCOL << std::endl;
    richard.launchSpell("Polymorph", model1);

    std::cout << std::endl
              << YELLOW << "Learning new spell:" << NOCOL << std::endl;
    richard.learnSpell(polymorph);

    std::cout << std::endl
              << YELLOW << "Creating new Fireball:" << NOCOL << std::endl;
    Fireball *fireball = new Fireball();

    std::cout << std::endl
              << YELLOW << "Learning new spell:" << NOCOL << std::endl;
    richard.learnSpell(fireball);

    std::cout << std::endl
              << YELLOW << "Creating new target:" << NOCOL << std::endl;
    ATarget *wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

    std::cout << std::endl
              << YELLOW << "Richard introducing himself:" << NOCOL << std::endl;
    richard.introduce();

    std::cout << std::endl
              << YELLOW << "Launching Polymorph spell:" << NOCOL << std::endl;
    richard.launchSpell("Polymorph", *wall);

    std::cout << std::endl
              << YELLOW << "Launching Fireball spell:" << NOCOL << std::endl;
    richard.launchSpell("Fireball", *wall);

    std::cout << std::endl
              << YELLOW << "Forgetting Polymorph spell:" << NOCOL << std::endl;
    richard.forgetSpell("Polymorph");

    std::cout << std::endl
              << YELLOW << "Forgetting Fireball spell:" << NOCOL << std::endl;
    richard.forgetSpell("Fireball");

    system("leaks a.out");
}