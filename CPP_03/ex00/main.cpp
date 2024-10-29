#include "ClapTrap.hpp"

// test main //

int main(void)
{
	// creation //
	ClapTrap Clap("Clap");
	ClapTrap Ennemy("Ennemy");

	std::cout<<std::endl;

	// beRepaired //
	Clap.beRepaired(5);
	Clap.getStat();

	std::cout<<std::endl;

	// takeDamage //
	Clap.takeDamage(10);
	Clap.getStat();

	std::cout<<std::endl;

	// Attack //
	Ennemy.attack("some other ClapTrap ...");
	Ennemy.getStat();

	std::cout<<std::endl;

	// Dead //
	Clap.takeDamage(10);
	Clap.attack("some other ClapTrap ...");
	Clap.getStat();

	std::cout<<std::endl;

	// enought energy points //
	for (int i = 0; i < 10; i++)
		Clap.beRepaired(1);
	Clap.getStat();

	std::cout<<std::endl;
	return (0);
}