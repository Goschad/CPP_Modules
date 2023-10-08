#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename S>

void swap( S &a, S &b )
{
	S tmp = a;
	a = b;
	b = tmp;
}

template<typename X>

X max( X a, X b )
{
	if (a > b)
		return (a);
	else
		return (b);
}

template<typename N>

N min( N a, N b )
{
	if (a < b)
		return (a);
	else
		return (b);
}

#endif