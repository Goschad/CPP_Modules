#ifndef FIXER_HPP
#define FIXER_HPP

#include <iostream>

class Fixed
{
    private :
		int FixedNumber;
        const static int FixedByte = 8;

    public :
        Fixed( void );
        Fixed( Fixed const & src );
        Fixed & operator=( Fixed const & rhs );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
        ~Fixed(void);
};

#endif 