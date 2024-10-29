#include "Dog.Class.hpp"
#include "Brain.Class.hpp"

Dog::Dog()
{
	this->DogBrain = new Brain();
	this->type = "Dog";
	std::cout << "constructor [ Dog ] class with brain was called ..." << std::endl;

}

void Dog::makeSound() const
{
	std::cout << "[ " << this->getType() << " ] " << "Ouaf Ouaf i'm a dog with brain" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor for [ Dog ] class and his brain was called ..." << std::endl;
	delete [] (this->DogBrain);
	std::cout << "deleted ..." << std::endl;
}