#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// test main //

int main(void)
{
	// creation //
	ClapTrap Clap("First");
	// Heritage //
	ScavTrap Scav("Second");

	std::cout << std::endl;

	Clap.getStat();

	std::cout << std::endl;

	Scav.getStat();

	std::cout << std::endl;

	return (0);
}