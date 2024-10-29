#include "WrongCat.Class.hpp"

WrongCat::WrongCat() 
{
	this->type = "WrongCat";
	this->WrongCatBrain = new Brain();
	std::cout << "constructor for [ WrongCat ] class with a brain was called ..." << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << "[ " << this->getType() << " ] " << "Miaou Miaou i'm a WrongCat with a brain and usless" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "destructor for [ WrongCat ] class with a brain was called ..." << std::endl;
	delete [] (this->WrongCatBrain);
}