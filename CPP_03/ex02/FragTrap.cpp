#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout<<"[FragTrap] constructor called for "<< name << " ..."<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->EnergyPoints <= 0)
		std::cout << "[FragTrap] " << this->name <<" not having enough EnergyPoints ..." <<std::endl;
	else if (this->HitPoints <= 0)
		std::cout<< "[FragTrap] " << this->name << " is already dead ..." <<std::endl;
	else
	{
		this->EnergyPoints -= 1;
		std::cout<<"[FragTrap] " << this->name << " : A high five ?"<<std::endl;
	}
}

FragTrap::~FragTrap()
{
	std::cout<<"[FragTrap] destructor called for "<< this->name << " ..."<<std::endl;
}