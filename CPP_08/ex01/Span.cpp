#include "Span.hpp"

// ---[ Constructor ]---

Span::Span( void ) : _n( 0 ) 
{
	std::cout << "Default Span constructor was called. N = 0" << std::endl;
}

Span::Span( unsigned int n ) : _n( n ) 
{
	std::cout << "Span constructor was called." << std::endl;
}

Span::Span( Span const & src ) 
{
    *this = src;
}

// ---[ Operator ]---

Span & Span::operator=(Span const & rhs) 
{
	if ( this != &rhs )
	{
		_n = rhs.getN();
		_spanList = rhs._spanList;
	}
	
	return (*this);
}

// ---[ Functions ]---

void Span::addNumber(int n)
{
	try
	{
		if (_spanList.size() >= _n)
			throw(SpanExceptionMax());
		_spanList.push_back(n);
	}
	catch (const SpanExceptionMax &e)
	{
		std::cout << "can't add a number, exceeded the value of N" << std::endl;
	}
}

unsigned int Span::shortestSpan(void)
{
	bool t = false;
	unsigned int n = 0;
	int i = 0;
	int span = 0;
	int shortest = 0;
	std::list<int>::iterator it;

	try
	{
		if (_spanList.size() == 0)
			throw (SpanExceptionMin());

		while (n < _n)
		{
			for (it = _spanList.begin(); it != _spanList.end(); ++it)
			{
				if (t == false)
				{
					span = *it;
					t = true;
				}

				if (span > *it && (span - *it < shortest || i == 0))
				{
					shortest = span - *it;
					i++;
				}
				else if (i != 0 && span == *it)
				{
					shortest = 0;
					i++;
				}
			}
			i = 0;
			span = 0;
			t = false;
			n++;
		}
	}
	catch (const SpanExceptionMin &e)
	{
		std::cout << "no value in Span list" << std::endl;
	}

	return (shortest);
}

unsigned int Span::longestSpan(void)
{
	int i = 0;
	int shortest = 0;
	int hightest = 0;
	int longtest = 0;
	std::list<int>::iterator it;

	try
	{
		if (_spanList.size() == 0)
			throw (SpanExceptionMin());

		for (it = _spanList.begin(); it != _spanList.end(); ++it)
		{
			if (i == 0 || shortest > (*it))
				shortest = (*it);
			if (i == 0 || hightest < (*it))
				hightest = (*it);
			i++;
		}
		longtest = hightest - shortest;
	}
	catch (const SpanExceptionMin &e)
	{
		std::cout << "no value in Span list" << std::endl;
	}
	return (longtest);
}

// ---[ Getters ]---

unsigned int Span::getN(void) const
{
	return (_n);
}

const std::list< int >* Span::getList( void ) const 
{
    return (&_spanList);
}

// ---[ Exceptions ]---

const char* Span::SpanExceptionMax::what() const throw()
{
	return ("can't add a number, exceeded the value of N");
};

const char* Span::SpanExceptionMin::what() const throw()
{
	return ("no value in Span list");
};

// ---[ Destructor ]---

Span::~Span( void )
{
	std::cout << "Span destructor was called." << std::endl;
}