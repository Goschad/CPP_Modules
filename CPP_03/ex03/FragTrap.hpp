#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
		FragTrap(std::string name = "default");
        void highFivesGuys(void);
		~FragTrap();
};

#endif