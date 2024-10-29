#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie 
{
    private :
        std::string name;

    public :
        Zombie(void);
        ~Zombie(void);
        void    announce( void );
        void    GiveName(std::string name);

};

Zombie* zombieHorde( int N, std::string name );

#endif