#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout<<"🧟 "<<"Zombie "<< this->name << " was created..."<<std::endl;
}

void Zombie::announce( void )
{
    std::cout<<"🧟 "<< this->name <<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<"🧟 "<<"Zombie "<< this->name << " was destroyed..."<<std::endl;
}