#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	std::cout << '\n';
	const Animal* j = new Dog();
	std::cout << '\n';
	const Animal* i = new Cat();
	std::cout << '\n';

	std::cin.get();
	std::cout << "\033[2J";
	std::cout << j->getType() << " " << std::endl;
	std::cout << '\n';
	std::cout << i->getType() << " " << std::endl;
	std::cout << '\n';
	i->makeSound(); //will output the cat sound!
	std::cout << '\n';
	j->makeSound();
	std::cout << '\n';
	meta->makeSound();

	std::cin.get();
	std::cout << "\033[2J";
	const WrongAnimal *k = new WrongCat();
	std::cout << '\n';
	std::cout << *k;
	std::cout << '\n';
	k->makeSound();

	{
		std::cin.get();
		std::cout << "\033[2J";
		Animal* toto = new Dog();
		std::cout << '\n';
		std::cout << *toto;
		std::cout << '\n';
		toto->makeSound();
		std::cout << '\n';
		delete toto;
		std::cout << '\n';
		Dog model_for_newDog;
		Dog* newDog = new Dog(model_for_newDog);
		{
			Dog tata;
			std::cout << '\n';
			*newDog = tata;
			std::cout << '\n';
			std::cout << newDog->think() << '\n';
			std::cout << tata.think() << '\n';
			delete newDog;
			std::cout << '\n';
		}
	}
	
	{
		std::cin.get();
		std::cout << "\033[2J";
		Animal* toto = new Cat();
		std::cout << '\n';
		std::cout << *toto;
		std::cout << '\n';
		toto->makeSound();
		std::cout << '\n';
		delete toto;
		std::cout << '\n';
		Cat* newCat = new Cat();
		{
			Cat tata;
			std::cout << '\n';
			*newCat = tata;
			std::cout << '\n';
			std::cout << newCat->think() << '\n';
			std::cout << tata.think() << '\n';
			delete newCat;
			std::cout << '\n';
		}
	}

	{
		std::cin.get();
		std::cout << "\033[2J";
		delete meta;
		std::cout << '\n';
		delete j;
		std::cout << '\n';
		delete i;
		std::cout << '\n';
		delete k;
	}

	{
		std::cin.get();
		std::cout << "\033[2J";
		Animal * animalArray[10];
		for (size_t i = 0; i < 10; i++) {
			
			if (i % 2 == 0) {
				animalArray[i] = new Cat();
			} else {
				animalArray[i] = new Dog();
			}
		}

		std::cin.get();
		std::cout << "\033[2J";
		for (size_t i = 0; i < 10; i++) {
			delete animalArray[i];
		}
	}	
}
