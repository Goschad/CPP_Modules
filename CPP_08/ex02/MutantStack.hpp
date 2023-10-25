#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <vector>
#include <deque>

template< typename T, class Container = std::deque< T > >

class MutantStack : public std::stack< T, Container >
{
	public:
		// constructor 
		MutantStack( void )
		{

		}

		MutantStack( MutantStack & src ) 
		{ 
			*this = src; 
		}
	
		// operator
		MutantStack & operator=( const MutantStack & rhs ) 
		{
    	    std::stack< T, Container >::operator=( rhs );
    	    return *this;
    	}

		// function iterator
	
		typedef typename Container::iterator    iterator;
	
    	iterator begin()
		{
			return (this->c.begin());
		}

    	iterator end() 
		{ 
			return (this->c.end());
		}
	
		// destructor
		~MutantStack( void ) {};
};

#endif