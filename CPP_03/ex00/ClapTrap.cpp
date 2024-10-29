#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): HitPoints(10), EnergyPoints(10) ,AttackDamage(0)
{
	this->name = name;
	std::cout<<"ClapTrap constructor called for "<< name << " ..."<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->HitPoints <= 0)
		std::cout<< "Welp ... ClapTrap " << this->name << " is already dead ..." <<std::endl;
	else if (this->EnergyPoints <= 0)
		std::cout<< "Welp ... ClapTrap " << this->name << " not having enough EnergyPoints ..." <<std::endl;
	else
	{
		std::cout<< "[ClapTrap] " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" <<std::endl;
		this->EnergyPoints -= 1;
	}
	if (this->HitPoints <= 0)
		this->HitPoints = 0;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints <= 0)
	{
		std::cout<< "[ClapTrap] " << this->name << " is already dead, stop harassing him ..." <<std::endl;
		this->HitPoints = 0;
	}
	else
	{
		std::cout<< "[ClapTrap] " << this->name << " take " << amount << " damage ..." <<std::endl;
		this->HitPoints -= amount;
		if (this->HitPoints <= 0)
			std::cout<< "[ClapTrap] " << this->name << " is dead ..." <<std::endl;
	}
	if (this->HitPoints <= 0)
		this->HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= 0)
		std::cout<< "Welp ... [ClapTrap] " << this->name << " not having enough EnergyPoints ..." <<std::endl;
	if (this->HitPoints <= 0)
	{
		std::cout<< "[ClapTrap] " << this->name << " is already dead ..." <<std::endl;
	}
	else
	{
		std::cout<< "[ClapTrap] " << this->name << " was repaired by " << amount << " HitPoints" <<std::endl;
		this->HitPoints += amount;
		this->EnergyPoints -= 1;
	}
	if (this->HitPoints <= 0)
		this->HitPoints = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"[ClapTrap] destructor called for "<< this->name << " ..."<<std::endl;
}

void ClapTrap::getStat(void)
{
	std::cout<< "name = " << this->name << std::endl;
	std::cout<< "HitPoints = " << this->HitPoints << std::endl;
	std::cout<< "EnergyPoints = " << this->EnergyPoints << std::endl;
	std::cout<< "AttackDamage = " << this->AttackDamage << std::endl;
}