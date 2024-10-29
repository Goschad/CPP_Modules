#include "Fixed.hpp"

// constructor //

Fixed::Fixed() : FixedNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int FixedNumber )
{
	this->FixedNumber = FixedNumber << this->FixedByte;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float FixedNumber )
{
	this->FixedNumber = (int)roundf(FixedNumber * ( 1 << this->FixedByte ));
	std::cout << "Float constructor called" << std::endl;
}

// copy //

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

// operator //

Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->FixedNumber = rhs.getRawBits();
	return (*this);
}

std::ostream & operator<<( std::ostream & ostream , Fixed const & rhs)
{
	ostream << rhs.toFloat();
	
	return (ostream);
}

// get function //

int Fixed::getRawBits( void ) const 
{
	return (this->FixedNumber);
}

// set function //

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->FixedNumber = raw;
}

// conversion function //

int Fixed::toInt( void ) const
{	
	return ( this->getRawBits() >> this->FixedByte );
}

float Fixed::toFloat( void ) const
{
	return ( (float)this->getRawBits() / (1 << this->FixedByte) );
}

// destructor //

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}