#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <new>

class ClapTrap
{
    protected :
		std::string name;
		int HitPoints;
		int EnergyPoints;
		int AttackDamage;

    public :
		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();

		// for test //
		void getStat(void);
};

#endif