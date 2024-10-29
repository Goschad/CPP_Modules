#include "WrongCat.Class.hpp"

WrongCat::WrongCat() 
{
	this->type = "WrongCat";
	std::cout << "Hello you ! A constructor for [ WrongCat ] class was called ..." << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << "[ " << this->getType() << " ] " << "Miaou Miaou i'm a WrongCat and usless" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Oh crap ! A destructor for [ WrongCat ] class was called ..." << std::endl;
}