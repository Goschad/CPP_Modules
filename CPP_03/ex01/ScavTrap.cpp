#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout<<"[ScavTrap] constructor called for "<< name << " ..."<<std::endl;
}

void ScavTrap::guardGate()
{
	if (this->EnergyPoints <= 0)
		std::cout << "[ScavTrap] " << this->name <<" not having enough EnergyPoints ..." <<std::endl;
	else if (this->HitPoints <= 0)
		std::cout<< "[ScavTrap] " << this->name << " is already dead ..." <<std::endl;
	else if (this->kepperMode == 0)
	{
		this->kepperMode = 1;
		this->EnergyPoints -= 1;
		std::cout << "[ScavTrap] " << this->name <<" go into Gate kepper mode ..." << std::endl;
	}
	else if (this->kepperMode == 1)
	{
		this->kepperMode = 0;
		this->EnergyPoints -= 1;
		std::cout << "[ScavTrap] " << this->name <<" return into base mode ..." << std::endl;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout<<"[ScavTrap] destructor called for "<< this->name << " ..."<<std::endl;
}