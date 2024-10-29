#include "Cat.Class.hpp"

Cat::Cat() 
{
	this->type = "Cat";
	std::cout << "Hello you ! A constructor for [ Cat ] class was called ..." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[ " << this->getType() << " ] " << "Miaou Miaou i'm a cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Oh crap ! A destructor for [ Cat ] class was called ..." << std::endl;
}