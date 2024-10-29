#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    FragTrap::HitPoints = 100;
    ScavTrap::EnergyPoints = 50;
	FragTrap::AttackDamage = 30;
    std::cout << "[DiamondTrap] constructor called for "<< name << " ..."<<std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am [DiamondTrap], my name is "<< this->name << " ..."<<std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[DiamondTrap] destructor called for "<< this->name << " ..."<<std::endl;
}