#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// test main //

int main(void)
{
	// creation //
	ClapTrap Clap("First");
	// Heritage //
	FragTrap Frag("Second");

	std::cout << std::endl;

	Clap.getStat();

	std::cout << std::endl;

	Frag.getStat();

	std::cout << std::endl;

	return (0);
}