#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

// include

#include "ClapTrap.hpp"

// Child class

class ScavTrap : public ClapTrap
{
	private:
		int kepperMode = 0;
		
    public:
		ScavTrap(std::string name = "default");
        void guardGate();
		~ScavTrap();
};

#endif