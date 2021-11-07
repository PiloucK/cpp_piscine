/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:08 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/04 16:35:48 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	CLEAR_STDOUT
	START_INFO
	WAIT_INPUT

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	{
		AMateria* tmp;
		tmp = src->createMateria("ice");

		// EXEMPLE D'APPEL POUR UN TEST UNIQUEMENT ACCESSIBLE EN DEBUG
		ASSERT(tmp->getType() == "ice");

		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
	}

	ICharacter* bob = new Character("bob");

	std::cout << "Use the two learnd spells\n";

	me->use(0, *bob);
	me->use(1, *bob);

	NEXT_TEST
	{
		std::cout << "test: -Try to learn more than possible\n";
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->equip(tmp);
		me->equip(tmp);
	}

	NEXT_TEST
	{
		std::cout << "test: -Try to use out of inventory\n";
		me->use(-1, *bob);
		me->use(4, *bob);

		std::cout << "\ntest: -Use all spells\n";
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
	}

	NEXT_TEST
	{
		std::cout << "test: -Delete one and then add when inventory was full\n";
		me->unequip(2);
		me->equip(src->createMateria("cure"));
		
		std::cout << "\ntest: -Use all spells\n";
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
	}

	NEXT_TEST
	{
		std::cout << "test: -Delete same index twice\n";
		me->unequip(2);
		me->unequip(2);

		std::cout << "\ntest: -Use all spells\n";
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
	}

	NEXT_TEST
	{
		std::cout << "test: -Create a new character, change it and then create by copy and create/use=\n";
		Character toto("toto");

		toto.equip(src->createMateria("cure"));
		toto.equip(src->createMateria("cure"));
		toto.equip(src->createMateria("ice"));
		toto.equip(src->createMateria("cure"));

		toto.unequip(3);
		
		std::cout << "\ntest: -Use all spells\n";
		toto.use(0, *bob);
		toto.use(1, *bob);
		toto.use(2, *bob);
		toto.use(3, *bob);

		Character tata(toto);

		std::cout << "\ntest: -Use all spells\n";
		tata.use(0, *bob);
		tata.use(1, *bob);
		tata.use(2, *bob);
		tata.use(3, *bob);

		Character caren("caren");

		std::cout << "\ntest: -Use all spells before copy\n";
		caren.use(0, *bob);
		caren.use(1, *bob);
		caren.use(2, *bob);
		caren.use(3, *bob);
		std::cout << "\ntest: -Use all spells after copy\n";
		caren = tata;
		caren.use(0, *bob);
		caren.use(1, *bob);
		caren.use(2, *bob);
		caren.use(3, *bob);
	}

	NEXT_TEST
	{
		MateriaSource book;

		book.learnMateria(src->createMateria("cure"));
		book.learnMateria(src->createMateria("cure"));
		book.learnMateria(src->createMateria("cure"));
		book.learnMateria(src->createMateria("cure"));

		{
			std::cout << "test: -Try to learn more than possible\n";
			book.learnMateria(src->createMateria("ice"));
		}

		{
			std::cout << "test: -Try to create unknown materia\n";
			book.createMateria("ice");
		}
	}

	delete bob;
	delete me;
	delete src;

	return 0;
}
