#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

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