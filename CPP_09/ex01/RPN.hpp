#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;
	
	public:
		RPN( void );

		void PolishCalcul( char c );
		int PolishMath(char **t,  int i );
		int init_all(int argc, char **argv);

		// useless
		void printStack( void );
	
		std::stack<int> getStack(void) const;

		~RPN();
};

#endif