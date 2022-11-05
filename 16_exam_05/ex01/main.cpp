#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

#define YELLOW "\033[0;33m"
#define NOCOL "\e[0m"
int main(void)
{
    std::cout << YELLOW << "Creating Richard:" << NOCOL << std::endl;
    Warlock richard("Richard", "the Titled");

    Dummy bob;
    ATarget *clone = bob.clone();

    Fwoosh *fwoosh = new Fwoosh();
    ASpell *otherFwoosh = fwoosh->clone();

    std::cout << YELLOW << std::endl
              << "Learning fwoosh:" << NOCOL << std::endl;
    richard.learnSpell(fwoosh);

    std::cout << YELLOW << std::endl
              << "Relearning the same cloned spell:" << NOCOL << std::endl;
    richard.learnSpell(otherFwoosh);

    std::cout << YELLOW << std::endl
              << "Introducing itself:" << NOCOL << std::endl;
    richard.introduce();

    std::cout << YELLOW << std::endl
              << "Launching spell on Bob:" << NOCOL << std::endl;
    richard.launchSpell("Fwoosh", bob);

    std::cout << YELLOW << std::endl
              << "Launching spell on Bob's clone:" << NOCOL << std::endl;
    richard.launchSpell("Fwoosh", *clone);

    std::cout << YELLOW << std::endl
              << "Forgetting Fwoosh:" << NOCOL << std::endl;
    richard.forgetSpell("Fwoosh");

    std::cout << YELLOW << std::endl
              << "Trying to forget the same spell:" << NOCOL << std::endl;
    richard.forgetSpell("Fwoosh");

    std::cout << YELLOW << std::endl
              << "Trying to launch deleted spell:" << NOCOL << std::endl;
    richard.launchSpell("Fwoosh", bob);

    std::cout << std::endl;
    system("leaks a.out");
}