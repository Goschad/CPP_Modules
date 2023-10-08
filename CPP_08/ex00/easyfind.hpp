#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// include

#include <iostream>
#include <exception>
#include <list>
#include <vector>
#include <string>

// exception

class NoOccurrenceExecption : public std::exception
{
	public:
		virtual const char* what() const throw();

};

const char* NoOccurrenceExecption::what() const throw()
{
	return ("no occurrence is found");
};

// template

template< typename T >

// function with template

void EasyFind( T& container, int n)
{	
	try
	{
		if (std::find(container.begin(), container.end(), n) == container.end())
			throw (NoOccurrenceExecption());
		else
			std::cout << "an occurrence for " << n << "." << std::endl;
	}
	catch(const NoOccurrenceExecption &e)
	{
		std::cerr << "no occurrence for "  << n << "." << std::endl;
	}
}

#endif