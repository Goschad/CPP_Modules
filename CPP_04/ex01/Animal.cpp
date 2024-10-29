#include "Animal.Class.hpp"

Animal::Animal() 
{
	this->type = "Animal";
	std::cout << "constructor [ Animal ] called ..." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "/* Animal noises */" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << "destructor [ Animal ] called ..." << std::endl;
}