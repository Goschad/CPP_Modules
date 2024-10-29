#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <new>

class Weapon
{
    private :
        std::string type;

    public :
        Weapon(std::string type);
        void setType(const std::string NewType);
        std::string& getType( void );
        ~Weapon();

};

#endif