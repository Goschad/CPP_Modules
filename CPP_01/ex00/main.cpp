#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;

    zombie = newZombie("Foo");
    zombie->announce();

    randomChump("Bob");
    delete zombie;
}