/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:23:52 by mbouaza           #+#    #+#             */
/*   Updated: 2023/09/18 13:33:49 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate( void )
{
	Base *newBase = NULL;

	srand((unsigned int)time(NULL));
	int random = rand() % 3;
	std::cout << "Type : " << random << std::endl;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else if (random == 2)
		return (new C());
	return (newBase);
}

void identify(Base * p)
{
	A * a;
	if ((a = dynamic_cast<A *>(p)))
		std::cout << "Type A" << std::endl;
	B * b;
	if ((b = dynamic_cast<B *>(p)))
		std::cout << "Type B" << std::endl;
	C * c;
	if ((c = dynamic_cast<C *>(p)))
		std::cout << "Type C" << std::endl;
}

void identify(Base & p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		std::cout << "Type A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		;
	}

	try
	{
		B & b = dynamic_cast<B &>(p);
		std::cout << "Type B" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		;
	}

	try
	{
		C & c = dynamic_cast<C &>(p);
		std::cout << "Type C" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		;
	}
}

int main( void )
{
	Base *ptr = generate();

	identify(ptr);

	Base *ref = generate();
	
	identify(*ref);

	delete ptr;
	delete ref;
}