#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name): name(name), weapon(weapon)
{
    this->name = name;
    std::cout<<"HumanB "<< this->name <<" was created ..."<<std::endl;
}

void HumanB::attack( void )
{
    std::cout<< this->name <<" attacks with their "<< this->weapon->getType() <<std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::~HumanB()
{
    std::cout<<"HumanB "<< this->name <<" was destroyed ..."<<std::endl;
}