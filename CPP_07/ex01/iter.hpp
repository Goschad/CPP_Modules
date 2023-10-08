#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template< typename F, typename S>

void iter(F *tableau, unsigned int size, void (*function)(S &))
{
	if (tableau == NULL || function == NULL)
		return ;
	for (unsigned int len = 0; len < size; len++)
		function(tableau[len]);
}

#endif