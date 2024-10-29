#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <new>

class HumanB 
{
    private :
        std::string name;
        Weapon *weapon;

    public :
        HumanB(std::string name);
        void attack( void );
        void setWeapon(Weapon &weapon);
        ~HumanB();

};

#endif