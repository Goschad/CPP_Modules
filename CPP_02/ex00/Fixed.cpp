#include "Fixed.hpp"

Fixed::Fixed() : FixedNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->FixedNumber = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedNumber);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->FixedNumber = raw;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}