#include "Weapon.hpp"

Weapon::Weapon(const std::string NewType)
{
    this->type = NewType;
    std::cout<<"Weapon "<< this->type <<" was created ..."<<std::endl;
}

void Weapon::setType(const std::string NewType)
{
     this->type = NewType;
}

std::string& Weapon::getType( void )
{
    std::string& RefType = this->type;
    return (RefType);
}

Weapon::~Weapon()
{
    std::cout<<"Weapon "<< this->type <<" was destroyed ..."<<std::endl;
}