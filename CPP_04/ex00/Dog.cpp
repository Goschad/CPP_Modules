#include "Dog.Class.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Hey ! Constructor for [ Dog ] class was called ..." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[ " << this->getType() << " ]" << "Ouaf Ouaf" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Oh no ! Destructor for [ Dog ] class was called ..." << std::endl;
}