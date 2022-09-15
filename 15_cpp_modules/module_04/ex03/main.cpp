#include <iostream>
#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

int main(void)
{
    std::cout << "Parameter constructor:" << std::endl;
    AMateria *ice = new Ice("ice");
    std::cout << *ice << std::endl;

    std::cout << "Clone() initialization:" << std::endl;
    AMateria *clone = ice->clone();
    std::cout << *clone << std::endl;

    std::cout << "Type of ice is " << ice->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "New character:" << std::endl;
    Character character("Armin");
    std::cout << std::endl;

    std::cout << "use():" << std::endl;
    ice->use(character);
    std::cout << std::endl;

    delete ice;
    std::cout << std::endl;

    delete clone;
    std::cout << std::endl;
    return (0);
}