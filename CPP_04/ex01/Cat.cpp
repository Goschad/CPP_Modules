#include "Cat.Class.hpp"
#include "Brain.Class.hpp"

Cat::Cat() 
{
	this->type = "Cat";
	this->CatBrain = new Brain();
	std::cout << "constructor [ Cat ] class with Brain was called ..." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[ " << this->getType() << " ] " << "Miaou Miaou i'm a cat with a brain" << std::endl;
}

Cat::~Cat()
{
	std::cout << "destructor for [ Cat ] class and his brain was called ..." << std::endl;
	std::cout << "deleted ..." << std::endl;
	delete [] (this->CatBrain);

}