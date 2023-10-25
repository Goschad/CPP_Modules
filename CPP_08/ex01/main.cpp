#include "Span.hpp"

int main()
{ 
	Span span(1000);

	srand((unsigned int)time(NULL));

	std::list<int> t;
	for (int i = 0; i < 1000; i++)
		t.push_back(std::rand() % 10000);

	span.addNumbers(t);

	t.clear();

	std::cout << "--- [ span with mutiples numbers ] --- " << std::endl;

	std::cout << "longest = " << span.longestSpan() << std::endl;
	std::cout << "shortest = " <<  span.shortestSpan() << std::endl;

	// manual //

	std::cout << "--- [ span with manual methode ] --- " << std::endl;

	Span S_span(5);

	S_span.addNumber(100);
	S_span.addNumber(99);
	S_span.addNumber(1000);
	S_span.addNumber(1);
	S_span.addNumber(40);

	std::cout << "longest = " << S_span.longestSpan() << std::endl;
	std::cout << "shortest = " <<  S_span.shortestSpan() << std::endl;

	std::cout << std::endl;

	// invalide size //

	S_span.addNumber(1000000000);
	S_span.addNumber(10000);
	
	return 0;
}