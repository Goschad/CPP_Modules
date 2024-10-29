#include "Animal.Class.hpp"
#include "Dog.Class.hpp"
#include "Cat.Class.hpp"

#include "WrongAnimal.Class.hpp"
#include "WrongCat.Class.hpp"

int main()
{
	// test with Animal Class //

	std::cout << "------------------ A N I M A L --------------------"<< std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "--------------------------------------"<< std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "--------------------------------------"<< std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete [] j;
	delete i;

	std::cout << "------------------ W R O N G - A N I M A L --------------------\n" << std::endl;

	// test with WrongAnimal Class //

	const WrongAnimal* metaton = new WrongAnimal();
	const WrongAnimal* z = new WrongCat();

	std::cout << "--------------------------------------"<< std::endl;

	std::cout << metaton->getType() << " " << std::endl;
	std::cout << z->getType() << " " << std::endl;

	std::cout << "--------------------------------------"<< std::endl;

	metaton->makeSound();
	z->makeSound();

	std::cout << "--------------------------------------"<< std::endl;

	delete metaton;
	delete z;

	return (0);
}