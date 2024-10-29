#include "Animal.Class.hpp"
#include "Dog.Class.hpp"
#include "Cat.Class.hpp"

#include "WrongAnimal.Class.hpp"
#include "WrongCat.Class.hpp"

int main()
{
	std::cout << "tab of 50 Dog :" << std::endl;

	const Animal* j = new Dog[2];

	std::cout  << std::endl;

	delete [] j;

	std::cout  << std::endl;

	std::cout << "tab of 50 Cat :" << std::endl;

	std::cout  << std::endl;

	const Animal* i = new Cat[2];

	std::cout  << std::endl;

	delete [] i;

	return 0;
}