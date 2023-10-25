#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <iostream>

class Span
{
	private:
		unsigned int    _n;
		std::list<int>  _spanList;

	public:
		Span( void );
		Span( unsigned int n );
    	Span( Span const & src );
    	~Span( void );

		// operator
		Span & operator=(Span const & rhs);

		// function
		void addNumber(int n);
		void addNumbers(std::list<int> list);
		unsigned int longestSpan(void);
		unsigned int shortestSpan(void);

		// getters
		unsigned int getN(void) const;
		const std::list< int >* getList( void ) const ;

		// exception
		class SpanExceptionMin : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class SpanExceptionMax : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif