#ifndef FIXER_HPP
#define FIXER_HPP

#include <iostream>
#include <cmath>


class Fixed
{
    private :
		int FixedNumber;
        const static int FixedByte = 8;

    public :
        Fixed( void ) ; // constructor
        Fixed( int FixedNumber ) ; // constructor
        Fixed( float FixedNumber ) ; // constructor

        Fixed( Fixed const & src ) ; // copy

        ~Fixed( void ) ;  // destructor

        int toInt( void ) const; // member function
		int getRawBits( void ) const ; // member function
		void setRawBits( int const raw ) ; // member function
        float toFloat( void ) const ; // member function

        Fixed & operator=( Fixed const & rhs ) ; // operator
};

// other //

std::ostream & operator<<( std::ostream & ostream , Fixed const & rhs) ;

#endif 