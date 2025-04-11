#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	// Create a MateriaSource and learn Ice and Cure materia
	IMateriaSource *src = new MateriaSource();
	AMateria *allo;
	AMateria *allo2;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create a character named "Alice"
	ICharacter *alice = new Character("Alice");

	// Create and equip Ice materia to Alice
	AMateria *tmp;
	tmp = src->createMateria("ice");
	allo = tmp;
	alice->equip(tmp);

	// Create and equip Cure materia to Alice
	tmp = src->createMateria("cure");
	alice->equip(tmp);
	allo2 = tmp;

	// Create another character named "Bob"
	ICharacter *bob = new Character("Bob");

	// Alice uses her equipped materia on Bob
	alice->use(0, *bob); // Uses Ice on Bob
	alice->use(1, *bob); // Uses Cure on Bob

	
	alice->unequip(0);
	alice->unequip(1);

	// Clean up
	delete bob;
	delete alice;
	delete src;
	delete allo;
	delete allo2;
	return 0;
}

