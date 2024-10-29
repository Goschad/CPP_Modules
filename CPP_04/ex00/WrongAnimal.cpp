#include "WrongAnimal.Class.hpp"

WrongAnimal::WrongAnimal() 
{
	this->type = "WrongAnimal";
	std::cout << "constructor [ WrongAnimal ] called ..." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "/* WrongAnimal noises */" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "destructor [ WrongAnimal ] called ..." << std::endl;
}