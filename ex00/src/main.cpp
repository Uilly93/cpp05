#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/colors.hpp"
#include <iostream>

int main() {
    IMateriaSource *src = new MateriaSource();
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Filling Metaria source with 4 metaria:" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "trying to overfill spellbook metaria" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    src->learnMateria(new Cure());
    src->learnMateria(new Cure());

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "creating Character \"Georges\" and equiping it with 2 metarias:" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    ICharacter *me = new Character("Georges");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Trying to over equip Georges or creating invalid metaria" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    tmp = src->createMateria("water");
    me->equip(tmp);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Georges Attacking new Character Bob:" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    ICharacter *bob = new Character("Bob");
    me->use(0, *bob);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Trying to unequip materia n.0 of Georges inventory and attacking Bob" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    me->unequip(0);
    me->unequip(0);
    me->unequip(0);
    me->use(0, *bob);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Georges Trying unequip or attack Bob with invalid inventory items" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    me->use(42, *bob);
    me->use(-42, *bob);
    me->unequip(-42);
    me->unequip(42);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Testing deep copy" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    Character bobby("deepcopy");
    tmp = src->createMateria("ice");
    bobby.equip(tmp);
    Character cpy(bobby);
    bobby.unequip(0);
    cpy.use(0, bobby);
    cpy.use(1, bobby);
    cpy.use(2, bobby);
    cpy.use(3, bobby);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Destructors calling" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}
