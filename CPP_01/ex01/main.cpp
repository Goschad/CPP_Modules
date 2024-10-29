#include "Zombie.hpp"

int main()
{
    Zombie *zombie;
    int    N;

    N = 5;
    zombie = zombieHorde(N, "Bob");
    for (int i = 0; i < N; i++)
        zombie[i].announce();
    delete [] zombie;
}