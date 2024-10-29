#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <new>

class ClapTrap
{
    private :
		std::string name;
		int HitPoints;
		int EnergyPoints;
		int AttackDamage;

    public :
		ClapTrap(std::string name = "default");
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();

		// for test //
		void getStat(void);
};

#endif