#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ClapTrap, public FragTrap, public ScavTrap
{
        private:
             std::string name;

        public:
             DiamondTrap(std::string name = "default");
             void whoAmI();
             ~DiamondTrap();

             using ScavTrap::attack;
};

#endif