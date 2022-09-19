#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    std::cout << "Materia default constructor:" << std::endl;
    IMateriaSource *src = new MateriaSource();
    std::cout << std::endl;

    std::cout << "Learning Materias:" << std::endl;
    src->learnMateria(new Ice());
    std::cout << std::endl;

    src->learnMateria(new Ice());
    std::cout << std::endl;

    src->learnMateria(new Cure());
    std::cout << std::endl;

    src->learnMateria(new Cure());
    std::cout << std::endl;

    std::cout << "Too many Materias:" << std::endl;
    src->learnMateria(new Cure());
    std::cout << std::endl;

    std::cout << "New character with name:" << std::endl;
    ICharacter *me = new Character("me");
    std::cout << std::endl;

    std::cout << "Create new 'ice' Materia from MateriaSource:" << std::endl;
    AMateria *tmp;
    tmp = src->createMateria("ice");
    std::cout << std::endl;

    me->equip(tmp);
    std::cout << std::endl;

    std::cout << "Create new 'cure' Materia from MateriaSource:" << std::endl;
    tmp = src->createMateria("cure");
    std::cout << std::endl;

    me->equip(tmp);
    std::cout << std::endl;

    std::cout << "Doing it 3 more times:" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    me->equip(NULL);
    std::cout << std::endl;

    std::cout << "New character Bob:" << std::endl;
    ICharacter *bob = new Character("bob");
    std::cout << std::endl;

    std::cout << "Using Materias with right indexes:" << std::endl;
    me->use(0, *bob);
    std::cout << std::endl;

    me->use(1, *bob);
    std::cout << std::endl;

    me->use(2, *bob);
    std::cout << std::endl;

    me->use(3, *bob);
    std::cout << std::endl;

    std::cout << "Using Materias with wrong indexes:" << std::endl;
    me->use(-1, *bob);
    std::cout << std::endl;

    me->use(4, *bob);
    std::cout << std::endl;

    std::cout << "Unequipping Materias with right index:" << std::endl;
    me->unequip(1);
    std::cout << std::endl;

    me->unequip(0);
    std::cout << std::endl;

    me->unequip(0);
    std::cout << std::endl;

    std::cout << "Unequipping Materias with wrong index:" << std::endl;
    me->unequip(-1);
    std::cout << std::endl;

    delete bob;
    std::cout << std::endl;

    delete me;
    std::cout << std::endl;

    delete src;
    std::cout << std::endl;

    std::cout << "Completeness check:" << std::endl;

    Character origin = Character("Origin");
    std::cout << std::endl;

    std::cout << "Character copy constructor:" << std::endl;
    Character copy = Character(origin);
    std::cout << std::endl;

    std::cout << "Inventory deep check:" << std::endl;
    origin.outputInventoryAddress();
    copy.outputInventoryAddress();
    std::cout << std::endl;

    return (0);
}