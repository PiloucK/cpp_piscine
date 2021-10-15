#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
	std::cout << '\n';

    const WrongAnimal *k = new WrongCat();
	std::cout << *k;
    k->makeSound();
	std::cout << '\n';

	Animal* toto = new Dog();
	std::cout << *toto;
	toto->makeSound();
	*toto = *i;
	std::cout << *toto;
	toto->makeSound();
	delete toto;

	std::cout << '\n';
    delete meta;
    delete j;
    delete i;
    delete k;
}
