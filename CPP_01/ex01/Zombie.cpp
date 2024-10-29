#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout<<"🧟 Zombie "<< "'empty'" << " was created..."<<std::endl;
}

void Zombie::announce( void )
{
    std::cout<< "🧟 " << this->name <<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::GiveName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout<<"🧟 Zombie "<< this->name << " was destroyed..."<<std::endl;
}