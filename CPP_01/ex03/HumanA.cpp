#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
    this->name = name;
    this->weapon = weapon;
    std::cout<<"HumanA "<< this->name <<" was created ..."<<std::endl;
}

void HumanA::attack( void )
{
    std::cout<< this->name <<" attacks with their " << this->weapon.getType() <<std::endl;
}

HumanA::~HumanA()
{
    std::cout<<"HumanA "<< this->name <<" was destroyed ..."<<std::endl;
}